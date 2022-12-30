#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x4ff5da6e, "module_layout" },
	{ 0x6bc3fbc0, "__unregister_chrdev" },
	{ 0xd6ee688f, "vmalloc" },
	{ 0x12a4e128, "__arch_copy_from_user" },
	{ 0xeb293000, "__register_chrdev" },
	{ 0x999e8297, "vfree" },
	{ 0xdcb764ad, "memset" },
	{ 0x4b0a3f52, "gic_nonsecure_priorities" },
	{ 0x6cbbfc54, "__arch_copy_to_user" },
	{ 0x92997ed8, "_printk" },
	{ 0x5c1c3eb4, "cpu_hwcaps" },
	{ 0x5e2d7875, "cpu_hwcap_keys" },
	{ 0x796307fc, "find_get_pid" },
	{ 0x360cbf3e, "get_pid_task" },
	{ 0xb788fb30, "gic_pmr_sync" },
	{ 0x14b89635, "arm64_const_caps_ready" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "BF9EA18879733D5E0C03C80");
