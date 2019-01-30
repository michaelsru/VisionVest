/*
 * shift_register_daisy_chain_cpp.cpp
 * 
 * Copyright 2019  <pi@raspberrypi>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */

#include <stdio.h>
#include <wiringPi.h>
#include <wiringShift.h>
#include <sr595.h>
#include <pthread.h>
#include <iostream>
#include <mutex>

const int DATA_FREQ = 60;
const int PWM_FREQ = 60;
const int DATA_PIN = 0;
const int LATCH_PIN = 2;
const int CLOCK_PIN = 1;
const int BUF_SIZE = 64;

mutex mtx;

typedef struct thread_data
{
	int *values;
	int *intensities;
	int *counter;
	int *cur_index;
} thread_data_t;

//MSB FIRST ALWAYS
void shiftOut(int DATA_PIN, int CLOCK_PIN, int LATCH_PIN, int value, int size)
{
	digitalWrite(LATCH_PIN, 0);
	
	for (int i=size-1; i>=0; i--)
	{
		digitalWrite(DATA_PIN, value & (1<<i));
		
		digitalWrite(CLOCK_PIN, HIGH); delayMicroseconds(1);
		digitalWrite(CLOCK_PIN, LOW); delayMicroseconds(1);
	}
	
	digitalWrite(LATCH_PIN, 1);
}

void motorControl()
{
	int value, intensity;
	bool, values_left;
	do{
		values_left = false;
		mtx.lock();
		if (counter != cur_index)
		{
			values_left = true;
			value = values[cur_index];
			intensity = intensities[cur_index];
		}
		mtx.unlock();
		if (values_left)
		{
			for (int i = 0; i < 60; i++)
			{
				shiftOut(DATA_PIN, CLOCK_PIN, LATCH_PIN, value, size);
				delay(500);
				printf("%d\n", value);

				delay(1/PWM_FREQ - (100-intensity) * 1/PWM_FREQ);

				shiftOut(DATA_PIN, CLOCK_PIN, LATCH_PIN, 0, 16);
				delay(500);
				printf("%d\n", 0);
				
				delay(1/PWM_FREQ - (intensity) * 1/PWM_FREQ);
			}
			(cur_index++) % BUF_SIZE;
		}
	} while (true)
}

int main(int argc, char **argv)
{
	int counter = 0, cur_index = 0;
	
	wiringPiSetup();
	
	pinMode(DATA_PIN, OUTPUT);
	pinMode(LATCH_PIN, OUTPUT);
	pinMode(CLOCK_PIN, OUTPUT);
	
	digitalWrite(DATA_PIN, LOW);
	digitalWrite(CLOCK_PIN, LOW);
	digitalWrite(LATCH_PIN, HIGH);

	int values[BUF_SIZE];
	int intensities[BUF_SIZE];

	pthread_t *motor_control_thread, *listener_thread;
	thread_data_t thread_data;
	thread_data.values = values;
	thread_data.intensities = intensities;
	thread_data.counter = &counter;
	thread_data.cur_index = &cur_index;

	pthread_create(motor_control_thread, NULL, motorControl, &thread_data)
	
	for (;;)
	{
		for (int value = 0; value < 2^16; value++)
		{
			mtx.lock()
			values[counter] = value;
			intensities[counter] = rand() % 100 + 1;
			(counter++) % BUF_SIZE;
			mtx.unlock();
			delay(20);
		}
	}
}
