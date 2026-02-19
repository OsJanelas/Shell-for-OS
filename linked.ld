ENTRY(_start)
SECTIONS
{
    . = 0x100000; /* Carrega o Kernel em 1MB de RAM */

    .text : { *(.text) }   /* Código do Shell e Kernel */
    .data : { *(.data) }   /* Variáveis e Logos ASCII */
    .bss  : { *(.bss)  }   /* Memória temporária */
}