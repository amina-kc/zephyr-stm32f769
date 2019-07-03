/*
 * Copyright (c) 2019 Amina Kacem <aminakacem.isitcom@gmail.com>
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#ifndef ZEPHYR_DRIVERS_DISPLAY_DISPLAY_OTM8009A_H_
#define ZEPHYR_DRIVERS_DISPLAY_DISPLAY_OTM8009A_H_

#include <zephyr.h>

#define OTM8009A_CMD_ENTER_SLEEP 0x10
#define OTM8009A_CMD_EXIT_SLEEP 0x11
#define OTM8009A_CMD_GAMMA_SET 0x26
#define OTM8009A_CMD_DISPLAY_OFF 0x28
#define OTM8009A_CMD_DISPLAY_ON 0x29
#define OTM8009A_CMD_COLUMN_ADDR 0x2a
#define OTM8009A_CMD_PAGE_ADDR 0x2b
#define OTM8009A_CMD_MEM_WRITE 0x2c
#define OTM8009A_CMD_MEM_ACCESS_CTRL 0x36
#define OTM8009A_CMD_PIXEL_FORMAT_SET 0x3A
#define OTM8009A_CMD_FRAME_CTRL_NORMAL_MODE 0xB1
#define OTM8009A_CMD_DISPLAY_FUNCTION_CTRL 0xB6
#define OTM8009A_CMD_POWER_CTRL_1 0xC0
#define OTM8009A_CMD_POWER_CTRL_2 0xC1
#define OTM8009A_CMD_VCOM_CTRL_1 0xC5
#define OTM8009A_CMD_VCOM_CTRL_2 0xC7
#define OTM8009A_CMD_POSITVE_GAMMA_CORRECTION 0xE0
#define OTM8009A_CMD_NEGATIVE_GAMMA_CORRECTION 0xE1

#define OTM8009A_DATA_MEM_ACCESS_CTRL_MY 0x80
#define OTM8009A_DATA_MEM_ACCESS_CTRL_MX 0x40
#define OTM8009A_DATA_MEM_ACCESS_CTRL_MV 0x20
#define OTM8009A_DATA_MEM_ACCESS_CTRL_ML 0x10
#define OTM8009A_DATA_MEM_ACCESS_CTRL_BGR 0x08
#define OTM8009A_DATA_MEM_ACCESS_CTRL_MH 0x04

#define OTM8009A_DATA_PIXEL_FORMAT_RGB_18_BIT 0x60
#define OTM8009A_DATA_PIXEL_FORMAT_RGB_16_BIT 0x50
#define OTM8009A_DATA_PIXEL_FORMAT_MCU_18_BIT 0x06
#define OTM8009A_DATA_PIXEL_FORMAT_MCU_16_BIT 0x05

struct otm8009a_data;

/**
 * Send data to OTM8009A display controller
 *
 * @param data Device data structure
 * @param cmd Command to send to display controller
 * @param tx_data Data to transmit to the display controller
 * In case no data should be transmitted pass a NULL pointer
 * @param tx_len Number of bytes in tx_data buffer
 *
 */
//void lcd_init();
void init_test();
void otm8009a_transmit(struct otm8009a_data *data, u8_t cmd, void *tx_data,
		      size_t tx_len);

/**
 * Perform LCD specific initialization
 *
 * @param data Device data structure
 */
void otm8009a_lcd_init(struct otm8009a_data *data);

#endif /* ZEPHYR_DRIVERS_DISPLAY_DISPLAY_OTM8009A_H_ */
