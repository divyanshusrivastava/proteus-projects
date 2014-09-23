//-----------------------------------------------------------------------------
// SED1520-Library Demo-Application
//-----------------------------------------------------------------------------
// Copyright (c) 2005 Martin Thomas, Kaiserslautern, Germany
// <eversmith@heizung-thomas.de>
//
// Target: 
//   any AVR with enough SRAM and port-pins (see sed1520.h for connection)
// Tool-chain: 
//   avr-gcc 3.4.3/avr-libc 1.2.3 (WinAVR 2/2005)

#include <avr/io.h>
#include <util/delay.h>
#include "sed1520.h"	// definitions for the LCD-library
#include "fonts.h"	// definitions for the fonts
#include "bmp.h"		// definitions for the bitmaps/icons

#define DELAY 20 /* hundrets of milliseconds (20 -> 2s) */

/* update display (framebuffer to LCD-RAM and delay for t*100 ms */
static void demo_upd_delay(uint8_t t)
 { unsigned char i;

   lcd_update_all();

   for (i=0; i<t; i++) 
    { _delay_ms(50);
      _delay_ms(50);
    }
 }

int main (void) 
 { SP = RAMEND;
  
   lcd_init();			/* initialize display */
	
   while (1) 
    { lcd_erase();	// clear display 

      // single dots 
      lcd_dot_set(20,0);
      lcd_dot_set(21,1);
      lcd_dot_set(22,2);
      lcd_dot_set(23,3);
      
      // line & circle 
      lcd_line(23,3,100,30,LCD_MODE_SET);
      demo_upd_delay(DELAY);
      lcd_circle(90,20,15,LCD_MODE_SET);
      lcd_circle(20,10,5,LCD_MODE_SET);

      demo_upd_delay(DELAY);
      
      // text and fonts 
      lcd_text(5,4,FONT_SIX_DOT,"#abcdefghijkl");
      demo_upd_delay(DELAY);
      lcd_text(5,20,FONT_SEVEN_DOT,"mnopqrstuwxyvz");
      demo_upd_delay(DELAY);
      
      // inverse 
      lcd_box(2,2,118,28,LCD_MODE_XOR);
      demo_upd_delay(DELAY);
      
      // for a clock 
      lcd_erase();
      lcd_text(4,7,FONT_EIGHTEEN_DOT,"12:34:56");
      demo_upd_delay(DELAY);
    
      // fonts & inverse 
      lcd_erase();
      lcd_text(5,0,FONT_NINE_DOT,"EW12A03GLY");
      lcd_text(5,16,FONT_SEVEN_DOT,"Proteus VSM");
      demo_upd_delay(DELAY);
      lcd_box(0,0,SCRN_RIGHT+1,SCRN_BOTTOM+1,LCD_MODE_XOR);
      demo_upd_delay(DELAY);
      lcd_box(0,0,SCRN_RIGHT+1,SCRN_BOTTOM+1,LCD_MODE_XOR);
      demo_upd_delay(DELAY);
      
      // bitmap 
      lcd_bitmap(90, 1, &icon1_bmp, LCD_MODE_SET);
      demo_upd_delay(DELAY);
      lcd_erase();
      lcd_bitmap(0, 0, &frame_bmp, LCD_MODE_SET);
      
      // progmem strings 
      lcd_text_p(6,3,FONT_NINE_DOT,PSTR("Labcenter")); 
      lcd_text_P(6,15,FONT_SEVEN_DOT,"Electronics");
      demo_upd_delay(DELAY);
      demo_upd_delay(DELAY);
    }
   return 0;   /* never reached */
 }

