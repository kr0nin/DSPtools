cmd_/home/kronin/Desktop/gobiarch/QCUSBNet/QMI.o := gcc -Wp,-MD,/home/kronin/Desktop/gobiarch/QCUSBNet/.QMI.o.d  -nostdinc -isystem /usr/lib/gcc/x86_64-unknown-linux-gnu/4.6.2/include -I/usr/src/linux-3.1.5-1-ARCH/arch/x86/include -Iarch/x86/include/generated -Iinclude  -include /usr/src/linux-3.1.5-1-ARCH/include/linux/kconfig.h -D__KERNEL__ -Wall -Wundef -Wstrict-prototypes -Wno-trigraphs -fno-strict-aliasing -fno-common -Werror-implicit-function-declaration -Wno-format-security -fno-delete-null-pointer-checks -O2 -m64 -mtune=generic -mno-red-zone -mcmodel=kernel -funit-at-a-time -maccumulate-outgoing-args -fstack-protector -DCONFIG_AS_CFI=1 -DCONFIG_AS_CFI_SIGNAL_FRAME=1 -DCONFIG_AS_CFI_SECTIONS=1 -DCONFIG_AS_FXSAVEQ=1 -pipe -Wno-sign-compare -fno-asynchronous-unwind-tables -mno-sse -mno-mmx -mno-sse2 -mno-3dnow -Wframe-larger-than=2048 -Wno-unused-but-set-variable -fno-omit-frame-pointer -fno-optimize-sibling-calls -pg -Wdeclaration-after-statement -Wno-pointer-sign -fno-strict-overflow -fconserve-stack -DCC_HAVE_ASM_GOTO  -DMODULE  -D"KBUILD_STR(s)=\#s" -D"KBUILD_BASENAME=KBUILD_STR(QMI)"  -D"KBUILD_MODNAME=KBUILD_STR(QCUSBNet2k)" -c -o /home/kronin/Desktop/gobiarch/QCUSBNet/.tmp_QMI.o /home/kronin/Desktop/gobiarch/QCUSBNet/QMI.c

source_/home/kronin/Desktop/gobiarch/QCUSBNet/QMI.o := /home/kronin/Desktop/gobiarch/QCUSBNet/QMI.c

deps_/home/kronin/Desktop/gobiarch/QCUSBNet/QMI.o := \
  /usr/src/linux-3.1.5-1-ARCH/include/linux/kconfig.h \
    $(wildcard include/config/h.h) \
    $(wildcard include/config/.h) \
    $(wildcard include/config/foo.h) \
  /home/kronin/Desktop/gobiarch/QCUSBNet/QMI.h \

/home/kronin/Desktop/gobiarch/QCUSBNet/QMI.o: $(deps_/home/kronin/Desktop/gobiarch/QCUSBNet/QMI.o)

$(deps_/home/kronin/Desktop/gobiarch/QCUSBNet/QMI.o):
