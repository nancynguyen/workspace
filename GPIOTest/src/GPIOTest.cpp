//============================================================================
// Name        : GPIOTest.cpp
// Author      : Ngoc Nguyen
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <unistd.h>
#include "gpiolib.h"
#include <iomux>
using namespace std;

unsigned int LEDGPIO = 60;   // GPIO1_28 = (1x32) + 28 = 60
unsigned int ButtonGPIO = 15;   // GPIO0_15 = (0x32) + 15 = 15

int main(int argc, char *argv[]){

	cout << "Testing the GPIO Pins" << endl;

	gpio_export(LEDGPIO);    // The LED
	gpio_export(ButtonGPIO);   // The push button switch
	gpio_set_dir(LEDGPIO, OUTPUT_PIN);   // The LED is an output
	gpio_set_dir(ButtonGPIO, INPUT_PIN);   // The push button input

	// Flash the LED 5 times
	for(int i=0; i<5; i++){
		cout << "Setting the LED on" << endl;
                gpio_set_value(LEDGPIO, HIGH);
		usleep(1000000);         // on for 200ms
		cout << "Setting the LED off" << endl;
                gpio_set_value(LEDGPIO, LOW);
		usleep(1000000);         // off for 200ms
	}

	// Wait for the push button to be pressed
	cout << "Please press the button!" << endl;

	unsigned int value = LOW;
	do {
		gpio_get_value(ButtonGPIO, &value);
		cout << ".";
		usleep(1000);      // sleep for one millisecond
	} while (value!=HIGH);
	cout << endl <<  "Button was just pressed!" << endl;

	cout << "Finished Testing the GPIO Pins" << endl;
	gpio_unexport(LEDGPIO);     // unexport the LED
	gpio_unexport(ButtonGPIO);  // unexport the push button
	return 0;
}
