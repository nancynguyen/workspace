/*
 * lcdlib.h
 *
 *  Created on: Aug 25, 2014
 *      Author: ngoc
 */

#ifndef LCDLIB_H
#define LCDLIB_H

#include <inttypes.h>

#define LCD_RS	67 // P8_8 GPIO2[3]
#define LCD_EN  68 // P8_10 GPIO2[4]

#define LCD_DB4 65 // P8_18 GPIO2[1]
#define LCD_DB5 46 // P8_16 GPIO1[14]
#define LCD_DB6 26 // P8_14 GPIO0[26]
#define LCD_DB7 44 // P8_12 GPIO0[12]

#define LCD_CLR             0	//DB0: clear display
#define LCD_HOME            1	//DB1: return to home position
#define LCD_ENTRY_MODE      2	//DB2: set entry mode
#define LCD_ENTRY_INC       1	//DB1: increment
#define LCD_ENTRY_SHIFT     0	//DB2: shift
#define LCD_ON_CTRL         3	//DB3: turn lcd/cursor on
#define LCD_ON_DISPLAY      2	//DB2: turn display on
#define LCD_ON_CURSOR       1	//DB1: turn cursor on
#define LCD_ON_BLINK        0	//DB0: blinking cursor
#define LCD_MOVE            4	//DB4: move cursor/display
#define LCD_MOVE_DISP       3	//DB3: move display (0-> move cursor)
#define LCD_MOVE_RIGHT      2	//DB2: move right (0-> left)
#define LCD_FUNCTION        5	//DB5: function set
#define LCD_FUNCTION_8BIT   4	//DB4: set 8BIT mode (0->4BIT mode)
#define LCD_FUNCTION_2LINES 3	//DB3: two lines (0->one line)
#define LCD_FUNCTION_10DOTS 2	//DB2: 5x10 font (0->5x7 font)
#define LCD_CGRAM           6	//DB6: set CG RAM address
#define LCD_DDRAM           7	//DB7: set DD RAM address
// reading:
#define LCD_BUSY            7	//DB7: LCD is busy
#define LCD_LINES			2	//visible lines
#define LCD_LINE_LENGTH		16	//line length (in characters)
// cursor position to DDRAM mapping
#define LCD_LINE0_DDRAMADDR		0x00
#define LCD_LINE1_DDRAMADDR		0x40
#define LCD_LINE2_DDRAMADDR		0x14
#define LCD_LINE3_DDRAMADDR		0x54


void LCDsendChar(uint8_t);		//forms data ready to send to 74HC164
void LCDsendCommand(uint8_t);	//forms data ready to send to 74HC164
void LCDinit(void);			//Initializes LCD
void LCDclr(void);				//Clears LCD
void LCDhome(void);			//LCD cursor home
void LCDstring(char*);	//Outputs string to LCD
void LCDGotoXY(uint8_t, uint8_t);	//Cursor to X Y position

void LCDshiftRight(uint8_t);	//shift by n characters Right
void LCDshiftLeft(uint8_t);	//shift by n characters Left
void LCDcursorOn(void);		//Underline cursor ON
void LCDcursorOnBlink(void);	//Underline blinking cursor ON
void LCDcursorOFF(void);		//Cursor OFF
void LCDblank(void);			//LCD blank but not cleared
void LCDvisible(void);			//LCD visible
void LCDcursorLeft(uint8_t);	//Shift cursor left by n
void LCDcursorRight(uint8_t);	//shif cursor right by n

#endif /* LCDLIB_H_ */
