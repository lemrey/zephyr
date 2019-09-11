/*
 * Copyright (c) 2012-2014 Wind River Systems, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr.h>
#include <sys/printk.h>

static struct k_delayed_work dwork;

void work_item(struct k_work *w)
{
	printk("That wasn't 20 hours..\n");
	/* k_delayed_work_submit(&dwork, K_HOURS(20)); */
}

void main(void)
{
	int err;

	printk("Hello World! %s\n", CONFIG_BOARD);

	k_delayed_work_init(&dwork, work_item);

	err = k_delayed_work_submit(&dwork, K_HOURS(20));
	if (err) {
		printk("k_delayed_work_submit(), err %d", err);
	}
}
