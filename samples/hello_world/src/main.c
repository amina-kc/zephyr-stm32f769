/*
 * Copyright (c) 2012-2014 Wind River Systems, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr.h>
#include <sys/printk.h>
#include <display/stm32f7-otm8009a.h>

void main(void)
{ 


	BSP_LCD_Init();
	printk("lcd init! \n");

        BSP_LCD_LayerDefaultInit(1, LCD_FB_START_ADDRESS);

  	BSP_LCD_SelectLayer(1);
  	printk("lcd select layer! \n"); 

	BSP_LCD_SetBackColor(LCD_COLOR_WHITE); 
	printk("set backcolor! \n");

  	BSP_LCD_Clear(LCD_COLOR_WHITE);
	printk("lcd clear! \n");

 	BSP_LCD_SetTextColor(LCD_COLOR_DARKBLUE);  
	printk("set text color! \n");

  	BSP_LCD_DisplayStringAt(0, 10, (uint8_t *)"STM32F769I HELLO LCD", CENTER_MODE);
	printk("done! \n");

	while(1);

}
