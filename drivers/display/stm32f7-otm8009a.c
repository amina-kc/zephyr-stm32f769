#include "stm32f7-otm8009a.h"
#include <display.h>

#define LOG_LEVEL CONFIG_DISPLAY_LOG_LEVEL
#include <logging/log.h>
LOG_MODULE_REGISTER(display_otm8009a);

#include <gpio.h>
#include <misc/byteorder.h>
#include <string.h>
#include <misc/printk.h>

#define LED_PORT LED0_GPIO_CONTROLLER
#define LED	LED0_GPIO_PIN
#define SLEEP_TIME 	2000
int cnt = 0;
struct otm8009a_data {
    struct device *reset_gpio;
};

void init_test(){
struct device *dev;
dev = device_get_binding(LED_PORT);
/* Set LED pin as output */
gpio_pin_configure(dev, LED, GPIO_DIR_OUT);
//printk("configure terminated\n\r");

while (1) {
gpio_pin_write(dev, LED, cnt % 2);
cnt++;
k_sleep(SLEEP_TIME);
}

}
/*
void lcd_init()
{
printk("Hello AMINA!\n");
}*/

static int otm8009a_init(struct device *dev)
{
    printk("Hello AMINA kc!\n");
    return 0;
}



static int otm8009a_write(const struct device *dev, const u16_t x,
			 const u16_t y,
			 const struct display_buffer_descriptor *desc,
			 const void *buf)
{
    return 0;
}

static int otm8009a_read(const struct device *dev, const u16_t x,
			const u16_t y,
			const struct display_buffer_descriptor *desc,
			void *buf)
{
    return 0;
}

static void *otm8009a_get_framebuffer(const struct device *dev)
{
    return (void*)0xc0000000;
}

static int otm8009a_display_blanking_off(const struct device *dev)
{
    return 0;
}

static int otm8009a_display_blanking_on(const struct device *dev)
{
    return 0;
}

static int otm8009a_set_brightness(const struct device *dev,
				  const u8_t brightness)
{
    return 0;
}

static int otm8009a_set_contrast(const struct device *dev, const u8_t contrast)
{
    return 0;
}

static int otm8009a_set_pixel_format(const struct device *dev,
				    const enum display_pixel_format
				    pixel_format)
{
    return 0;	
}

static int otm8009a_set_orientation(const struct device *dev,
				   const enum display_orientation orientation)
{
    return 0;	
}

static void otm8009a_get_capabilities(const struct device *dev,
				     struct display_capabilities *capabilities)
{
}

static const struct display_driver_api otm8009a_api = {
	.blanking_on = otm8009a_display_blanking_on,
	.blanking_off = otm8009a_display_blanking_off,
	.write = otm8009a_write,
	.read = otm8009a_read,
	.get_framebuffer = otm8009a_get_framebuffer,
	.set_brightness = otm8009a_set_brightness,
	.set_contrast = otm8009a_set_contrast,
	.get_capabilities = otm8009a_get_capabilities,
	.set_pixel_format = otm8009a_set_pixel_format,
	.set_orientation = otm8009a_set_orientation,
};

static struct otm8009a_data otm8009a_data;

DEVICE_AND_API_INIT(otm8009a, 0, &otm8009a_init,
		    &otm8009a_data, NULL, APPLICATION,
		    CONFIG_APPLICATION_INIT_PRIORITY, &otm8009a_api);
