/*
 * drivers/video/samsung/s5pfb.h
 *
 * $Id: s5pfb.h,v 1.1 2008/11/17 11:12:08 jsgood Exp $
 *
 * Copyright (C) 2008 Jinsung Yang <jsgood.yang@samsung.com>
 *
 * This file is subject to the terms and conditions of the GNU General Public
 * License.  See the file COPYING in the main directory of this archive for
 * more details.
 *
 *	s5p Frame Buffer Driver
 *	based on skeletonfb.c, sa1100fb.h, s5p2410fb.c
 */

#ifndef _s5pFB_H_   
#define _s5pFB_H_

#include "regs-lcd.h"


typedef struct 
{

	/* Screen size */
	int width;
	int height;

	/* Screen info */
	int xres;
	int yres;

	/* Virtual Screen info */
	int xres_virtual;
	int yres_virtual;
	int xoffset;
	int yoffset;

	/* OSD Screen size */
	int osd_width;
	int osd_height;

	/* OSD Screen info */
	int osd_xres;
	int osd_yres;

	/* OSD Screen info */
	int osd_xres_virtual;
	int osd_yres_virtual;

	int bpp;
	int bytes_per_pixel;
	unsigned long pixclock;

	int hsync_len;
	int left_margin;
	int right_margin;
	int vsync_len;
	int upper_margin;
	int lower_margin;
	int sync;

	int cmap_grayscale:1;
	int cmap_inverse:1;
	int cmap_static:1;
	int unused:29;

	/* backlight info */
	int backlight_min;
	int backlight_max;
	int backlight_default;

	int vs_offset;
	int brightness;
	int palette_win;
	int backlight_level;
	int backlight_power;
	int lcd_power;

	//s5p_vsync_info_t vsync_info;
	//s5p_vs_info_t vs_info;

	/* lcd configuration registers */
	unsigned long lcdcon1;
	unsigned long lcdcon2;

    unsigned long lcdcon3;
	unsigned long lcdcon4;
	unsigned long lcdcon5;

	/* GPIOs */
	unsigned long gpcup;
	unsigned long gpcup_mask;
	unsigned long gpccon;
	unsigned long gpccon_mask;
	unsigned long gpdup;
	unsigned long gpdup_mask;
	unsigned long gpdcon;
	unsigned long gpdcon_mask;

	/* lpc3600 control register */
	unsigned long lpcsel;
	unsigned long lcdtcon1;
	unsigned long lcdtcon2;
	unsigned long lcdtcon3;
	unsigned long lcdosd1;
	unsigned long lcdosd2;
	unsigned long lcdosd3;
	unsigned long lcdsaddrb1;
	unsigned long lcdsaddrb2;
	unsigned long lcdsaddrf1;
	unsigned long lcdsaddrf2;
	unsigned long lcdeaddrb1;
	unsigned long lcdeaddrb2;
	unsigned long lcdeaddrf1;
	unsigned long lcdeaddrf2;
	unsigned long lcdvscrb1;
	unsigned long lcdvscrb2;
	unsigned long lcdvscrf1;
	unsigned long lcdvscrf2;
	unsigned long lcdintcon;
	unsigned long lcdkeycon;
	unsigned long lcdkeyval;
	unsigned long lcdbgcon;
	unsigned long lcdfgcon;
	unsigned long lcddithcon;

	unsigned long vidcon0;
	unsigned long vidcon1;
	unsigned long vidcon2;
	unsigned long vidtcon0;
	unsigned long vidtcon1;
	unsigned long vidtcon2;
	unsigned long vidtcon3;
	unsigned long wincon0;
	unsigned long wincon2;
	unsigned long wincon1;
	unsigned long wincon3;
	unsigned long wincon4;

	unsigned long vidosd0a;
	unsigned long vidosd0b;
	unsigned long vidosd0c;
	unsigned long vidosd1a;
	unsigned long vidosd1b;
	unsigned long vidosd1c;
	unsigned long vidosd1d;
	unsigned long vidosd2a;
	unsigned long vidosd2b;
	unsigned long vidosd2c;
	unsigned long vidosd2d;
	unsigned long vidosd3a;
	unsigned long vidosd3b;
	unsigned long vidosd3c;
	unsigned long vidosd4a;
	unsigned long vidosd4b;
	unsigned long vidosd4c;

	unsigned long vidw00add0b0;
	unsigned long vidw00add0b1;
	unsigned long vidw01add0;
	unsigned long vidw01add0b0;
	unsigned long vidw01add0b1;

	unsigned long vidw00add1b0;
	unsigned long vidw00add1b1;
	unsigned long vidw01add1;
	unsigned long vidw01add1b0;
	unsigned long vidw01add1b1;

	unsigned long vidw00add2b0;
	unsigned long vidw00add2b1;

	unsigned long vidw02add0;
	unsigned long vidw03add0;
	unsigned long vidw04add0;

	unsigned long vidw02add1;
	unsigned long vidw03add1;
	unsigned long vidw04add1;
	unsigned long vidw00add2;
	unsigned long vidw01add2;
	unsigned long vidw02add2;
	unsigned long vidw03add2;
	unsigned long vidw04add2;

	unsigned long vidintcon;
	unsigned long vidintcon0;
	unsigned long vidintcon1;
	unsigned long w1keycon0;
	unsigned long w1keycon1;
	unsigned long w2keycon0;
	unsigned long w2keycon1;
	unsigned long w3keycon0;
	unsigned long w3keycon1;
	unsigned long w4keycon0;
	unsigned long w4keycon1;

	unsigned long win0map;
	unsigned long win1map;
	unsigned long win2map;
	unsigned long win3map;
	unsigned long win4map;

	unsigned long wpalcon;
	unsigned long dithmode;
	unsigned long intclr0;
	unsigned long intclr1;
	unsigned long intclr2;

	unsigned long win0pal;
	unsigned long win1pal;

	/* utility functions */
	void (*set_backlight_power)(int);
	void (*set_lcd_power)(int);
	void (*set_brightness)(int);
}s5p_fimd_info_t;

#define s5p_FB_PALETTE_BUFF_CLEAR	(0x80000000)	/* entry is clear/invalid */
#define s5p_FB_COLOR_KEY_DIR_BG 	0
#define s5p_FB_COLOR_KEY_DIR_FG 	1
#define s5p_FB_DEFAULT_BACKLIGHT_LEVEL	2
#define s5p_FB_MAX_DISPLAY_OFFSET	200
#define s5p_FB_DEFAULT_DISPLAY_OFFSET	100
#define s5p_FB_MAX_ALPHA_LEVEL		0xf
#define s5p_FB_MAX_BRIGHTNESS		180         
#define s5p_FB_DEFAULT_BRIGHTNESS	4
#define s5p_FB_VS_SET 			12
#define s5p_FB_VS_MOVE_LEFT		15
#define s5p_FB_VS_MOVE_RIGHT		16
#define s5p_FB_VS_MOVE_UP		17
#define s5p_FB_VS_MOVE_DOWN		18
#define s5pFB_ALPHA_MODE_PLANE		0
#define s5pFB_ALPHA_MODE_PIXEL		1

#define s5p_FB_PIXEL_BPP_8	8
#define s5p_FB_PIXEL_BPP_16	16	/*  RGB 5-6-5 format for SMDK EVAL BOARD */
#define s5p_FB_PIXEL_BPP_24	24	/*  RGB 8-8-8 format for SMDK EVAL BOARD */

#define CONFIG_FB_s5p_BPP_24

s5p_fimd_info_t s5p_fimd =
{
	.vidcon0 = s5p_VIDCON0_INTERLACE_F_PROGRESSIVE | s5p_VIDCON0_VIDOUT_RGB_IF | s5p_VIDCON0_L1_DATA16_SUB_16_MODE | \
	           s5p_VIDCON0_L0_DATA16_MAIN_16_MODE | s5p_VIDCON0_PNRMODE_RGB_P | \
	           s5p_VIDCON0_CLKVALUP_ALWAYS | s5p_VIDCON0_CLKDIR_DIVIDED | s5p_VIDCON0_CLKSEL(1) | \
	           s5p_VIDCON0_ENVID_DISABLE | s5p_VIDCON0_ENVID_F_DISABLE,

	.dithmode = (s5p_DITHMODE_RDITHPOS_5BIT | s5p_DITHMODE_GDITHPOS_6BIT | s5p_DITHMODE_BDITHPOS_5BIT ) & s5p_DITHMODE_DITHERING_DISABLE,

#if defined (CONFIG_FB_s5p_BPP_8)
	.wincon0 =  s5p_WINCONx_BYTSWP_ENABLE | s5p_WINCONx_BURSTLEN_4WORD | s5p_WINCONx_BPPMODE_F_8BPP_PAL,
	.wincon1 =  s5p_WINCONx_HAWSWP_ENABLE | s5p_WINCONx_BURSTLEN_4WORD | s5p_WINCONx_BPPMODE_F_16BPP_565 | s5p_WINCONx_BLD_PIX_PLANE | s5p_WINCONx_ALPHA_SEL_1,
	.bpp = s5p_FB_PIXEL_BPP_8,
	.bytes_per_pixel = 1,
	.wpalcon = s5p_WPALCON_W0PAL_16BIT,

#elif defined (CONFIG_FB_s5p_BPP_16)
	.wincon0 = s5p_WINCONx_ENLOCAL_DMA | s5p_WINCONx_BUFSEL_0 | s5p_WINCONx_BUFAUTOEN_DISABLE | \
	           s5p_WINCONx_BITSWP_DISABLE | s5p_WINCONx_BYTSWP_DISABLE | s5p_WINCONx_HAWSWP_ENABLE | \
	           s5p_WINCONx_BURSTLEN_16WORD | s5p_WINCONx_BPPMODE_F_16BPP_565 | s5p_WINCONx_ENWIN_F_DISABLE,

	.wincon1 = s5p_WINCONx_ENLOCAL_DMA | s5p_WINCONx_BUFSEL_0 | s5p_WINCONx_BUFAUTOEN_DISABLE | \
	           s5p_WINCONx_BITSWP_DISABLE | s5p_WINCONx_BYTSWP_DISABLE | s5p_WINCONx_HAWSWP_ENABLE | \
	           s5p_WINCONx_BURSTLEN_16WORD | s5p_WINCONx_BLD_PIX_PLANE | s5p_WINCONx_BPPMODE_F_16BPP_565 | \
	           s5p_WINCONx_ALPHA_SEL_1 | s5p_WINCONx_ENWIN_F_DISABLE,

	.wincon2 = s5p_WINCONx_ENLOCAL_DMA | s5p_WINCONx_BITSWP_DISABLE | s5p_WINCONx_BYTSWP_DISABLE | \
	           s5p_WINCONx_HAWSWP_ENABLE | s5p_WINCONx_BURSTLEN_4WORD | s5p_WINCONx_BURSTLEN_16WORD | \
	           s5p_WINCONx_BLD_PIX_PLANE | s5p_WINCONx_BPPMODE_F_16BPP_565 | s5p_WINCONx_ALPHA_SEL_1 | s5p_WINCONx_ENWIN_F_DISABLE,

	.wincon3 = s5p_WINCONx_BITSWP_DISABLE | s5p_WINCONx_BYTSWP_DISABLE | s5p_WINCONx_HAWSWP_ENABLE | \
	           s5p_WINCONx_BURSTLEN_4WORD | s5p_WINCONx_BURSTLEN_16WORD | s5p_WINCONx_BLD_PIX_PLANE | \
	           s5p_WINCONx_BPPMODE_F_16BPP_565 | s5p_WINCONx_ALPHA_SEL_1 | s5p_WINCONx_ENWIN_F_DISABLE,

	.wincon4 = s5p_WINCONx_BITSWP_DISABLE | s5p_WINCONx_BYTSWP_DISABLE | s5p_WINCONx_HAWSWP_ENABLE | \
	           s5p_WINCONx_BURSTLEN_4WORD | s5p_WINCONx_BURSTLEN_16WORD | s5p_WINCONx_BLD_PIX_PLANE |
	           s5p_WINCONx_BPPMODE_F_16BPP_565 | s5p_WINCONx_ALPHA_SEL_1 | s5p_WINCONx_ENWIN_F_DISABLE,

	.bpp = s5p_FB_PIXEL_BPP_16,
	.bytes_per_pixel = 2,
	.wpalcon = s5p_WPALCON_W0PAL_16BIT,

#elif defined (CONFIG_FB_s5p_BPP_24)
	.wincon0 = s5p_WINCONx_HAWSWP_DISABLE | s5p_WINCONx_BURSTLEN_16WORD | s5p_WINCONx_BPPMODE_F_24BPP_888 ,//| s5p_WINCON_ENWIN_ENABLE,
	.wincon1 = s5p_WINCONx_HAWSWP_DISABLE | s5p_WINCONx_BURSTLEN_16WORD | s5p_WINCONx_BPPMODE_F_24BPP_888 | s5p_WINCONx_BLD_PIX_PLANE | s5p_WINCONx_ALPHA_SEL_1,
	.wincon2 = s5p_WINCONx_HAWSWP_DISABLE | s5p_WINCONx_BURSTLEN_16WORD | s5p_WINCONx_BPPMODE_F_24BPP_888 | s5p_WINCONx_BLD_PIX_PLANE | s5p_WINCONx_ALPHA_SEL_1,
	.wincon3 = s5p_WINCONx_HAWSWP_DISABLE | s5p_WINCONx_BURSTLEN_16WORD | s5p_WINCONx_BPPMODE_F_24BPP_888 | s5p_WINCONx_BLD_PIX_PLANE | s5p_WINCONx_ALPHA_SEL_1,
	.wincon4 = s5p_WINCONx_HAWSWP_DISABLE | s5p_WINCONx_BURSTLEN_16WORD | s5p_WINCONx_BPPMODE_F_24BPP_888 | s5p_WINCONx_BLD_PIX_PLANE | s5p_WINCONx_ALPHA_SEL_1,
	.bpp = s5p_FB_PIXEL_BPP_24,
	.bytes_per_pixel =4,
	.wpalcon = s5p_WPALCON_W0PAL_24BIT,
#endif

	.vidosd1c = s5p_VIDOSDxC_ALPHA1_B(s5p_FB_MAX_ALPHA_LEVEL) | s5p_VIDOSDxC_ALPHA1_G(s5p_FB_MAX_ALPHA_LEVEL) | s5p_VIDOSDxC_ALPHA1_R(s5p_FB_MAX_ALPHA_LEVEL),
	.vidosd2c = s5p_VIDOSDxC_ALPHA1_B(s5p_FB_MAX_ALPHA_LEVEL) | s5p_VIDOSDxC_ALPHA1_G(s5p_FB_MAX_ALPHA_LEVEL) | s5p_VIDOSDxC_ALPHA1_R(s5p_FB_MAX_ALPHA_LEVEL),
	.vidosd3c = s5p_VIDOSDxC_ALPHA1_B(s5p_FB_MAX_ALPHA_LEVEL) | s5p_VIDOSDxC_ALPHA1_G(s5p_FB_MAX_ALPHA_LEVEL) | s5p_VIDOSDxC_ALPHA1_R(s5p_FB_MAX_ALPHA_LEVEL),
	.vidosd4c = s5p_VIDOSDxC_ALPHA1_B(s5p_FB_MAX_ALPHA_LEVEL) | s5p_VIDOSDxC_ALPHA1_G(s5p_FB_MAX_ALPHA_LEVEL) | s5p_VIDOSDxC_ALPHA1_R(s5p_FB_MAX_ALPHA_LEVEL),

	.vidintcon0 = s5p_VIDINTCON0_FRAMESEL0_VSYNC | s5p_VIDINTCON0_FRAMESEL1_NONE | s5p_VIDINTCON0_INTFRMEN_DISABLE | \
	              s5p_VIDINTCON0_FIFOSEL_WIN0 | s5p_VIDINTCON0_FIFOLEVEL_25 | s5p_VIDINTCON0_INTFIFOEN_DISABLE | s5p_VIDINTCON0_INTEN_ENABLE,
	.vidintcon1 = 0,

	.xoffset = 0,
	.yoffset = 0,

	//Specifies color key setting register.
	.w1keycon0 = s5p_WxKEYCON0_KEYBLEN_DISABLE | s5p_WxKEYCON0_KEYEN_F_DISABLE | s5p_WxKEYCON0_DIRCON_MATCH_FG_IMAGE | s5p_WxKEYCON0_COMPKEY(0x0),
	.w1keycon1 = s5p_WxKEYCON1_COLVAL(0xffffff),
	.w2keycon0 = s5p_WxKEYCON0_KEYBLEN_DISABLE | s5p_WxKEYCON0_KEYEN_F_DISABLE | s5p_WxKEYCON0_DIRCON_MATCH_FG_IMAGE | s5p_WxKEYCON0_COMPKEY(0x0),
	.w2keycon1 = s5p_WxKEYCON1_COLVAL(0xffffff),
	.w3keycon0 = s5p_WxKEYCON0_KEYBLEN_DISABLE | s5p_WxKEYCON0_KEYEN_F_DISABLE | s5p_WxKEYCON0_DIRCON_MATCH_FG_IMAGE | s5p_WxKEYCON0_COMPKEY(0x0),
	.w3keycon1 = s5p_WxKEYCON1_COLVAL(0xffffff),
	.w4keycon0 = s5p_WxKEYCON0_KEYBLEN_DISABLE | s5p_WxKEYCON0_KEYEN_F_DISABLE | s5p_WxKEYCON0_DIRCON_MATCH_FG_IMAGE | s5p_WxKEYCON0_COMPKEY(0x0),
	.w4keycon1 = s5p_WxKEYCON1_COLVAL(0xffffff),

	.sync = 0,
	.cmap_static = 1,

	.vs_offset = s5p_FB_DEFAULT_DISPLAY_OFFSET,
	.brightness = s5p_FB_DEFAULT_BRIGHTNESS,
	.backlight_level = s5p_FB_DEFAULT_BACKLIGHT_LEVEL,
	.backlight_power = 1,
	.lcd_power = 1,
};


#define s5p_FB_HFP		116 //28	/* front porch */
#define s5p_FB_HSW		130  //40	/* hsync width */
#define s5p_FB_HBP		130  //22	/* back porch */

#define s5p_FB_VFP		59 //28	/* front porch */
#define s5p_FB_VSW		83//10	/* vsync width */
#define s5p_FB_VBP		58 //22	/* back porch */

#define s5p_FB_HRES		1024	/* horizon pixel  x resolition */
#define s5p_FB_VRES		600	/* line cnt       y resolution */

#define s5p_FB_HRES_VIRTUAL	s5p_FB_HRES     /* horizon pixel  x resolition */
#define s5p_FB_VRES_VIRTUAL	s5p_FB_VRES * 2 /* line cnt       y resolution */

#define s5p_FB_HRES_OSD		1024	/* horizon pixel  x resolition */
#define s5p_FB_VRES_OSD		600	/* line cnt       y resolution */

#define s5p_FB_HRES_OSD_VIRTUAL	s5p_FB_HRES_OSD     /* horizon pixel  x resolition */
#define s5p_FB_VRES_OSD_VIRTUAL s5p_FB_VRES_OSD * 2 /* line cnt       y resolution */

#define s5p_FB_VFRAME_FREQ     	60	/* frame rate freq */
#define S3C_FB_PIXEL_CLOCK	(s5p_FB_VFRAME_FREQ * (s5p_FB_HFP + s5p_FB_HSW + s5p_FB_HBP + s5p_FB_HRES) * (s5p_FB_VFP + s5p_FB_VSW + s5p_FB_VBP + s5p_FB_VRES))


#endif




