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
//#include <mutex>
#include <boost/multiprecision/cpp_int.hpp>

using namespace boost::multiprecision;

//const int DATA_FREQ = 60; //should be whenever it comes in
//const int PWM_FREQ = 60; //maybe limit, otherwise as fast as possible
static const int DATA_PIN = 0;
static const int LATCH_PIN = 2;
static const int CLOCK_PIN = 1;
//const int BUF_SIZE = 64; //should only really have 1 intensity map at a time.
static const int NUM_MOTORS = 96;
static const int NUM_INTENSITIES = 10; // the levels of intensities, also # of frames to complete a map.

//mutex mtx;
/*
typedef struct thread_data
{
	int **intensities;
	int *counter;
	int *cur_index;
} thread_data_t;
*/
//MSB FIRST ALWAYS
void shiftOut(void * value, int size)
{
	digitalWrite(LATCH_PIN, 0);
	
	for (int i=size-1; i>=0; i--)
	{
		digitalWrite(DATA_PIN, (int128_t)*value & (1<<i));
		
		digitalWrite(CLOCK_PIN, HIGH); delayMicroseconds(1);
		digitalWrite(CLOCK_PIN, LOW); delayMicroseconds(1);
	}
	
	digitalWrite(LATCH_PIN, 1);
}

int main(int argc, char **argv)
{
	//int counter = 0, cur_index = 0;
	
	wiringPiSetup();
	
	pinMode(DATA_PIN, OUTPUT);
	pinMode(LATCH_PIN, OUTPUT);
	pinMode(CLOCK_PIN, OUTPUT);
	
	digitalWrite(DATA_PIN, LOW);
	digitalWrite(CLOCK_PIN, LOW);
	digitalWrite(LATCH_PIN, HIGH);

	int map[NUM_MOTORS];
	int128_t frames[NUM_INTENSITIES]; //each int128 is a "frame" of ~96~ bits
	bool new_msg_received = false;

	//infinite loop to check for new intensity maps from camera
	for (;;)
	{
		//check for intensity map somehow
		if (new_msg_received) 
		{
			new_msg_received = false;
			//flush current frames
			memset(frames,0,sizeof(frames));

			//for now, just use this temp bullshit thing to create map
			for (int i=0; i<NUM_MOTORS; i++)
			{
				map[i] = i%NUM_INTENSITIES;
			}		

			//populate the frames arr to loop through later
			for (int i=NUM_MOTORS; i>0; i--)
			{
				for (int j=0; j<map[i]; j)
				{
					frames[j] | 1<<i;
				}
			}
		}

		// go through map (at least once) to get a full "cycle" of the PWM
		for (int i=0; i< NUM_INTENSITIES; i++) 
		{
			shiftOut(frames[i], 128);
		}


	}

	/*
	int values[BUF_SIZE];
	int intensities[BUF_SIZE][NUM_MOTORS];

	pthread_t *motor_control_thread, *listener_thread;
	thread_data_t thread_data;
	thread_data.values = values;
	thread_data.intensities = intensities;
	thread_data.counter = &counter;
	thread_data.cur_index = &cur_index;

	pthread_create(motor_control_thread, NULL, motorControl, &thread_data)
	
	for (;;)
	{
		for (int i = 0; i < 96; i++)
		{
			mtx.lock()
			intensities[counter][i] = rand() % NUM_INTENSITIES;
			(counter++) % BUF_SIZE;
			mtx.unlock();
			delay(20);
		}
	}
	*/
}
