/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialised, but the project is compiling for an FPU. Please initialise the FPU before use."
#endif

int main(void)
{
	//__asm volatile (code : output operand list : input operand list : clobber list);
	//In this code we are learning to use "code, input operand list, output operand list" sections of above syntax.
	int val=5;
	__asm volatile("MOV R0,%0": :"r"(val));  //"r" register constraint modifier
	__asm volatile("MOV R4,%0": :"i"(0x50)); //"i" immediate constraint modifier

	//Move value of CONTROL register to a variable control_reg using inline assembly code.
	int control_reg;
	__asm volatile("MRS %0,CONTROL": "=r"(control_reg): : );
	__asm volatile("MOV R1,%0": : "r"(control_reg): );

	//Move value of val1 to val2 using inline assembly code.
	int val1=5,val2;
	__asm volatile("MOV %0,%1": "=r"(val2): "r"(val1): );
	__asm volatile("MOV R7,%0": :"r"(val2): );
}