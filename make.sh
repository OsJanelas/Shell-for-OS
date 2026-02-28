echo "compiling kernel"
nasm -felf   kernel.asm        -o kernel.o

echo "compiling userspace"
i686-elf-gcc -ffreestanding -m32 -g -c shell.c       -o shell.o

echo "linking"
ld -m elf_i386 -T linker.ld -o fullkernel kernel.o shell.o

echo "Generating IMG File"
grub-mkrescue -o ShellExample.img Shell/

runner.bat
