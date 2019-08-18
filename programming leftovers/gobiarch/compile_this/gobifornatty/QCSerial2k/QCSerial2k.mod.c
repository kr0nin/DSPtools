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
	{ 0xe9dbf1dc, "usb_serial_resume" },
	{ 0x3ea1aea4, "usb_serial_disconnect" },
	{ 0xbc4e2b92, "usb_serial_probe" },
	{ 0x677bb305, "param_ops_bool" },
	{ 0xfd2a74a9, "usb_deregister" },
	{ 0x8cd15312, "usb_serial_deregister" },
	{ 0xddca35e5, "usb_register_driver" },
	{ 0x45e1bf8c, "usb_serial_register" },
	{ 0xa47edc63, "usb_serial_suspend" },
	{ 0xa7586379, "dev_get_drvdata" },
	{ 0x27e1a049, "printk" },
	{ 0x3557b322, "usb_set_interface" },
	{ 0xb4390f9a, "mcount" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=usbserial";

MODULE_ALIAS("usb:v05C6p9214d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v05C6p9215d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v05C6p9264d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v05C6p9265d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v16D8p8001d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v16D8p8002d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v413Cp8185d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v413Cp8186d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v1410pA014d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v1410pA010d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v1410pA011d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v1410pA012d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v1410pA013d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v03F0p241Dd*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v03F0p251Dd*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v05C6p9204d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v05C6p9205d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v05C6p9208d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v05C6p920Bd*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v04DAp250Ed*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v04DAp250Fd*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v05C6p9244d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v05C6p9245d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v1199p9000d*dc*dsc*dp*ic*isc*ip*");
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
MODULE_ALIAS("usb:v05C6p9224d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v05C6p9225d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v05C6p9234d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v05C6p9235d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v05C6p9274d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v05C6p9275d*dc*dsc*dp*ic*isc*ip*");

MODULE_INFO(srcversion, "8778B44F614AAE6377B4F8D");
