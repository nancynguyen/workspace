#include "lcdlib.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <poll.h>
#include "gpiolib.h"

uint8_t lcd_data;


#define  data(x)	((lcd_data & (1<<x)) ? HIGH : LOW)

void set_data()
{
	gpio_set_value(LCD_DB4,data(4));
	gpio_set_value(LCD_DB5,data(5));
	gpio_set_value(LCD_DB6,data(6));
	gpio_set_value(LCD_DB7,data(7));
	}

void LCDsendChar(uint8_t ch)		//Sends Char to LCD
{

	gpio_set_dir(LCD_RS,OUTPUT_PIN);
	gpio_set_dir(LCD_EN,OUTPUT_PIN);

	lcd_data=(ch&0b11110000);

	set_data();

	gpio_set_value(LCD_RS,HIGH);
	gpio_set_value(LCD_EN,HIGH);
	usleep(1000);
	gpio_set_value(LCD_EN,LOW);
	gpio_set_value(LCD_RS,LOW);
	usleep(1000);

	lcd_data=((ch&0b00001111)<<4);
	set_data();
	gpio_set_value(LCD_RS,HIGH);
	gpio_set_value(LCD_EN,HIGH);
	usleep(1000);
	gpio_set_value(LCD_EN,LOW);
	gpio_set_value(LCD_RS,LOW);
	usleep(1000);

}
void LCDsendCommand(uint8_t cmd)	//Sends Command to LCD
{

	lcd_data=(cmd&0b11110000);
	set_data();
	gpio_set_value(LCD_EN,HIGH);

	usleep(5000);
	gpio_set_value(LCD_EN,LOW);

	usleep(5000);
	lcd_data=((cmd&0b00001111)<<4);
	set_data();
	gpio_set_value(LCD_EN,HIGH);
	usleep(5000);
	gpio_set_value(LCD_EN,LOW);
	usleep(5000);

}
void LCDinit(void)//Initializes LCD
{

	usleep(15000);
	gpio_set_value(LCD_DB4,LOW);
	gpio_set_value(LCD_DB5,LOW);
	gpio_set_value(LCD_DB6,LOW);
	gpio_set_value(LCD_DB7,LOW);

	gpio_set_value(LCD_EN,LOW);
	gpio_set_value(LCD_RS,LOW);

	//---------one------
	gpio_set_value(LCD_DB7,LOW);
	gpio_set_value(LCD_DB6,LOW);
	gpio_set_value(LCD_DB5,HIGH);
	gpio_set_value(LCD_DB4,HIGH);
	gpio_set_value(LCD_EN,HIGH);
	gpio_set_value(LCD_RS,LOW);
	usleep(1000);
	gpio_set_value(LCD_EN,LOW);
	usleep(1000);

	//-----------two-----------
	gpio_set_value(LCD_DB7,LOW);
	gpio_set_value(LCD_DB6,LOW);
	gpio_set_value(LCD_DB5,HIGH);
	gpio_set_value(LCD_DB4,HIGH);
	gpio_set_value(LCD_EN,HIGH);
	gpio_set_value(LCD_RS,LOW);
	usleep(1000);
	gpio_set_value(LCD_EN,LOW);
	usleep(1000);

	//-------three-------------
	gpio_set_value(LCD_DB7,LOW);
	gpio_set_value(LCD_DB6,LOW);
	gpio_set_value(LCD_DB5,HIGH);
	gpio_set_value(LCD_DB4,LOW);
	gpio_set_value(LCD_EN,HIGH);
	gpio_set_value(LCD_RS,LOW);
	usleep(1000);
	gpio_set_value(LCD_EN,LOW);
	usleep(1000);

	LCDsendCommand(0b00101000);
   //-----increment address, invisible cursor shift------
	LCDsendCommand(0b00000110);

}
void LCDclr(void)				//Clears LCD
{
	LCDsendCommand(1<<LCD_CLR);
}
void LCDhome(void)			//LCD cursor home
{
	LCDsendCommand(1<<LCD_HOME);
}
void LCDstring(char* str)	//Outputs string to LCD
{
	register uint8_t i;

	// check to make sure we have a good pointer
	if (!str) return;
	i=0;
	// print data
	while(str[i]!='\0')
	{
		LCDsendChar(str[i]);
		i++;
	}
}
void LCDGotoXY(uint8_t x, uint8_t y)	//Cursor to X Y position
{
	register uint8_t DDRAMAddr;
	switch(y)
	{
	case 0: DDRAMAddr = LCD_LINE0_DDRAMADDR+x; break;
	case 1: DDRAMAddr = LCD_LINE1_DDRAMADDR+x; break;
	case 2: DDRAMAddr = LCD_LINE2_DDRAMADDR+x; break;
	case 3: DDRAMAddr = LCD_LINE3_DDRAMADDR+x; break;
	default: DDRAMAddr = LCD_LINE0_DDRAMADDR+x;
	}
	// set data address
	LCDsendCommand(1<<LCD_DDRAM | DDRAMAddr);

}

void LCDshiftLeft(uint8_t n)	//Scrol n of characters Right
{
	for (uint8_t i=0;i<n;i++)
	{
		LCDsendCommand(0x1E);
	}
}
void LCDshiftRight(uint8_t n)	//Scrol n of characters Left
{
	for (uint8_t i=0;i<n;i++)
	{
		LCDsendCommand(0x18);
	}
}
void LCDcursorOn(void) 			//displays LCD cursor
{
	LCDsendCommand(0x0E);
}
void LCDcursorOnBlink(void)		//displays LCD blinking cursor
{
	LCDsendCommand(0x0F);
}
void LCDcursorOFF(void)			//turns OFF cursor
{
	LCDsendCommand(0x0C);
}
void LCDblank(void)				//blanks LCD
{
	LCDsendCommand(0x08);
}
void LCDvisible(void)			//Shows LCD
{
	LCDsendCommand(0x0C);
}
void LCDcursorLeft(uint8_t n)	//Moves cursor by n poisitions left
{
	for (uint8_t i=0;i<n;i++)
	{
		LCDsendCommand(0x10);
	}
}
void LCDcursorRight(uint8_t n)	//Moves cursor by n poisitions left
{
	for (uint8_t i=0;i<n;i++)
	{
		LCDsendCommand(0x14);
	}
}
