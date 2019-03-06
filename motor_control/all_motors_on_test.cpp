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
#include <string.h>
#include <stdint.h>


static const int DATA_PIN = 0;
static const int LATCH_PIN = 2;
static const int CLOCK_PIN = 1;

//MSB FIRST ALWAYS
void shiftOutTest(unsigned long long int value, int size)
{
	digitalWrite(LATCH_PIN, 0);
	unsigned long long int write;
	for (int i=size-1; i>=0; i--)
	{
		write = (value >> i)%2;
		printf("%llu , %i \n", write, i);
		digitalWrite(DATA_PIN, (value >> i) %2);
		//digitalWrite(DATA_PIN, 1);
		
		digitalWrite(CLOCK_PIN, HIGH); delayMicroseconds(5);
		digitalWrite(CLOCK_PIN, LOW); delayMicroseconds(5);
	}
	
	//~ digitalWrite(LATCH_PIN, 1);
	//~ delay(1000);
	//~ digitalWrite(LATCH_PIN, 0);
	//~ for (int i=size/2; i<size; i++)
	//~ {
		//~ write = value & (1ULL<<i);
		//~ printf("%llu , %i \n", write, i);
		//~ digitalWrite(DATA_PIN, value & (1ULL<<i));
		digitalWrite(DATA_PIN, 0);
		
		//~ digitalWrite(CLOCK_PIN, HIGH); delayMicroseconds(10);
		//~ digitalWrite(CLOCK_PIN, LOW); delayMicroseconds(10);
	//~ }
	
	digitalWrite(LATCH_PIN, 1);
	
}

int main(int argc, char **argv)
{
	unsigned long long int value = (1ULL << 48) - 1;
	value = 65535;
	//~ long long  value = (1ULL << 33) - 1;
	printf("size of value is %d\n", sizeof(value));
	int size = 48;
	int delay_time = 2000;
	
	printf("Start\n");
	wiringPiSetup();
	printf("wiri48ngPi setup finished\n");
	
	// initialize shift register and RPi pins
	pinMode(DATA_PIN, OUTPUT);
	pinMode(LATCH_PIN, OUTPUT);
	pinMode(CLOCK_PIN, OUTPUT);
	
	digitalWrite(DATA_PIN, LOW);
	digitalWrite(CLOCK_PIN, LOW);
	digitalWrite(LATCH_PIN, HIGH);
	shiftOutTest(0, size);
	
	//std::cout << "program started" << std::endl;
	//infinite loop to check for new intensity maps from camera
	printf("Begin shifting\n");
	while(1)
	{
		printf("size of value is %d\n", sizeof(value));
		printf("shifting out %llu\n", value);
		shiftOutTest(value, size);
		//shiftOutAll(1, size);
		//shiftOut((2^48)-1, 48);
		//shiftOut(0, 10);
		delay(delay_time);
		printf("shifting out none\n");
		shiftOutTest(0, size);
		//shiftOutAll(0, size);
		delay(delay_time);
	}
}
