/*
 * Copyright (c) 2012-2014 Wind River Systems, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr.h>
#include <misc/printk.h>

struct k_delayed_work dw;

void work_handler(struct k_work *w)
{
	k_delayed_work_submit(&dw, 10);
}

void main(void)
{
	printk("Hello World! %s\n", CONFIG_BOARD);

	k_delayed_work_init(&dw, work_handler);
	k_delayed_work_submit(&dw, K_NO_WAIT);

	while (1) {
		k_sleep(K_SECONDS(1));
	}
}
