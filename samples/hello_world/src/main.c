/*
 * Copyright (c) 2012-2014 Wind River Systems, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr.h>
#include <sys/printk.h>
//#include <stm32f769i_discovery.h>
//#include <stm32f769i_discovery_lcd.h>
//#include <stm32f769i_discovery_sdram.h>
#include <display/stm32f7-otm8009a.h>

void main(void)
{ 

test_func();


while(1);

	//printk("Hello World! %s\n", CONFIG_BOARD);
	//init_test();
/*
  BSP_LCD_Init();
  BSP_LCD_LayerDefaultInit(1, LCD_FB_START_ADDRESS);
  
  
  BSP_LCD_SelectLayer(1);

  BSP_LCD_SetFont(&LCD_DEFAULT_FONT);
  
  
  BSP_LCD_SetBackColor(LCD_COLOR_WHITE); 
  BSP_LCD_Clear(LCD_COLOR_WHITE);


  BSP_LCD_SetTextColor(LCD_COLOR_DARKBLUE);  


  BSP_LCD_DisplayStringAt(0, 10, (uint8_t *)"STM32F769I HELLO lcd", CENTER_MODE);
*/
}
