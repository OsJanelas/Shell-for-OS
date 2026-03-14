/* MADE WITH GEMINI /*

ENTRY(_start)                /* 1. Define o ponto de entrada */

SECTIONS
{
    . = 0x100000;            /* 2. Define o endereço de carregamento (ex: 1MB) */

    .text : {                /* 3. Seção de código */
        *(.text)
    }

    .data : {                /* 4. Seção de dados inicializados */
        *(.data)
    }

    .bss : {                 /* 5. Seção de dados não inicializados */
        *(.bss)
        *(COMMON)
    }
}