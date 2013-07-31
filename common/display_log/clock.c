/* linux/arch/arm/plat-s3c64xx/clock.c
 *
 * Copyright 2008 Openmoko, Inc.
 * Copyright 2008 Simtec Electronics
 *	Ben Dooks <ben@simtec.co.uk>
 *	http://armlinux.simtec.co.uk/
 *
 * S3C64XX Base clock support
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
*/

#include <common.h>
#include <command.h>
#include <regs.h>
#include "s3c64xx-dvfs.h"

#define writel(val,reg)		(*(volatile unsigned int *)(reg) = (val))
#define readl(reg)			(*(volatile unsigned int *)(reg))

//extern int  s3c6410_changedivider(unsigned int value, unsigned int vaddr);

/* definition for cpu freq */

#define ARM_CLK_DIV	*(volatile unsigned long *)(0xE0100300)


#define ARM_DIV_RATIO_BIT		0
#define ARM_DIV_MASK			(0x7<<ARM_DIV_RATIO_BIT)
#define HCLK_DIV_RATIO_BIT		20
#define HCLK_DIV_MASK			(0x7<<HCLK_DIV_RATIO_BIT)
#define PCLK_DIV_RATIO_BIT		16
#define PCLK_DIV_MASK			(0xf<<PCLK_DIV_RATIO_BIT)
#define MHZ (1000*1000)


/* ARMCLK, HCLKX2, APLL, PDIV, ARM_DIV, HCLKX2_DIV */
static const u32 s3c_cpu_clk_tab_533MHz[][6] = {
	{532*MHZ, 266 *MHZ, 266, 3, 0, 1},
	{266*MHZ, 266 *MHZ, 266, 3, 1, 1},
	{133*MHZ, 266 *MHZ, 266, 3, 3, 1},
#ifdef USE_DVFS_AL1_LEVEL
	{133*MHZ, 133 *MHZ, 266, 1, 3, 3},
#endif /* USE_DVFS_AL1_LEVEL */
	{ 66*MHZ, 133 *MHZ, 266, 1, 7, 3},
};

/* ARMCLK, HCLKX2, APLL, PDIV, ARM_DIV, HCLKX2_DIV */
static const u32 s3c_cpu_clk_tab_800MHz[][6] = {
	{800*MHZ,  266 *MHZ, 400, 3, 0, 2},
	{400*MHZ,  266 *MHZ, 400, 3, 1, 2},
	{266*MHZ,  266 *MHZ, 400, 3, 2, 2},
	{133*MHZ,  266 *MHZ, 400, 3, 5, 2},
#ifdef USE_DVFS_AL1_LEVEL
	{133*MHZ,  133 *MHZ, 400, 1, 5, 5},
#endif /* USE_DVFS_AL1_LEVEL */
	{ 66*MHZ,  133 *MHZ, 400, 1, 11, 5},
};

unsigned int S3C64XX_FREQ_TAB = 1;

static const u32 (*s3c_cpu_clk_tab[2])[6] = {
	s3c_cpu_clk_tab_533MHz,
	s3c_cpu_clk_tab_800MHz,
} ;

static u32 s3c_cpu_clk_tab_size(void)
{
	u32 size;
	if(S3C64XX_FREQ_TAB)
		size = ARRAY_SIZE(s3c_cpu_clk_tab_800MHz);
	else
		size = ARRAY_SIZE(s3c_cpu_clk_tab_533MHz);

	return size;
}

int s3c64xx_clk_set_rate(unsigned int target_freq,
                                unsigned int index )
{

	unsigned int mask;
	u32 clk_div0;
	u32 arm_div_0_1;
	u32 arm_div_0;
	static const u32 (*cpu_clk_tab)[6];

	cpu_clk_tab = s3c_cpu_clk_tab[S3C64XX_FREQ_TAB];
	
	/* validate target frequency */ 
	if(cpu_clk_tab[index][0] != target_freq)
	{
		return 0;
	}
	mask = (~(HCLK_DIV_MASK)) & (~(ARM_DIV_MASK)) & (~(PCLK_DIV_MASK));
	clk_div0 = ARM_CLK_DIV & mask;
	clk_div0 |= cpu_clk_tab[index][4];
	clk_div0 |= (cpu_clk_tab[index][5]) << HCLK_DIV_RATIO_BIT;
	clk_div0 |= (cpu_clk_tab[index][3]) << PCLK_DIV_RATIO_BIT;
	arm_div_0 = ARM_CLK_DIV;
	arm_div_0_1 = ARM_CLK_DIV;
	printf(" before changer ARM_CLK_DVI and clk_div0 vaule is %x and %x, and%x\n", arm_div_0,arm_div_0_1,clk_div0);
	//s3c6410_changedivider(clk_div0, ARM_CLK_DIV);
	ARM_CLK_DIV = clk_div0;
	arm_div_0 = ARM_CLK_DIV;
	printf(" after changer ARM_CLK_DVI vaule is %x\n", arm_div_0);
	return 0;
}


int s3c_fclk_set_rate(unsigned long rate)
{

	int index, ret;
	
	index = s3c64xx_cpufreq_index;
	printf("target rate and index is %d and %d\n", rate, index);
	ret = s3c64xx_clk_set_rate(rate, index);
	return 0;
	
}

