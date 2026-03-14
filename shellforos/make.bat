# kernel.asm COMPILING
nasm -f win32 kernel.asm -o binaries/kernel.o

# shell.c COMPILING
gcc -m32 -c shell.c -o binaries/shell.o -ffreestanding

# linker.ld LINKING
ld -m i386pe -T linker.ld binaries/kernel.o binaries/shell.o -o SimpleShell.img