/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2022-03-29     shelton      first version
 */

#ifndef __DRV_QSPI_H__
#define __DRV_QSPI_H__

#include <rtthread.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifdef BSP_USING_QSPI1
#define QSPI1_BUS_CONFIG                                       \
    {                                                          \
        .qspi_x                 = QSPI1,                       \
        .bus_name               = "qspi1",                     \
    }
#endif /* BSP_USING_QSPI1 */

#ifdef BSP_USING_QSPI2
#define QSPI2_BUS_CONFIG                                       \
    {                                                          \
        .qspi_x                 = QSPI2,                       \
        .bus_name               = "qspi2",                     \
    }
#endif /* BSP_USING_QSPI2 */

rt_err_t rt_hw_qspi_device_attach(const char *bus_name, const char *device_name, rt_base_t cs_pin, rt_uint8_t data_line_width, void (*enter_qspi_mode)(), void (*exit_qspi_mode)());

#ifdef __cplusplus
}
#endif

#endif /* __DRV_QSPI_H__ */
