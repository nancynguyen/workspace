#include <iostream>
#include <string>
#include <unistd.h>

#include "lcdlib.h"
#include "SimpleGPIO.h"

using namespace std;

int main()
{
	gpio_export(LCD_RS);
	gpio_export(LCD_EN);
	gpio_export(LCD_DB4);
	gpio_export(LCD_DB5);
	gpio_export(LCD_DB6);
	gpio_export(LCD_DB7);



	gpio_set_value(LCD_DB4,LOW);
	gpio_set_value(LCD_DB5,LOW);
	gpio_set_value(LCD_DB6,LOW);
	gpio_set_value(LCD_DB7,LOW);

	gpio_set_value(LCD_EN,LOW);
	gpio_set_value(LCD_RS,LOW);

	gpio_set_dir(LCD_RS,OUTPUT_PIN);
	gpio_set_dir(LCD_EN,OUTPUT_PIN);
	gpio_set_dir(LCD_DB4,OUTPUT_PIN);
	gpio_set_dir(LCD_DB5,OUTPUT_PIN);
	gpio_set_dir(LCD_DB6,OUTPUT_PIN);
	gpio_set_dir(LCD_DB7,OUTPUT_PIN);

	cout <<"Hello LCD Test Program" << endl;
//	LCDclr();		// clears LCD
	LCDinit();		// init LCD bit, dual line, cursor right
//	usleep(100000);
 	LCDclr();		// clears LCD
//	usleep(100000);
// 	LCDhome();
//	LCDcursorOn();
//	usleep(10000);
//	LCDcursorOnBlink();
	usleep(1000);

	LCDstring("K3D Solutions");
	LCDGotoXY(0,1);
	LCDstring("LCD Tested!!!");
	usleep(1000000);
	LCDclr();		// clears LCD
	LCDhome();
	LCDstring("Now Printing....");
	LCDGotoXY(0,1);
	LCDstring("Please wait!!!");
	cout <<"LCD Test Finished !" << endl;

	gpio_unexport(LCD_RS);
	gpio_unexport(LCD_EN);
	gpio_unexport(LCD_DB4);
	gpio_unexport(LCD_DB5);
	gpio_unexport(LCD_DB6);
	gpio_unexport(LCD_DB7);

	return 0;

	}
