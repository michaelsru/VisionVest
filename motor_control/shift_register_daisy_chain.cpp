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
#include <iostream>
#include <string.h>

#include <bitset>

static const int DATA_PIN = 0;
static const int LATCH_PIN = 2;
static const int CLOCK_PIN = 1;
//const int BUF_SIZE = 64; //should only really have 1 intensity map at a time.
static const int NUM_MOTORS = 9;
static const int NUM_INTENSITIES = 10; // the levels of intensities, also # of frames to complete a map.

//MSB FIRST ALWAYS
void shiftOut(int value, int size)
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

int main(int argc, char **argv)
{
	std::cout << "start" << std::endl;
	wiringPiSetup();
	
	// initialize shift register and RPi pins
	pinMode(DATA_PIN, OUTPUT);
	pinMode(LATCH_PIN, OUTPUT);
	pinMode(CLOCK_PIN, OUTPUT);
	
	digitalWrite(DATA_PIN, LOW);
	digitalWrite(CLOCK_PIN, LOW);
	digitalWrite(LATCH_PIN, HIGH);

	//int map[NUM_MOTORS];
	int frames[NUM_INTENSITIES]; //each int128 is a "frame" of ~96~ bits
	bool new_msg_received = true;
	
	int arr[] = {0, 0, 0, 0, 0, 0, 0, 0, 02};
	
	//std::cout << "program started" << std::endl;
	//infinite loop to check for new intensity maps from camera
	for (;;)
	{
		//interprocess check for new messages
		//if new message
			//set arr[] = newest message
			//set new_msg_received = true;
		
		//check for intensity map somehow
		if (new_msg_received) 
		{
			//std::cout << "new msg received" << std::endl;
			new_msg_received = false;
			
			//flush current frames
			memset(frames,0,sizeof(frames));
			
			for (int i=0; i<NUM_INTENSITIES-1; i++) //iterating through each frame
			{
				for (int j=0; j<9; j++) //iterating through each motor on the frame
				{
					frames[i] |= (arr[j] > i) << j; //should populate each frame with correct PWM command
					//std::cout << "shift out frames (binary): " << std::bitset<32>(frames[0]) << std::endl;
					/*
						msg:       0 9 4 6 7
						frames[0]: 0 1 1 1 1
						frames[1]: 0 1 1 1 1
						frames[2]: 0 1 1 1 1
						frames[3]: 0 1 1 1 1
						frames[4]: 0 1 0 1 1
						frames[5]: 0 1 0 1 1
						frames[6]: 0 1 0 0 1
						frames[7]: 0 1 0 0 0
						frames[8]: 0 1 0 0 0
						frames[9]: 0 0 0 0 0
					*/
				}
			}
		}

		// go through map (at least once) to get a full "cycle" of the PWM
		for (int i=0; i< NUM_INTENSITIES; i++) 
		{
			//std::cout << "shift out frames: " << frames[i] << " binary: " << std::bitset<32>(frames[i]) << std::endl;
			shiftOut(frames[i], NUM_MOTORS);
			//delay(1);
			//shiftOut(511, 10);
			//delay(500);
			//shiftOut(0, 10);
			//delay(500);
		}
		//delay(3000);
	}
}
