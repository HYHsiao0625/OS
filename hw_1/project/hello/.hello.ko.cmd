savedcmd_/home/yuan/Desktop/OS/hw_1/project/hello/hello.ko := ld -r -m elf_x86_64 -z noexecstack --build-id=sha1  -T scripts/module.lds -o /home/yuan/Desktop/OS/hw_1/project/hello/hello.ko /home/yuan/Desktop/OS/hw_1/project/hello/hello.o /home/yuan/Desktop/OS/hw_1/project/hello/hello.mod.o;  make -f ./arch/x86/Makefile.postlink /home/yuan/Desktop/OS/hw_1/project/hello/hello.ko