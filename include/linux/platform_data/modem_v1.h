/*
 * Copyright (C) 2012 Samsung Electronics.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#ifndef __MODEM_V1_H__
#define __MODEM_V1_H__

#include <linux/platform_device.h>
#include <linux/miscdevice.h>
#include <linux/types.h>

#ifdef CONFIG_LINK_DEVICE_SHMEM
#include <mach/shdmem.h>
#include <mach/pmu.h>
#endif

enum modem_t {
	IMC_XMM6260,
	IMC_XMM6262,
	VIA_CBP71,
	VIA_CBP72,
	VIA_CBP82,
	SEC_CMC220,
	SEC_CMC221,
	SEC_SS222,
	SEC_SH222AP,
	QC_MDM6600,
	QC_ESC6270,
	QC_QSC6085,
	SPRD_SC8803,
	DUMMY,
	MAX_MODEM_TYPE
};

enum dev_format {
	IPC_FMT,
	IPC_RAW,
	IPC_RFS,
	IPC_MULTI_RAW,
	IPC_CMD,
	IPC_BOOT,
	IPC_RAMDUMP,
	IPC_DEBUG,
	MAX_DEV_FORMAT,
};
#define MAX_IPC_DEV	(IPC_RFS + 1)	/* FMT, RAW, RFS */
#define MAX_SIPC5_DEV	(IPC_RAW + 1)	/* FMT, RAW */

enum modem_io {
	IODEV_MISC,
	IODEV_NET,
	IODEV_DUMMY,
};

enum modem_link {
	LINKDEV_UNDEFINED,
	LINKDEV_MIPI,
	LINKDEV_USB,
	LINKDEV_HSIC,
	LINKDEV_DPRAM,
	LINKDEV_PLD,
	LINKDEV_C2C,
	LINKDEV_SHMEM,
	LINKDEV_SPI,
	LINKDEV_MAX
};
#define LINKTYPE(modem_link) (1u << (modem_link))

enum modem_network {
	UMTS_NETWORK,
	CDMA_NETWORK,
	TDSCDMA_NETWORK,
	LTE_NETWORK,
	MAX_MODEM_NETWORK
};

enum sipc_ver {
	NO_SIPC_VER = 0,
	SIPC_VER_40 = 40,
	SIPC_VER_41 = 41,
	SIPC_VER_42 = 42,
	SIPC_VER_50 = 50,
	MAX_SIPC_VER
};

enum sipc_ch_id {
	SIPC_CH_ID_RAW_0 = 0,	/*reserved*/
	SIPC_CH_ID_CS_VT_DATA,
	SIPC_CH_ID_CS_VT_CONTROL,
	SIPC_CH_ID_CS_VT_AUDIO,
	SIPC_CH_ID_CS_VT_VIDEO,
	SIPC_CH_ID_RAW_5,	/*reserved*/
	SIPC_CH_ID_RAW_6,	/*reserved*/
	SIPC_CH_ID_CDMA_DATA,
	SIPC_CH_ID_PCM_DATA,
	SIPC_CH_ID_TRANSFER_SCREEN,

	SIPC_CH_ID_PDP_0 = 10,	/*ID:10*/
	SIPC_CH_ID_PDP_1,
	SIPC_CH_ID_PDP_2,
	SIPC_CH_ID_PDP_3,
	SIPC_CH_ID_PDP_4,
	SIPC_CH_ID_PDP_5,
	SIPC_CH_ID_PDP_6,
	SIPC_CH_ID_PDP_7,
	SIPC_CH_ID_PDP_8,
	SIPC_CH_ID_PDP_9,
	SIPC_CH_ID_PDP_10,
	SIPC_CH_ID_PDP_11,
	SIPC_CH_ID_PDP_12,
	SIPC_CH_ID_PDP_13,
	SIPC_CH_ID_PDP_14,
	SIPC_CH_ID_BT_DUN,	/*ID:25*/
	SIPC_CH_ID_CIQ_DATA,
	SIPC_CH_ID_PDP_17,	/*reserved*/
	SIPC_CH_ID_CPLOG1,	/*ID:28*/
	SIPC_CH_ID_CPLOG2,	/*ID:29*/
	SIPC_CH_ID_LOOPBACK1,	/*ID:30*/
	SIPC_CH_ID_LOOPBACK2,	/*ID:31*/

	/* 32 ~ 214 is reserved */

	SIPC5_CH_ID_BOOT_0 = 215,
	SIPC5_CH_ID_BOOT_1,
	SIPC5_CH_ID_BOOT_2,
	SIPC5_CH_ID_BOOT_3,
	SIPC5_CH_ID_BOOT_4,
	SIPC5_CH_ID_BOOT_5,
	SIPC5_CH_ID_BOOT_6,
	SIPC5_CH_ID_BOOT_7,
	SIPC5_CH_ID_BOOT_8,
	SIPC5_CH_ID_BOOT_9,

	SIPC5_CH_ID_DUMP_0 = 225,
	SIPC5_CH_ID_DUMP_1,
	SIPC5_CH_ID_DUMP_2,
	SIPC5_CH_ID_DUMP_3,
	SIPC5_CH_ID_DUMP_4,
	SIPC5_CH_ID_DUMP_5,
	SIPC5_CH_ID_DUMP_6,
	SIPC5_CH_ID_DUMP_7,
	SIPC5_CH_ID_DUMP_8,
	SIPC5_CH_ID_DUMP_9,

	SIPC5_CH_ID_FMT_0 = 235,
	SIPC5_CH_ID_FMT_1,
	SIPC5_CH_ID_FMT_2,
	SIPC5_CH_ID_FMT_3,
	SIPC5_CH_ID_FMT_4,
	SIPC5_CH_ID_FMT_5,
	SIPC5_CH_ID_FMT_6,
	SIPC5_CH_ID_FMT_7,
	SIPC5_CH_ID_FMT_8,
	SIPC5_CH_ID_FMT_9,

	SIPC5_CH_ID_RFS_0 = 245,
	SIPC5_CH_ID_RFS_1,
	SIPC5_CH_ID_RFS_2,
	SIPC5_CH_ID_RFS_3,
	SIPC5_CH_ID_RFS_4,
	SIPC5_CH_ID_RFS_5,
	SIPC5_CH_ID_RFS_6,
	SIPC5_CH_ID_RFS_7,
	SIPC5_CH_ID_RFS_8,
	SIPC5_CH_ID_RFS_9,

	SIPC5_CH_ID_FLOW_CTRL = 255
};

#define STR_CP_FAIL	"cp_fail"
#define STR_CP_WDT	"cp_wdt"	/* CP watchdog timer */

/**
 * struct modem_io_t - declaration for io_device
 * @name:	device name
 * @id:		for SIPC4, contains format & channel information
 *		(id & 11100000b)>>5 = format  (eg, 0=FMT, 1=RAW, 2=RFS)
 *		(id & 00011111b)    = channel (valid only if format is RAW)
 *		for SIPC5, contains only 8-bit channel ID
 * @format:	device format
 * @io_type:	type of this io_device
 * @links:	list of link_devices to use this io_device
 *		for example, if you want to use DPRAM and USB in an io_device.
 *		.links = LINKTYPE(LINKDEV_DPRAM) | LINKTYPE(LINKDEV_USB)
 * @tx_link:	when you use 2+ link_devices, set the link for TX.
 *		If define multiple link_devices in @links,
 *		you can receive data from them. But, cannot send data to all.
 *		TX is only one link_device.
 * @app:	the name of the application that will use this IO device
 *
 * This structure is used in board-*-modems.c
 */
struct modem_io_t {
	char *name;
	unsigned int id;
	enum dev_format format;
	enum modem_io io_type;
	enum modem_link links;
	enum modem_link tx_link;
	char *app;
};

struct modemlink_pm_data {
	char *name;
	/* link power contol 2 types : pin & regulator control */
	int (*link_ldo_enable)(bool);
	unsigned int gpio_link_enable;
	unsigned int gpio_link_active;
	unsigned int gpio_link_hostwake;
	unsigned int gpio_link_slavewake;
	int (*link_reconnect)(void);

	/* usb hub only */
	int (*port_enable)(int, int);
	int (*hub_standby)(void *);
	void *hub_pm_data;
	bool has_usbhub;

	/* cpu/bus frequency lock */
	atomic_t freqlock;
	int (*freq_lock)(struct device *dev);
	int (*freq_unlock)(struct device *dev);

	int autosuspend_delay_ms; /* if zero, the default value is used */
	void (*ehci_reg_dump)(struct device *);
};

struct modemlink_pm_link_activectl {
	int gpio_initialized;
	int gpio_request_host_active;
};

#ifdef CONFIG_LINK_DEVICE_SHMEM
enum shmem_type {
	REAL_SHMEM,
	C2C_SHMEM,
	MAX_SHMEM_TYPE
};

struct modem_mbox {
	unsigned int mbx_ap2cp_msg;
	unsigned int mbx_cp2ap_msg;
	unsigned int mbx_ap2cp_active;	/* PDA_ACTIVE	*/
	unsigned int mbx_cp2ap_active;	/* PHONE_ACTIVE	*/
	unsigned int mbx_ap2cp_wakeup;	/* CP_WAKEUP	*/
	unsigned int mbx_cp2ap_wakeup;	/* AP_WAKEUP	*/
	unsigned int mbx_ap2cp_status;	/* AP_STATUS	*/
	unsigned int mbx_cp2ap_status;	/* CP_STATUS	*/

	unsigned int int_ap2cp_msg;
	unsigned int int_ap2cp_active;
	unsigned int int_ap2cp_wakeup;
	unsigned int int_ap2cp_status;

	unsigned int irq_cp2ap_msg;
	unsigned int irq_cp2ap_active;
	unsigned int irq_cp2ap_wakeup;
	unsigned int irq_cp2ap_status;

	/* Performance request */
	unsigned int mbx_ap2cp_perf_req;
	unsigned int mbx_cp2ap_perf_req;

	unsigned int int_ap2cp_perf_req;
	unsigned int irq_cp2ap_perf_req;

	/* System (H/W) revision */
	unsigned int mbx_ap2cp_sys_rev;
	unsigned int mbx_ap2cp_pmic_rev;
	unsigned int mbx_ap2cp_pkg_id;
};

struct modem_pmu {
	int (*power)(enum cp_mode mode);
	int (*get_pwr_status)(void);
	int (*stop)(void);
	int (*start)(void);
	int (*clear_cp_fail)(void);
	int (*clear_cp_wdt)(void);
};
#endif

/* platform data */
struct modem_data {
	char *name;

	unsigned int gpio_cp_on;
	unsigned int gpio_cp_off;
	unsigned int gpio_reset_req_n;
	unsigned int gpio_cp_reset;

	/* for broadcasting AP's PM state (active or sleep) */
	unsigned int gpio_pda_active;

	/* for checking aliveness of CP */
	unsigned int gpio_phone_active;
	unsigned int irq_phone_active;

	/* for AP-CP IPC interrupt */
	unsigned int gpio_ipc_int2ap;
	unsigned int irq_ipc_int2ap;
	unsigned long irqf_ipc_int2ap;	/* IRQ flags */
	unsigned int gpio_ipc_int2cp;

	/* for AP-CP power management (PM) handshaking */
	unsigned int gpio_ap_wakeup;
	unsigned int irq_ap_wakeup;
	unsigned int gpio_ap_status;
	unsigned int gpio_cp_wakeup;
	unsigned int gpio_cp_status;
	unsigned int irq_cp_status;

	/* for USB/HSIC PM */
	unsigned int gpio_host_wakeup;
	unsigned int irq_host_wakeup;
	unsigned int gpio_host_active;
	unsigned int gpio_slave_wakeup;

	unsigned int gpio_cp_dump_int;
	unsigned int gpio_ap_dump_int;
	unsigned int gpio_flm_uart_sel;
	unsigned int gpio_cp_warm_reset;

	unsigned int gpio_sim_detect;
	unsigned int irq_sim_detect;

#ifdef CONFIG_LINK_DEVICE_SHMEM
	unsigned int sys_rev;
	unsigned int pmic_rev;
	unsigned int pkg_id;
	struct modem_mbox *mbx;
	struct modem_pmu *pmu;
#endif

	/* Switch with 2 links in a modem */
	unsigned int gpio_link_switch;

	/* Modem component */
	enum modem_network modem_net;
	enum modem_t modem_type;
	enum modem_link link_types;
	char *link_name;

	/* SIPC version */
	enum sipc_ver ipc_version;

	/* the number of real IPC devices -> (IPC_RAW + 1) or (IPC_RFS + 1) */
	unsigned int max_ipc_dev;

	/* Information of IO devices */
	unsigned int num_iodevs;
	struct modem_io_t *iodevs;

	/* Modem link PM support */
	struct modemlink_pm_data *link_pm_data;

	/* Handover with 2+ modems */
	bool use_handover;

	/* SIM Detect polarity */
	bool sim_polarity;

	void (*gpio_revers_bias_clear)(void);
	void (*gpio_revers_bias_restore)(void);
};

#define MODEM_BOOT_DEV_SPI "modem_boot_spi"

struct modem_boot_spi_platform_data {
	const char *name;
	unsigned int gpio_cp_status;
};

struct modem_boot_spi {
	struct miscdevice dev;
	struct spi_device *spi_dev;
	struct mutex lock;
	unsigned int gpio_cp_status;
};
#define to_modem_boot_spi(misc)	container_of(misc, struct modem_boot_spi, dev);

#define LOG_TAG	"mif: "
#define CALLEE	(__func__)
#define CALLER	(__builtin_return_address(0))

#define mif_err_limited(fmt, ...) \
	printk_ratelimited(KERN_ERR LOG_TAG "%s: " pr_fmt(fmt), __func__, ##__VA_ARGS__)
#define mif_err(fmt, ...) \
	pr_err(LOG_TAG "%s: " pr_fmt(fmt), __func__, ##__VA_ARGS__)
#define mif_debug(fmt, ...) \
	pr_debug(LOG_TAG "%s: " pr_fmt(fmt), __func__, ##__VA_ARGS__)
#define mif_info(fmt, ...) \
	pr_info(LOG_TAG "%s: " pr_fmt(fmt), __func__, ##__VA_ARGS__)
#define mif_trace(fmt, ...) \
	printk(KERN_DEBUG "mif: %s: %d: called(%pF): " fmt, \
		__func__, __LINE__, __builtin_return_address(0), ##__VA_ARGS__)

#endif
