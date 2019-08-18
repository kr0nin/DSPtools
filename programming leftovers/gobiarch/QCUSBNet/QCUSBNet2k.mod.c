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
	{ 0x5e74aae9, "module_layout" },
	{ 0x48ba2ede, "cdev_del" },
	{ 0x70b38806, "kmalloc_caches" },
	{ 0x5a34a45c, "__kmalloc" },
	{ 0x4fcf8715, "cdev_init" },
	{ 0xf9a482f9, "msleep" },
	{ 0x2b200864, "_raw_spin_unlock" },
	{ 0x63583b70, "usbnet_resume" },
	{ 0x1baf5ce2, "usbnet_probe" },
	{ 0x53b5f043, "usbnet_disconnect" },
	{ 0xb6f9e0df, "netif_carrier_on" },
	{ 0x20000329, "simple_strtoul" },
	{ 0x670c0597, "down_interruptible" },
	{ 0x9dd922eb, "netif_carrier_off" },
	{ 0xa2607fcb, "usb_kill_urb" },
	{ 0x62654b6f, "device_destroy" },
	{ 0x415524c6, "filp_close" },
	{ 0xb78c61e8, "param_ops_bool" },
	{ 0x2d865dd7, "usb_autopm_get_interface" },
	{ 0x7485e15e, "unregister_chrdev_region" },
	{ 0xf079b2bd, "kthread_create_on_node" },
	{ 0x7d11c268, "jiffies" },
	{ 0xe174aa7, "__init_waitqueue_head" },
	{ 0x4f8b5ddb, "_copy_to_user" },
	{ 0xde0bdcff, "memset" },
	{ 0x11089ac7, "_ctype" },
	{ 0x88941a06, "_raw_spin_unlock_irqrestore" },
	{ 0x5711f75, "current_task" },
	{ 0x6bf8d133, "down_trylock" },
	{ 0x622b4107, "usb_deregister" },
	{ 0x27e1a049, "printk" },
	{ 0xa1349907, "usb_set_interface" },
	{ 0xb10ec686, "wait_for_completion_interruptible" },
	{ 0xb4390f9a, "mcount" },
	{ 0xf8142945, "usb_control_msg" },
	{ 0x1e6d26a8, "strstr" },
	{ 0x1bacc7f7, "device_create" },
	{ 0x2469810f, "__rcu_read_unlock" },
	{ 0x6d39188b, "usbnet_suspend" },
	{ 0x257f581a, "dev_kfree_skb_any" },
	{ 0xb8d52224, "cdev_add" },
	{ 0xff49d477, "init_task" },
	{ 0x353c7491, "usb_submit_urb" },
	{ 0x6b2dc060, "dump_stack" },
	{ 0x217b66e6, "wake_up_process" },
	{ 0xd7a575d5, "kmem_cache_alloc_trace" },
	{ 0x6443d74d, "_raw_spin_lock" },
	{ 0x587c70d8, "_raw_spin_lock_irqsave" },
	{ 0x37a0cba, "kfree" },
	{ 0x236c8c64, "memcpy" },
	{ 0x57b09822, "up" },
	{ 0xa07ac1e8, "usb_register_driver" },
	{ 0x8e98480c, "class_destroy" },
	{ 0x5e09ca75, "complete" },
	{ 0x9edbecae, "snprintf" },
	{ 0x8d522714, "__rcu_read_lock" },
	{ 0x4f6b400b, "_copy_from_user" },
	{ 0x2472955e, "__class_create" },
	{ 0x40cb9be8, "dev_get_drvdata" },
	{ 0x461383f5, "usb_free_urb" },
	{ 0x29537c9e, "alloc_chrdev_region" },
	{ 0xedb3433d, "usb_autopm_put_interface" },
	{ 0xa877b6d0, "usb_alloc_urb" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=usbnet,usbcore";

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
