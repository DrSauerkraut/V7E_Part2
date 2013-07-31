/*
 *  linux/arch/arm/plat-s3c64xx/s3c64xx-cpufreq.c
 *
 *  CPU frequency scaling for S3C64XX
 *
 *  Copyright (C) 2008 Samsung Electronics
 *
 *  Based on cpu-sa1110.c, Copyright (C) 2001 Russell King
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
//#include "types.h"

//#include "cpufreq.h"

//#include <linux/clk.h>

//#include <asm/system.h>

#include <common.h>
#include <command.h>
#include <s3c6410.h>
#include "s3c64xx-dvfs.h"

extern int dvs_set_voltage(int vcc_arm, int vcc_int);

static int prevIndex_dvfs = 0;
unsigned int s3c64xx_cpufreq_index = 0;

#define CLIP_LEVEL(a, b) (a > b ? b : a)

#define CPUFREQ_ENTRY_INVALID ~0
#define CPUFREQ_TABLE_END     ~1

struct cpufreq_frequency_table {
	unsigned int	index;     /* any */
	unsigned int	frequency; /* kHz - doesn't need to be in ascending
				    * order */
};

static struct cpufreq_frequency_table freq_table_532MHz[] = {
	{0, 532*KHZ_T},
	{1, 266*KHZ_T},
	{2, 133*KHZ_T},
#ifdef USE_DVFS_AL1_LEVEL
	{3, 133*KHZ_T},
	{4, 66*KHZ_T},
	{5, CPUFREQ_TABLE_END},
#else
	{3, 66*KHZ_T},
	{4, CPUFREQ_TABLE_END},		
#endif /* USE_DVFS_AL1_LEVEL */
};

static struct cpufreq_frequency_table freq_table_800MHz[] = {
	{0, 800*KHZ_T},
	{1, 400*KHZ_T},
	{2, 266*KHZ_T},	
	{3, 133*KHZ_T},
#ifdef USE_DVFS_AL1_LEVEL
	{4, 133*KHZ_T},
	{5, (66)*KHZ_T},
	{6, CPUFREQ_TABLE_END},
#else
	{4, (66)*KHZ_T},
	{5, CPUFREQ_TABLE_END},
#endif /* USE_DVFS_AL1_LEVEL */
};

static unsigned char transition_state_800MHz[][2] = {
	{1, 0},
	{2, 0},
	{3, 1},
	{3, 2},
#ifdef USE_DVFS_AL1_LEVEL
	{5, 3},
	{5, 4},
#else
	{4, 3},
#endif /* USE_DVFS_AL1_LEVEL */
};

static unsigned char transition_state_532MHz[][2] = {
	{1, 0},
	{2, 0},
	{2, 1},
#ifdef USE_DVFS_AL1_LEVEL
	{4, 2},
	{4, 3},
#else
	{3, 2},
#endif /* USE_DVFS_AL1_LEVEL */
};

/* frequency voltage matching table */
static const unsigned int frequency_match_532MHz[][4] = {
/* frequency, Mathced VDD ARM voltage , Matched VDD INT*/
	{532000, 1100, 1200, 0},
	{266000, 1050, 1200, 1},
	{133000, 1050, 1200, 2},
#ifdef USE_DVFS_AL1_LEVEL
	{133000, 1000, 1000, 3},
	{66000, 1000, 1000, 4},
#else
	{66000, 1000, 1000, 3},
#endif /* USE_DVFS_AL1_LEVEL */
};

/* frequency voltage matching table */
static const unsigned int frequency_match_800MHz[][4] = {
/* frequency, Mathced VDD ARM voltage , Matched VDD INT*/
	{800000, 1300, 1200, 0},
	{400000, 1100, 1200, 1},
	{266000, 1050, 1200, 2},
	{133000, 1050, 1200, 3},
#ifdef USE_DVFS_AL1_LEVEL
	{133000, 1000, 1050, 4},
	{66000, 1000, 1050, 5},
#else
	{66000, 1000, 1050, 4},
#endif /* USE_DVFS_AL1_LEVEL */
};

static const unsigned int (*frequency_match[2])[4] = {
	frequency_match_532MHz,
	frequency_match_800MHz,
};

static unsigned char (*transition_state[2])[2] = {
	transition_state_532MHz,
	transition_state_800MHz,
};

static struct cpufreq_frequency_table *s3c6410_freq_table[] = {
	freq_table_532MHz,
	freq_table_800MHz,
};

#ifdef USE_DVS
static unsigned int vcc_arm = 1300, vcc_int = 1200;

int set_voltage(unsigned int freq_index)
{
	static int index = 0;
	unsigned int arm_voltage, int_voltage;
	unsigned int arm_delay, int_delay, delay;
	
	if(index == freq_index)
		return 0;
		
	index = freq_index;
	
	arm_voltage = frequency_match[S3C64XX_FREQ_TAB][index][1];
	int_voltage = frequency_match[S3C64XX_FREQ_TAB][index][2];

	arm_delay =  10;
	int_delay =  10;
	
	delay = arm_delay > int_delay ? arm_delay : int_delay;

	if (arm_voltage != vcc_arm || int_voltage != vcc_int)
	{
		dvs_set_voltage(arm_voltage, arm_voltage);
		vcc_arm = arm_voltage;
		vcc_int = int_voltage;
	}
	printf ("after set vcc_arm and vcc_int is %d and %d\n", vcc_arm, vcc_int);
	udelay(delay);
	return 0;
}
#endif	/* USE_DVS */


int dvs_set_voltage(int vcc_arm, int vcc_int)
{	
	max8698c_dvs_set_voltage(vcc_arm, vcc_int);
	return 0;

}


/*
 *  add for uboot DVFS
 *
 */
void start_dvfs(unsigned int index)  // index : 0 : 800M, 1: 400M, 2: 266M, 3: 133M, 4: 133M, 5: 66M
{	
	int ret = 0;
	unsigned int target_freq;
	s3c64xx_cpufreq_index = index;
	if(prevIndex_dvfs == index)
		return ret;

	target_freq = s3c6410_freq_table[S3C64XX_FREQ_TAB][index].frequency;

	if(prevIndex_dvfs  <  index) 
	{
		/* frequency scaling */
		ret = s3c_fclk_set_rate(target_freq * KHZ_T);
		if(ret != 0) 
		{
			printf( "frequency scaling error\n");
			goto s3c6410_target_end;
		}
		/* voltage scaling */
		set_voltage(index);
		prevIndex_dvfs = index;
	}
	else {
		/* voltage scaling */
		set_voltage(index);
		/* frequency scaling */
		ret = s3c_fclk_set_rate(target_freq * KHZ_T);
		//ret = clk_set_rate(mpu_clk, target_freq * KHZ_T);
		if(ret != 0) {
			printf( "frequency scaling error\n");
			goto s3c6410_target_end;
		}
		prevIndex_dvfs = index;
	}

s3c6410_target_end:
	return ret;

}



