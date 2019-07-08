#include "stm32f7-otm8009a.h"
// #include "stm32f7xx_hal.h"
// #include <stm32f7xx.h>
// #include <stm32f7xx_hal_cortex.h>
// #include <stm32f769i_discovery.h>
// #include <stm32f769i_discovery_lcd.h>
// #include <stm32f769i_discovery_sdram.h>
// #include <display.h>

#define LOG_LEVEL CONFIG_DISPLAY_LOG_LEVEL
#include <logging/log.h>
LOG_MODULE_REGISTER(display_otm8009a);

#include <gpio.h>
#include <misc/byteorder.h>
#include <string.h>
#include <misc/printk.h>

#include <device.h>

/* end include */


struct otm8009a_data {

	struct device *reset_gpio;
	struct device *command_data_gpio;
};

static int otm8009a_init(struct device *dev)
{
	struct otm8009a_data *data = (struct otm8009a_data *)dev->driver_data;

	printk("Initializing display otm8009a driver\n");

	data->reset_gpio = device_get_binding(DT_ALIAS_OTMRESET_GPIOS_CONTROLLER);
	if (data->reset_gpio == NULL) {
		LOG_ERR("Could not get GPIO port for OTM8009A reset");
		return -EPERM;
	}

	printk("get gpio binding\n");

	gpio_pin_configure(data->reset_gpio,DT_ALIAS_OTMRESET_GPIO_PIN, GPIO_DIR_OUT);
	printk("pin configured\n");

	gpio_pin_write(data->reset_gpio, DT_ALIAS_OTMRESET_GPIO_PIN, 0);
	printk("pin wrote 0\n");

	k_sleep(10);

	gpio_pin_write(data->reset_gpio, DT_ALIAS_OTMRESET_GPIO_PIN, 1);
	printk("pin wrote 1 \n");

	printk("done\n");

	return 0;

}


struct otm8009a_data otma ;
struct device dev;

void test_func(void)
{
dev.driver_data = &otma;

uint8_t x = otm8009a_init(&dev);

printk("retval = %d\n",x);
printk("hello world\n");
}






