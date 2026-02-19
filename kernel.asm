; x86 system in Shell
global print_string

print_string:
    push bp
    mov bp, sp
    mov si, [bp+8]

.loop:
    lodsb
    or al, al
    jz .done
    mov ah, 0x0E
    int 0x10
    jmp .loop

.done:
    pop bp
    ret