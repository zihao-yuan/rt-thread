/*
 * Copyright (C) 2022-2024, Xiaohua Semiconductor Co., Ltd.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2022-04-28     CDT          first version
 */

#include <rtthread.h>
#include <rtdevice.h>
#include <board.h>

/* defined the LED_GREEN pin: PC9 */
#define LED_GREEN_PIN GET_PIN(B, 2)


int main(void)
{
    /* set LED_GREEN_PIN pin mode to output */
    rt_pin_mode(LED_GREEN_PIN, PIN_MODE_OUTPUT);

    while (1)
    {
        rt_pin_write(LED_GREEN_PIN, PIN_HIGH);
        rt_thread_mdelay(500);
        rt_pin_write(LED_GREEN_PIN, PIN_LOW);
        rt_thread_mdelay(500);
    }
}



/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date Author Notes
 * 2018-11-29 misonyo first implementation.
 */
/*
 * ????: ADC ??????
 * ????? adc_sample ???????
 * ??????:adc_sample
 * ????:?? ADC ??????????????
 * ?????????3.3V,????12??
*/
#include <rtthread.h>rt thread  adc
#include <rtdevice.h>
#define ADC_DEV_NAME "adc1" /* ADC ???? */
#define ADC_DEV_CHANNEL 10 /* ADC ?? */
static int adc_vol_sample(int argc, char *argv[])
{
 rt_adc_device_t adc_dev;
 rt_uint32_t value, vol;
 rt_err_t ret = RT_EOK;
	
//	ADC_SetExtChSrc(CM_ADC1,ADC_EXTCH_INTERN_ANALOG_SRC);
 /* ???? */
 adc_dev = (rt_adc_device_t)rt_device_find(ADC_DEV_NAME);
 if (adc_dev == RT_NULL)
 {
 rt_kprintf("adc sample run failed! can't find %s device!\n", ADC_DEV_NAME);
 return RT_ERROR;
 }
 /* ???? */
 ret = rt_adc_enable(adc_dev, ADC_DEV_CHANNEL);
 /* ????? */
 value = rt_adc_read(adc_dev, ADC_DEV_CHANNEL);
 rt_kprintf("the value is :%d \n", value);
 /* ????????,3.3V??12????4096,??????100??2??? */
 vol = value * 330 / 4096;
 rt_kprintf("the voltage is :%d.%02d \n", vol / 100, vol % 100);
 /* ???? */
 ret = rt_adc_disable(adc_dev, ADC_DEV_CHANNEL);
 return ret;
}
/* ??? msh ????? */
MSH_CMD_EXPORT(adc_vol_sample, adc voltage convert sample);
