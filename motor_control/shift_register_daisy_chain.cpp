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

//MSB FIRST ALWAYS
void shiftOut(int dataPin, int clockPin, int latchPin, int value, int size)
{
	digitalWrite(latchPin, 0);
	
	for (int i=size-1; i>=0; i--)
	{
		digitalWrite(dataPin, value & (1<<i));
		
		digitalWrite(clockPin, HIGH); delayMicroseconds(1);
		digitalWrite(clockPin, LOW); delayMicroseconds(1);
	}
	
	digitalWrite(latchPin, 1);
	
}

int main(int argc, char **argv)
{
	const int dataPin = 0;
	const int latchPin = 2;
	const int clockPin = 1;
	
	wiringPiSetup();
	
	pinMode(dataPin, OUTPUT);
	pinMode(latchPin, OUTPUT);
	pinMode(clockPin, OUTPUT);
	
	digitalWrite(dataPin, LOW);
	digitalWrite(clockPin, LOW);
	digitalWrite(latchPin, HIGH);
	
	for (;;)
	{
		int a = 0b0000000000000000;
		int b = 0b1111111111111111;
		
		shiftOut(dataPin, clockPin, latchPin, a, 16);
		delay(2000);
		printf("\n off");
		
		shiftOut(dataPin, clockPin, latchPin, b, 16);
		delay(2000);
		printf("\n on");
		
	}
	
	
}

