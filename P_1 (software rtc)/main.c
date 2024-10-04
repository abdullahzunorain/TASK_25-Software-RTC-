#include <reg51.h>
#include "DS1302.h"
#include <string.h>

unsigned char sec =0;
unsigned char min =59;
unsigned char hour=23;
unsigned char day=31;
unsigned char mon=12;
unsigned int year=24;
unsigned int d1000_ms=0;
unsigned int numday ;

sbit d1 = P2^0;
void timer_interrupt () interrupt 1
{
	d1000_ms++;
	if(d1000_ms==5000)
	{
		sec++;
		d1 = ~d1;
	lcd_set_cursor(0,14);
	lcd_display_int(sec );
	lcd_char(' ');
 
	lcd_set_cursor(0,13);
	lcd_char(':');
		
	lcd_set_cursor(0,10);
	lcd_display_int(min);
	lcd_char(' ');
		
	lcd_set_cursor(0,8);
	lcd_char(':');
	lcd_set_cursor(0,5);
	lcd_display_int(hour);
  lcd_char(' ');
		
	lcd_set_cursor(1,5);
	lcd_display_int(day);
	lcd_char(' ');
	
	lcd_set_cursor(1,8);
	lcd_char(':');
	
	lcd_set_cursor(1,10);
	lcd_display_int(mon);
	lcd_char(' ');
	
	lcd_set_cursor(1,13);
	lcd_char(':');
	
	lcd_set_cursor(1,14);
	lcd_display_int(year);
	lcd_char(' ');
	

  numday = dayinmonth(mon, year);

		if(sec==60)
		{
			sec=0;
			min++;
		}
		if(min==60)
		{
			
			min=0;
			hour++;
		}
		if(hour==24)
		{
			hour=0;
			day++;
		}
		if(day > numday)
		{
			day=1;
			mon++;
		}
		if(mon > 12)
		{
			mon=1;
			year++;
		}

		d1000_ms=0;
	}
}

void main()
{
	lcd_init();
  lcd_set_cursor(0,0);
	lcd_string("Time:");
	lcd_set_cursor(1,0);
	lcd_string("Date:");
	TMOD = 0x02;
	TH0= 0xD1; 
	ET0=1;
	EA=1;
	TR0=1;

	while(1)
	{
		
	}
	
}






























//void main()
//{
//	lcd_init();
//	DS1302_init();
//	DS1302_settime(0x23,0x59,0x50);
//	DS1302_setdate(0x31,0x12,0x23);
//	while(1)
//	{
//		DS1302_CE=1;
//		DS1302_readbyte();
//		DS1302_CE=0;
//		
//		DS1302_gettime();
//		DS1302_getdate();
//		
//	}
//}
