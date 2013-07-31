 .............../*
 * (C) Copyright 2003
 * David M�ller ELSOFT AG Switzerland. d.mueller@elsoft.ch
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

/************************************************
 * NAME	    : S5PC1XX.h
 * Version  : 31.3.2003
 *
 * common stuff for SAMSUNG S5PC1XX SoC
 ************************************************/

#ifndef __S5PC1XX_H__
#define __S5PC1XX_H__

typedef vu_char		S5PC1XX_REG8;
typedef vu_short	S5PC1XX_REG16;
typedef vu_long		S5PC1XX_REG32;

/* Memory controller (see manual chapter 5) */
typedef struct {
	S5PC1XX_REG32	BWSCON;
	S5PC1XX_REG32	BANKCON[8];
	S5PC1XX_REG32	REFRESH;
	S5PC1XX_REG32	BANKSIZE;
	S5PC1XX_REG32	MRSRB6;
	S5PC1XX_REG32	MRSRB7;
} /*__attribute__((__packed__))*/ S5PC1XX_MEMCTL;


/* USB HOST (see manual chapter 12) */
typedef struct {
	S5PC1XX_REG32	HcRevision;
	S5PC1XX_REG32	HcControl;
	S5PC1XX_REG32	HcCommonStatus;
	S5PC1XX_REG32	HcInterruptStatus;
	S5PC1XX_REG32	HcInterruptEnable;
	S5PC1XX_REG32	HcInterruptDisable;
	S5PC1XX_REG32	HcHCCA;
	S5PC1XX_REG32	HcPeriodCuttendED;
	S5PC1XX_REG32	HcControlHeadED;
	S5PC1XX_REG32	HcControlCurrentED;
	S5PC1XX_REG32	HcBulkHeadED;
	S5PC1XX_REG32	HcBuldCurrentED;
	S5PC1XX_REG32	HcDoneHead;
	S5PC1XX_REG32	HcRmInterval;
	S5PC1XX_REG32	HcFmRemaining;
	S5PC1XX_REG32	HcFmNumber;
	S5PC1XX_REG32	HcPeriodicStart;
	S5PC1XX_REG32	HcLSThreshold;
	S5PC1XX_REG32	HcRhDescriptorA;
	S5PC1XX_REG32	HcRhDescriptorB;
	S5PC1XX_REG32	HcRhStatus;
	S5PC1XX_REG32	HcRhPortStatus1;
	S5PC1XX_REG32	HcRhPortStatus2;
} /*__attribute__((__packed__))*/ S5PC1XX_USB_HOST;


/* INTERRUPT (see manual chapter 14) */
typedef struct {
	S5PC1XX_REG32	SRCPND;
	S5PC1XX_REG32	INTMOD;
	S5PC1XX_REG32	INTMSK;
	S5PC1XX_REG32	PRIORITY;
	S5PC1XX_REG32	INTPND;
	S5PC1XX_REG32	INTOFFSET;
#ifdef CONFIG_S3C2410
	S5PC1XX_REG32	SUBSRCPND;
	S5PC1XX_REG32	INTSUBMSK;
#endif
} /*__attribute__((__packed__))*/ S5PC1XX_INTERRUPT;


/* DMAS (see manual chapter 8) */
typedef struct {
	S5PC1XX_REG32	DISRC;
#ifdef CONFIG_S3C2410
	S5PC1XX_REG32	DISRCC;
#endif
	S5PC1XX_REG32	DIDST;
#ifdef CONFIG_S3C2410
	S5PC1XX_REG32	DIDSTC;
#endif
	S5PC1XX_REG32	DCON;
	S5PC1XX_REG32	DSTAT;
	S5PC1XX_REG32	DCSRC;
	S5PC1XX_REG32	DCDST;
	S5PC1XX_REG32	DMASKTRIG;
#ifdef CONFIG_S3C2400
	S5PC1XX_REG32	res[1];
#endif
#ifdef CONFIG_S3C2410
	S5PC1XX_REG32	res[7];
#endif
} /*__attribute__((__packed__))*/ S5PC1XX_DMA;

typedef struct {
	S5PC1XX_DMA	dma[4];
} /*__attribute__((__packed__))*/ S5PC1XX_DMAS;


/* CLOCK & POWER MANAGEMENT (see S3C2400 manual chapter 6) */
/*                          (see S3C2410 manual chapter 7) */
typedef struct {
	S5PC1XX_REG32	LOCKTIME;
#ifdef CONFIG_S3C24A0
	S5PC1XX_REG32	reserved0;
	S5PC1XX_REG32	reserved1;
	S5PC1XX_REG32	reserved2;
#endif
	S5PC1XX_REG32	MPLLCON;
	S5PC1XX_REG32	UPLLCON;
#ifdef CONFIG_S3C24A0
	S5PC1XX_REG32	reserved3;
	S5PC1XX_REG32	reserved4;
#endif
	S5PC1XX_REG32	CLKCON;
	S5PC1XX_REG32	CLKSLOW;
	S5PC1XX_REG32	CLKDIVN;
} /*__attribute__((__packed__))*/ S5PC1XX_CLOCK_POWER;


/* LCD CONTROLLER (see manual chapter 15) */
typedef struct {
	S5PC1XX_REG32	LCDCON1;
	S5PC1XX_REG32	LCDCON2;
	S5PC1XX_REG32	LCDCON3;
	S5PC1XX_REG32	LCDCON4;
	S5PC1XX_REG32	LCDCON5;
	S5PC1XX_REG32	LCDSADDR1;
	S5PC1XX_REG32	LCDSADDR2;
	S5PC1XX_REG32	LCDSADDR3;
	S5PC1XX_REG32	REDLUT;
	S5PC1XX_REG32	GREENLUT;
	S5PC1XX_REG32	BLUELUT;
	S5PC1XX_REG32	res[8];
	S5PC1XX_REG32	DITHMODE;
	S5PC1XX_REG32	TPAL;
#ifdef CONFIG_S3C2410
	S5PC1XX_REG32	LCDINTPND;
	S5PC1XX_REG32	LCDSRCPND;
	S5PC1XX_REG32	LCDINTMSK;
	S5PC1XX_REG32	LPCSEL;
#endif
} /*__attribute__((__packed__))*/ S5PC1XX_LCD;


/* NAND FLASH (see S3C2410 manual chapter 6) */
typedef struct {
	S5PC1XX_REG32	NFCONF;
	S5PC1XX_REG32	NFCMD;
	S5PC1XX_REG32	NFADDR;
	S5PC1XX_REG32	NFDATA;
	S5PC1XX_REG32	NFSTAT;
	S5PC1XX_REG32	NFECC;
} /*__attribute__((__packed__))*/ S3C2410_NAND;


/* UART (see manual chapter 11) */
typedef struct {
	S5PC1XX_REG32	ULCON;
	S5PC1XX_REG32	UCON;
	S5PC1XX_REG32	UFCON;
	S5PC1XX_REG32	UMCON;
	S5PC1XX_REG32	UTRSTAT;
	S5PC1XX_REG32	UERSTAT;
	S5PC1XX_REG32	UFSTAT;
	S5PC1XX_REG32	UMSTAT;
#ifdef __BIG_ENDIAN
	S5PC1XX_REG8	res1[3];
	S5PC1XX_REG8	UTXH;
	S5PC1XX_REG8	res2[3];
	S5PC1XX_REG8	URXH;
#else /* Little Endian */
	S5PC1XX_REG8	UTXH;
	S5PC1XX_REG8	res1[3];
	S5PC1XX_REG8	URXH;
	S5PC1XX_REG8	res2[3];
#endif
	S5PC1XX_REG32	UBRDIV;
} /*__attribute__((__packed__))*/ S5PC1XX_UART;


/* PWM TIMER (see manual chapter 10) */
typedef struct {
	S5PC1XX_REG32	TCNTB;
	S5PC1XX_REG32	TCMPB;
	S5PC1XX_REG32	TCNTO;
} /*__attribute__((__packed__))*/ S5PC1XX_TIMER;

typedef struct {
	S5PC1XX_REG32	TCFG0;
	S5PC1XX_REG32	TCFG1;
	S5PC1XX_REG32	TCON;
	S5PC1XX_TIMER	ch[4];
	S5PC1XX_REG32	TCNTB4;
	S5PC1XX_REG32	TCNTO4;
} /*__attribute__((__packed__))*/ S5PC1XX_TIMERS;


/* USB DEVICE (see manual chapter 13) */
typedef struct {
#ifdef __BIG_ENDIAN
	S5PC1XX_REG8	res[3];
	S5PC1XX_REG8	EP_FIFO_REG;
#else /*  little endian */
	S5PC1XX_REG8	EP_FIFO_REG;
	S5PC1XX_REG8	res[3];
#endif
} /*__attribute__((__packed__))*/ S5PC1XX_USB_DEV_FIFOS;

typedef struct {
#ifdef __BIG_ENDIAN
	S5PC1XX_REG8	res1[3];
	S5PC1XX_REG8	EP_DMA_CON;
	S5PC1XX_REG8	res2[3];
	S5PC1XX_REG8	EP_DMA_UNIT;
	S5PC1XX_REG8	res3[3];
	S5PC1XX_REG8	EP_DMA_FIFO;
	S5PC1XX_REG8	res4[3];
	S5PC1XX_REG8	EP_DMA_TTC_L;
	S5PC1XX_REG8	res5[3];
	S5PC1XX_REG8	EP_DMA_TTC_M;
	S5PC1XX_REG8	res6[3];
	S5PC1XX_REG8	EP_DMA_TTC_H;
#else /*  little endian */
	S5PC1XX_REG8	EP_DMA_CON;
	S5PC1XX_REG8	res1[3];
	S5PC1XX_REG8	EP_DMA_UNIT;
	S5PC1XX_REG8	res2[3];
	S5PC1XX_REG8	EP_DMA_FIFO;
	S5PC1XX_REG8	res3[3];
	S5PC1XX_REG8	EP_DMA_TTC_L;
	S5PC1XX_REG8	res4[3];
	S5PC1XX_REG8	EP_DMA_TTC_M;
	S5PC1XX_REG8	res5[3];
	S5PC1XX_REG8	EP_DMA_TTC_H;
	S5PC1XX_REG8	res6[3];
#endif
} /*__attribute__((__packed__))*/ S5PC1XX_USB_DEV_DMAS;

typedef struct {
#ifdef __BIG_ENDIAN
	S5PC1XX_REG8	res1[3];
	S5PC1XX_REG8	FUNC_ADDR_REG;
	S5PC1XX_REG8	res2[3];
	S5PC1XX_REG8	PWR_REG;
	S5PC1XX_REG8	res3[3];
	S5PC1XX_REG8	EP_INT_REG;
	S5PC1XX_REG8	res4[15];
	S5PC1XX_REG8	USB_INT_REG;
	S5PC1XX_REG8	res5[3];
	S5PC1XX_REG8	EP_INT_EN_REG;
	S5PC1XX_REG8	res6[15];
	S5PC1XX_REG8	USB_INT_EN_REG;
	S5PC1XX_REG8	res7[3];
	S5PC1XX_REG8	FRAME_NUM1_REG;
	S5PC1XX_REG8	res8[3];
	S5PC1XX_REG8	FRAME_NUM2_REG;
	S5PC1XX_REG8	res9[3];
	S5PC1XX_REG8	INDEX_REG;
	S5PC1XX_REG8	res10[7];
	S5PC1XX_REG8	MAXP_REG;
	S5PC1XX_REG8	res11[3];
	S5PC1XX_REG8	EP0_CSR_IN_CSR1_REG;
	S5PC1XX_REG8	res12[3];
	S5PC1XX_REG8	IN_CSR2_REG;
	S5PC1XX_REG8	res13[7];
	S5PC1XX_REG8	OUT_CSR1_REG;
	S5PC1XX_REG8	res14[3];
	S5PC1XX_REG8	OUT_CSR2_REG;
	S5PC1XX_REG8	res15[3];
	S5PC1XX_REG8	OUT_FIFO_CNT1_REG;
	S5PC1XX_REG8	res16[3];
	S5PC1XX_REG8	OUT_FIFO_CNT2_REG;
#else /*  little endian */
	S5PC1XX_REG8	FUNC_ADDR_REG;
	S5PC1XX_REG8	res1[3];
	S5PC1XX_REG8	PWR_REG;
	S5PC1XX_REG8	res2[3];
	S5PC1XX_REG8	EP_INT_REG;
	S5PC1XX_REG8	res3[15];
	S5PC1XX_REG8	USB_INT_REG;
	S5PC1XX_REG8	res4[3];
	S5PC1XX_REG8	EP_INT_EN_REG;
	S5PC1XX_REG8	res5[15];
	S5PC1XX_REG8	USB_INT_EN_REG;
	S5PC1XX_REG8	res6[3];
	S5PC1XX_REG8	FRAME_NUM1_REG;
	S5PC1XX_REG8	res7[3];
	S5PC1XX_REG8	FRAME_NUM2_REG;
	S5PC1XX_REG8	res8[3];
	S5PC1XX_REG8	INDEX_REG;
	S5PC1XX_REG8	res9[7];
	S5PC1XX_REG8	MAXP_REG;
	S5PC1XX_REG8	res10[7];
	S5PC1XX_REG8	EP0_CSR_IN_CSR1_REG;
	S5PC1XX_REG8	res11[3];
	S5PC1XX_REG8	IN_CSR2_REG;
	S5PC1XX_REG8	res12[3];
	S5PC1XX_REG8	OUT_CSR1_REG;
	S5PC1XX_REG8	res13[7];
	S5PC1XX_REG8	OUT_CSR2_REG;
	S5PC1XX_REG8	res14[3];
	S5PC1XX_REG8	OUT_FIFO_CNT1_REG;
	S5PC1XX_REG8	res15[3];
	S5PC1XX_REG8	OUT_FIFO_CNT2_REG;
	S5PC1XX_REG8	res16[3];
#endif /*  __BIG_ENDIAN */
	S5PC1XX_USB_DEV_FIFOS	fifo[5];
	S5PC1XX_USB_DEV_DMAS	dma[5];
} /*__attribute__((__packed__))*/ S5PC1XX_USB_DEVICE;


/* WATCH DOG TIMER (see manual chapter 18) */
typedef struct {
	S5PC1XX_REG32	WTCON;
	S5PC1XX_REG32	WTDAT;
	S5PC1XX_REG32	WTCNT;
} /*__attribute__((__packed__))*/ S5PC1XX_WATCHDOG;


/* IIC (see manual chapter 20) */
typedef struct {
	S5PC1XX_REG32	IICCON;
	S5PC1XX_REG32	IICSTAT;
	S5PC1XX_REG32	IICADD;
	S5PC1XX_REG32	IICDS;
} /*__attribute__((__packed__))*/ S5PC1XX_I2C;


/* IIS (see manual chapter 21) */
typedef struct {
#ifdef __BIG_ENDIAN
	S5PC1XX_REG16	res1;
	S5PC1XX_REG16	IISCON;
	S5PC1XX_REG16	res2;
	S5PC1XX_REG16	IISMOD;
	S5PC1XX_REG16	res3;
	S5PC1XX_REG16	IISPSR;
	S5PC1XX_REG16	res4;
	S5PC1XX_REG16	IISFCON;
	S5PC1XX_REG16	res5;
	S5PC1XX_REG16	IISFIFO;
#else /*  little endian */
	S5PC1XX_REG16	IISCON;
	S5PC1XX_REG16	res1;
	S5PC1XX_REG16	IISMOD;
	S5PC1XX_REG16	res2;
	S5PC1XX_REG16	IISPSR;
	S5PC1XX_REG16	res3;
	S5PC1XX_REG16	IISFCON;
	S5PC1XX_REG16	res4;
	S5PC1XX_REG16	IISFIFO;
	S5PC1XX_REG16	res5;
#endif
} /*__attribute__((__packed__))*/ S5PC1XX_I2S;


/* I/O PORT (see manual chapter 9) */
typedef struct {
#ifdef CONFIG_S3C2400
	S5PC1XX_REG32	PACON;
	S5PC1XX_REG32	PADAT;

	S5PC1XX_REG32	PBCON;
	S5PC1XX_REG32	PBDAT;
	S5PC1XX_REG32	PBUP;

	S5PC1XX_REG32	PCCON;
	S5PC1XX_REG32	PCDAT;
	S5PC1XX_REG32	PCUP;

	S5PC1XX_REG32	PDCON;
	S5PC1XX_REG32	PDDAT;
	S5PC1XX_REG32	PDUP;

	S5PC1XX_REG32	PECON;
	S5PC1XX_REG32	PEDAT;
	S5PC1XX_REG32	PEUP;

	S5PC1XX_REG32	PFCON;
	S5PC1XX_REG32	PFDAT;
	S5PC1XX_REG32	PFUP;

	S5PC1XX_REG32	PGCON;
	S5PC1XX_REG32	PGDAT;
	S5PC1XX_REG32	PGUP;

	S5PC1XX_REG32	OPENCR;

	S5PC1XX_REG32	MISCCR;
	S5PC1XX_REG32	EXTINT;
#endif
#ifdef CONFIG_S3C2410
	S5PC1XX_REG32	GPACON;
	S5PC1XX_REG32	GPADAT;
	S5PC1XX_REG32	res1[2];
	S5PC1XX_REG32	GPBCON;
	S5PC1XX_REG32	GPBDAT;
	S5PC1XX_REG32	GPBUP;
	S5PC1XX_REG32	res2;
	S5PC1XX_REG32	GPCCON;
	S5PC1XX_REG32	GPCDAT;
	S5PC1XX_REG32	GPCUP;
	S5PC1XX_REG32	res3;
	S5PC1XX_REG32	GPDCON;
	S5PC1XX_REG32	GPDDAT;
	S5PC1XX_REG32	GPDUP;
	S5PC1XX_REG32	res4;
	S5PC1XX_REG32	GPECON;
	S5PC1XX_REG32	GPEDAT;
	S5PC1XX_REG32	GPEUP;
	S5PC1XX_REG32	res5;
	S5PC1XX_REG32	GPFCON;
	S5PC1XX_REG32	GPFDAT;
	S5PC1XX_REG32	GPFUP;
	S5PC1XX_REG32	res6;
	S5PC1XX_REG32	GPGCON;
	S5PC1XX_REG32	GPGDAT;
	S5PC1XX_REG32	GPGUP;
	S5PC1XX_REG32	res7;
	S5PC1XX_REG32	GPHCON;
	S5PC1XX_REG32	GPHDAT;
	S5PC1XX_REG32	GPHUP;
	S5PC1XX_REG32	res8;

	S5PC1XX_REG32	MISCCR;
	S5PC1XX_REG32	DCLKCON;
	S5PC1XX_REG32	EXTINT0;
	S5PC1XX_REG32	EXTINT1;
	S5PC1XX_REG32	EXTINT2;
	S5PC1XX_REG32	EINTFLT0;
	S5PC1XX_REG32	EINTFLT1;
	S5PC1XX_REG32	EINTFLT2;
	S5PC1XX_REG32	EINTFLT3;
	S5PC1XX_REG32	EINTMASK;
	S5PC1XX_REG32	EINTPEND;
	S5PC1XX_REG32	GSTATUS0;
	S5PC1XX_REG32	GSTATUS1;
	S5PC1XX_REG32	GSTATUS2;
	S5PC1XX_REG32	GSTATUS3;
	S5PC1XX_REG32	GSTATUS4;
#endif
#if defined(CONFIG_S3C24A0) || defined(CONFIG_MDIRAC3)
	S5PC1XX_REG32	PACON;
	S5PC1XX_REG32	PADAT;

	S5PC1XX_REG32	PBCON;
	S5PC1XX_REG32	PBDAT;
	S5PC1XX_REG32	PBUP;

	S5PC1XX_REG32	PCCON;
	S5PC1XX_REG32	PCDAT;
	S5PC1XX_REG32	PCUP;

	S5PC1XX_REG32	PDCON;
	S5PC1XX_REG32	PDDAT;
	S5PC1XX_REG32	PDUP;

	S5PC1XX_REG32	PECON;
	S5PC1XX_REG32	PEDAT;
	S5PC1XX_REG32	PEUP;

	S5PC1XX_REG32	PFCON;
	S5PC1XX_REG32	PFDAT;
	S5PC1XX_REG32	PFUP;

	S5PC1XX_REG32	PGCON;
	S5PC1XX_REG32	PGDAT;
	S5PC1XX_REG32	PGUP;

	S5PC1XX_REG32	OPENCR;

	S5PC1XX_REG32	MISCCR;
	S5PC1XX_REG32	EXTINT;
#endif
} /*__attribute__((__packed__))*/ S5PC1XX_GPIO;


/* RTC (see manual chapter 17) */
typedef struct {
#ifdef __BIG_ENDIAN
	S5PC1XX_REG8	res1[67];
	S5PC1XX_REG8	RTCCON;
	S5PC1XX_REG8	res2[3];
	S5PC1XX_REG8	TICNT;
	S5PC1XX_REG8	res3[11];
	S5PC1XX_REG8	RTCALM;
	S5PC1XX_REG8	res4[3];
	S5PC1XX_REG8	ALMSEC;
	S5PC1XX_REG8	res5[3];
	S5PC1XX_REG8	ALMMIN;
	S5PC1XX_REG8	res6[3];
	S5PC1XX_REG8	ALMHOUR;
	S5PC1XX_REG8	res7[3];
	S5PC1XX_REG8	ALMDATE;
	S5PC1XX_REG8	res8[3];
	S5PC1XX_REG8	ALMMON;
	S5PC1XX_REG8	res9[3];
	S5PC1XX_REG8	ALMYEAR;
	S5PC1XX_REG8	res10[3];
	S5PC1XX_REG8	RTCRST;
	S5PC1XX_REG8	res11[3];
	S5PC1XX_REG8	BCDSEC;
	S5PC1XX_REG8	res12[3];
	S5PC1XX_REG8	BCDMIN;
	S5PC1XX_REG8	res13[3];
	S5PC1XX_REG8	BCDHOUR;
	S5PC1XX_REG8	res14[3];
	S5PC1XX_REG8	BCDDATE;
	S5PC1XX_REG8	res15[3];
	S5PC1XX_REG8	BCDDAY;
	S5PC1XX_REG8	res16[3];
	S5PC1XX_REG8	BCDMON;
	S5PC1XX_REG8	res17[3];
	S5PC1XX_REG8	BCDYEAR;
#else /*  little endian */
	S5PC1XX_REG8	res0[64];
	S5PC1XX_REG8	RTCCON;
	S5PC1XX_REG8	res1[3];
	S5PC1XX_REG8	TICNT;
	S5PC1XX_REG8	res2[11];
	S5PC1XX_REG8	RTCALM;
	S5PC1XX_REG8	res3[3];
	S5PC1XX_REG8	ALMSEC;
	S5PC1XX_REG8	res4[3];
	S5PC1XX_REG8	ALMMIN;
	S5PC1XX_REG8	res5[3];
	S5PC1XX_REG8	ALMHOUR;
	S5PC1XX_REG8	res6[3];
	S5PC1XX_REG8	ALMDATE;
	S5PC1XX_REG8	res7[3];
	S5PC1XX_REG8	ALMMON;
	S5PC1XX_REG8	res8[3];
	S5PC1XX_REG8	ALMYEAR;
	S5PC1XX_REG8	res9[3];
	S5PC1XX_REG8	RTCRST;
	S5PC1XX_REG8	res10[3];
	S5PC1XX_REG8	BCDSEC;
	S5PC1XX_REG8	res11[3];
	S5PC1XX_REG8	BCDMIN;
	S5PC1XX_REG8	res12[3];
	S5PC1XX_REG8	BCDHOUR;
	S5PC1XX_REG8	res13[3];
	S5PC1XX_REG8	BCDDATE;
	S5PC1XX_REG8	res14[3];
	S5PC1XX_REG8	BCDDAY;
	S5PC1XX_REG8	res15[3];
	S5PC1XX_REG8	BCDMON;
	S5PC1XX_REG8	res16[3];
	S5PC1XX_REG8	BCDYEAR;
	S5PC1XX_REG8	res17[3];
#endif
} /*__attribute__((__packed__))*/ S5PC1XX_RTC;


/* ADC (see manual chapter 16) */
typedef struct {
	S5PC1XX_REG32	ADCCON;
	S5PC1XX_REG32	ADCDAT;
} /*__attribute__((__packed__))*/ S3C2400_ADC;


/* ADC (see manual chapter 16) */
typedef struct {
	S5PC1XX_REG32	ADCCON;
	S5PC1XX_REG32	ADCTSC;
	S5PC1XX_REG32	ADCDLY;
	S5PC1XX_REG32	ADCDAT0;
	S5PC1XX_REG32	ADCDAT1;
} /*__attribute__((__packed__))*/ S3C2410_ADC;


/* SPI (see manual chapter 22) */
typedef struct {
	S5PC1XX_REG32	SPCON;
	S5PC1XX_REG32	SPSTA;
	S5PC1XX_REG32	SPPIN;
	S5PC1XX_REG32	SPPRE;
	S5PC1XX_REG32	SPTDAT;
	S5PC1XX_REG32	SPRDAT;
	S5PC1XX_REG32	res[2];
} __attribute__((__packed__)) S5PC1XX_SPI_CHANNEL;

typedef struct {
	S5PC1XX_SPI_CHANNEL	ch[S5PC1XX_SPI_CHANNELS];
} /*__attribute__((__packed__))*/ S5PC1XX_SPI;


/* MMC INTERFACE (see S3C2400 manual chapter 19) */
typedef struct {
#ifdef __BIG_ENDIAN
	S5PC1XX_REG8	res1[3];
	S5PC1XX_REG8	MMCON;
	S5PC1XX_REG8	res2[3];
	S5PC1XX_REG8	MMCRR;
	S5PC1XX_REG8	res3[3];
	S5PC1XX_REG8	MMFCON;
	S5PC1XX_REG8	res4[3];
	S5PC1XX_REG8	MMSTA;
	S5PC1XX_REG16	res5;
	S5PC1XX_REG16	MMFSTA;
	S5PC1XX_REG8	res6[3];
	S5PC1XX_REG8	MMPRE;
	S5PC1XX_REG16	res7;
	S5PC1XX_REG16	MMLEN;
	S5PC1XX_REG8	res8[3];
	S5PC1XX_REG8	MMCR7;
	S5PC1XX_REG32	MMRSP[4];
	S5PC1XX_REG8	res9[3];
	S5PC1XX_REG8	MMCMD0;
	S5PC1XX_REG32	MMCMD1;
	S5PC1XX_REG16	res10;
	S5PC1XX_REG16	MMCR16;
	S5PC1XX_REG8	res11[3];
	S5PC1XX_REG8	MMDAT;
#else
	S5PC1XX_REG8	MMCON;
	S5PC1XX_REG8	res1[3];
	S5PC1XX_REG8	MMCRR;
	S5PC1XX_REG8	res2[3];
	S5PC1XX_REG8	MMFCON;
	S5PC1XX_REG8	res3[3];
	S5PC1XX_REG8	MMSTA;
	S5PC1XX_REG8	res4[3];
	S5PC1XX_REG16	MMFSTA;
	S5PC1XX_REG16	res5;
	S5PC1XX_REG8	MMPRE;
	S5PC1XX_REG8	res6[3];
	S5PC1XX_REG16	MMLEN;
	S5PC1XX_REG16	res7;
	S5PC1XX_REG8	MMCR7;
	S5PC1XX_REG8	res8[3];
	S5PC1XX_REG32	MMRSP[4];
	S5PC1XX_REG8	MMCMD0;
	S5PC1XX_REG8	res9[3];
	S5PC1XX_REG32	MMCMD1;
	S5PC1XX_REG16	MMCR16;
	S5PC1XX_REG16	res10;
	S5PC1XX_REG8	MMDAT;
	S5PC1XX_REG8	res11[3];
#endif
} /*__attribute__((__packed__))*/ S3C2400_MMC;


/* SD INTERFACE (see S3C2410 manual chapter 19) */
typedef struct {
	S5PC1XX_REG32	SDICON;
	S5PC1XX_REG32	SDIPRE;
	S5PC1XX_REG32	SDICARG;
	S5PC1XX_REG32	SDICCON;
	S5PC1XX_REG32	SDICSTA;
	S5PC1XX_REG32	SDIRSP0;
	S5PC1XX_REG32	SDIRSP1;
	S5PC1XX_REG32	SDIRSP2;
	S5PC1XX_REG32	SDIRSP3;
	S5PC1XX_REG32	SDIDTIMER;
	S5PC1XX_REG32	SDIBSIZE;
	S5PC1XX_REG32	SDIDCON;
	S5PC1XX_REG32	SDIDCNT;
	S5PC1XX_REG32	SDIDSTA;
	S5PC1XX_REG32	SDIFSTA;
#ifdef __BIG_ENDIAN
	S5PC1XX_REG8	res[3];
	S5PC1XX_REG8	SDIDAT;
#else
	S5PC1XX_REG8	SDIDAT;
	S5PC1XX_REG8	res[3];
#endif
	S5PC1XX_REG32	SDIIMSK;
} /*__attribute__((__packed__))*/ S3C2410_SDI;

#endif /*__S5PC1XX_H__*/
