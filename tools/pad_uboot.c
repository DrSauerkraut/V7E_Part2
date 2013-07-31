/*
 * (C) Copyright 2009
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

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef __ASSEMBLY__
#define	__ASSEMBLY__			/* Dirty trick to get only #defines */
#endif
#define	__ASM_STUB_PROCESSOR_H__	/* don't include asm/processor.     */
#include <config.h>
#undef	__ASSEMBLY__

#define U_BOOT_SIZE		256 * 1024
#define U_BOOT0_SIZE	8 * 1024

extern unsigned long crc32(unsigned long, const unsigned char *, unsigned int);

int main(int argc, char **argv)
{
	unsigned char *buffer;
	FILE *fStream = NULL;
	unsigned int crc;
	int orig_size;
	int ret = 0;

	if (argc != 2) {
		printf("Usage: pad_uboot {u-boot}\n");
		ret = -1;
		goto exit;
	}

	buffer = (unsigned char *)malloc(U_BOOT_SIZE);
	if (!buffer) {
		printf("Allocate memory failed\n");
		ret = -2;
		goto exit;
	}
	memset(buffer, 0, U_BOOT_SIZE);

	fStream = fopen(argv[1], "rb");
	if (!fStream) {
		printf("Open file %s fail\n", argv[1]);
		ret = -3;
		goto free_memory;
	}

	orig_size = fread(buffer, 1, U_BOOT_SIZE, fStream);
	fclose(fStream);

// Add first 8K checksum for smdkc11 
	int i;
	char *p;
	unsigned int	checksum;
	p = buffer + 16;
	for(i = 0, checksum = 0; i < U_BOOT0_SIZE - 16; i++)
		checksum += (0x000000FF) & *p++;

	p = buffer + 8;	
	*( (unsigned int *)p ) = checksum;

//  memcpy(buffer + orig_size, buffer, U_BOOT_SIZE - orig_size); 
	crc = crc32(0, buffer, U_BOOT_SIZE - sizeof(crc));
	printf("CRC is 0x%x\n", crc);
	memcpy(buffer + U_BOOT_SIZE - sizeof(crc), &crc, sizeof(crc));
	fStream = fopen("u-boot-256KB.bin", "wb");
	if (!fStream) {
		printf("Create u-boot-256KB.bin failed\n");
		ret = -4;
		goto free_memory;
	}

	fwrite(buffer, 1, U_BOOT_SIZE, fStream);
	fclose(fStream);

  free_memory:
	free(buffer);
  exit:
	return ret;
}
