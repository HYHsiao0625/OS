obj-m := jiffies.o
all:
	make -C /lib/modules/`uname -r`/build M=`pwd` modules
clean:
	rm -rf *.o *.ko *.mod.* *.symvers *.order *.mod.cmd *.mod
