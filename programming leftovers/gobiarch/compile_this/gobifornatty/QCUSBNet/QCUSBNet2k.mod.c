#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
 .name = KBUILD_MODNAME,
 .init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
 .exit = cleanup_module,
#endif
 .arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x5bdd7527, "module_layout" },
	{ 0x9f99e118, "cdev_del" },
	{ 0x6361d76c, "kmalloc_caches" },
	{ 0x5a34a45c, "__kmalloc" },
	{ 0x506fd344, "cdev_init" },
	{ 0xf9a482f9, "msleep" },
	{ 0xb85f3bbe, "pv_lock_ops" },
	{ 0xebc19e25, "usbnet_resume" },
	{ 0xb4f97065, "usbnet_probe" },
	{ 0xf1d038e9, "usbnet_disconnect" },
	{ 0xab4e3332, "netif_carrier_on" },
	{ 0x20000329, "simple_strtoul" },
	{ 0x670c0597, "down_interruptible" },
	{ 0x52a39049, "netif_carrier_off" },
	{ 0x9ebc3ec3, "usb_kill_urb" },
	{ 0x2b514126, "device_destroy" },
	{ 0x2fa60949, "filp_close" },
	{ 0x677bb305, "param_ops_bool" },
	{ 0x83a47c3d, "usb_autopm_get_interface" },
	{ 0x7485e15e, "unregister_chrdev_region" },
	{ 0x7d11c268, "jiffies" },
	{ 0xe174aa7, "__init_waitqueue_head" },
	{ 0x4f8b5ddb, "_copy_to_user" },
	{ 0xde0bdcff, "memset" },
	{ 0x11089ac7, "_ctype" },
	{ 0x88941a06, "_raw_spin_unlock_irqrestore" },
	{ 0x237860ef, "current_task" },
	{ 0x6bf8d133, "down_trylock" },
	{ 0xfd2a74a9, "usb_deregister" },
	{ 0x27e1a049, "printk" },
	{ 0x3557b322, "usb_set_interface" },
	{ 0xb10ec686, "wait_for_completion_interruptible" },
	{ 0xa1c76e0a, "_cond_resched" },
	{ 0xb4390f9a, "mcount" },
	{ 0xf03b89ad, "usb_control_msg" },
	{ 0x1e6d26a8, "strstr" },
	{ 0xc0b6d671, "device_create" },
	{ 0x8cc3cb04, "usbnet_suspend" },
	{ 0xebe5c5e2, "dev_kfree_skb_any" },
	{ 0xe082240d, "cdev_add" },
	{ 0x8b5add80, "init_task" },
	{ 0x1dff1bb8, "usb_submit_urb" },
	{ 0xf0fdf6cb, "__stack_chk_fail" },
	{ 0x6b2dc060, "dump_stack" },
	{ 0x6e513552, "wake_up_process" },
	{ 0xa88e3dd, "kmem_cache_alloc_trace" },
	{ 0x6443d74d, "_raw_spin_lock" },
	{ 0x587c70d8, "_raw_spin_lock_irqsave" },
	{ 0x37a0cba, "kfree" },
	{ 0xf2e4ac3c, "kthread_create" },
	{ 0x236c8c64, "memcpy" },
	{ 0x57b09822, "up" },
	{ 0xddca35e5, "usb_register_driver" },
	{ 0xc84e8d97, "class_destroy" },
	{ 0x5e09ca75, "complete" },
	{ 0x9edbecae, "snprintf" },
	{ 0x4f6b400b, "_copy_from_user" },
	{ 0xd6c132c7, "__class_create" },
	{ 0xa7586379, "dev_get_drvdata" },
	{ 0xa0c9742e, "usb_free_urb" },
	{ 0x29537c9e, "alloc_chrdev_region" },
	{ 0x620b5df0, "usb_autopm_put_interface" },
	{ 0x31963523, "usb_alloc_urb" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=usbnet";

MODULE_ALIAS("usb:v05C6p9215d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v05C6p9265d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v16D8p8002d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v413Cp8186d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v1410pA010d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v1410pA011d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v1410pA012d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v1410pA013d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v03F0p251Dd*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v05C6p9205d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v05C6p920Bd*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v04DAp250Fd*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v05C6p9245d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v1199p9001d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v1199p9002d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v1199p9003d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v1199p9004d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v1199p9005d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v1199p9006d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v1199p9007d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v1199p9008d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v1199p9009d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v1199p900Ad*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v05C6p9225d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v05C6p9235d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v05C6p9275d*dc*dsc*dp*ic*isc*ip*");

MODULE_INFO(srcversion, "FBF628D1501FF7E92715FB7");
