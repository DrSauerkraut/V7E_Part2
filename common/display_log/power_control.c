/* 
 * power_control.c
 * 
 * Copyright (C) 2010, TMSBG L.H. SW-BSP1
 *
 * Copyright (C) 2011, Venus Project
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#include <s5pc110.h>
#include <asm/io.h>

void gpio_control_power(void)
{
	unsigned long sleep_config = 0;
	unsigned long sleep_pud = 0;
	unsigned long sleep_dat = 0;
#if 0
	/* 
	 *  GPJ1[5]: "VDD_CAM_EN";	GPJ1CON[5] = "0001" Output;		Output:1.
	 */
    sleep_config = GPJ1CON;    
    sleep_config &= ~( 0xF << 5*4 );
	sleep_config |= ( 0x1 << 5*4 );
    GPJ1CON = sleep_config;                                                                                                   
                                                                                                                                             
    sleep_dat = GPJ1DAT;                                                                                                      
    sleep_dat &= ~( 0x1 << 5*1 );
	sleep_dat |= ( 0x1 << 5*1 );
	GPJ1DAT = sleep_dat;
#endif


#if 0
	/* 
	 *  GPJ2[0]: "HDMI_EN";		Output:0.
	 *  GPJ2[4]: "LCD_POWER1";  Output:0.
	 */
    sleep_config = GPJ2CON;    
    sleep_config &= ~( 0xF << 4*4 | 0xF << 0*4 );
	sleep_config |= ( 0x1 << 4*4 | 0x1 << 0*4 );
    GPJ2CON = sleep_config;                                                                                                   
                                                                                                                                             
    sleep_dat = GPJ2DAT;                                                                                                      
    sleep_dat &= ~( 0x1 << 4*1 | 0x1 << 0*4);
	GPJ2DAT = sleep_dat;
#endif

#if 0
	/* 
	 *  GPJ3[0]: "LCD_BL_EN";		Output:0.
	 *  GPJ3[1]: "Vibrator_EN";  Output:0.
	 *  GPJ3[3]: "GPS_PWR_EN";       Output:0.
	 *  GPJ3[6]: "IOC_POWER";       Output:1.
	 */
    sleep_config = GPJ3CON;    
    sleep_config &= ~( 0xF << 6*4 | 0xF << 3*4 | 0xF << 1*4 | 0xF << 0 );
	sleep_config |= ( 0x1 << 6*4 | 0x1 << 3*4 | 0x1 << 1*4 | 0x1 << 0);
    GPJ3CON = sleep_config;                                                                                                   
                                                                                                                                             
    sleep_dat = GPJ3DAT;                                                                                                      
    sleep_dat &= ~( 0x1 << 6*1 | 0x1 << 3*1 | 0x1 << 1*1 | 0x1 << 0);
	sleep_dat |= ( 0x1 << 6*1 );
	GPJ3DAT = sleep_dat;
#endif


#if 0
	/* 
	 *  GPJ4[4]: "EXT_CARD_EN";		Otput:1.
	 */
    sleep_config = GPJ4CON;    
    sleep_config &= ~( 0xF << 4*4 );
	sleep_config |= ( 0x1 << 4*4 );
    GPJ4CON = sleep_config;                                                                                                   
                                                                                                                                             
    sleep_dat = GPJ4DAT;                                                                                                      
    sleep_dat &= ~( 0x1 << 4*1 );
	sleep_dat |= ( 0x1 << 4*1 );
	GPJ4DAT = sleep_dat;
#endif


#if 1                                                                                                                                        
	/* 
	 *  GPH1[2]: "Secret_EN";	Output:1.                                                                                          
	 */
	sleep_config = GPH1CON;                                                                                                   
	sleep_config &= ~(0xF << 2*4);                                                                                                           
	sleep_config |= (0x1 << 2*4);        
	GPH1CON = sleep_config;                                                                                                   
	    
	sleep_dat = GPH1DAT;
	sleep_dat &= ~( 0x1 << 2 );
	sleep_dat |= ( 0x1 << 2 );       
	GPH1DAT = sleep_dat;                                                                                                      
#endif                                      

#if 1
	/* 
	 *  GPH3[0]: "WIFI_MAC_WAKE";	Output:0.
	 */
	sleep_config = GPH3CON;
	sleep_config &= ~(0xF << 0);
	sleep_config |= 0x1;;		
	GPH3CON = sleep_config;

	sleep_dat = GPH3DAT;
	sleep_dat &= ~(0x1 << 0);		
	GPH3DAT = sleep_dat;
#endif
}

void power_control(void)
{
	gpio_control_power();
	wm8698c_power_control();
}


