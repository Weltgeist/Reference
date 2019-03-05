
MODULES := hellokernel.o

#guest architecture
# define by : source /export/tmp/4205_nn/opt/poky/environment-setup-aarch64-poky-linux 

obj-m := $(MODULES)

#path of the arm64 kernel source
ROOTDIR := /export/tmp/4205_nn/opt/poky/sysroots/aarch64-poky-linux/usr/src/kernel

MAKEARCH := $(MAKE) ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE)

all: modules
modules:
	$(MAKEARCH) -C $(ROOTDIR) M=${shell pwd} modules

clean:
	$(MAKEARCH) -C $(ROOTDIR) M=${shell pwd} clean