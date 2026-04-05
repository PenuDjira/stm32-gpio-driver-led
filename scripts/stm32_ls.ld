/* STM32_LS.ld Code */

/* 1. Definition the address and the size of the MEMORY */
MEMORY
{
    /* Nama(Atribut) : ORIGIN = Alamat Start, LENGTH = Ukuran */
    FLASH(rx) : ORIGIN = 0x08000000, LENGTH = 512K
    SRAM(rwx) : ORIGIN = 0x20000000, LENGTH = 128K
}

/* 2. Definition the place of the Sections */
SECTIONS
{
    /* Our main program code is placed into FLASH */
    .text :
    {
        *(.isr_vector)    /* Interuption table must in first place */
        *(.text)          /* ALl of main.c code saved at .text */
        *(.rodata)        /* Constant data like const uint8_t pin = 13; (Read-Only) */
        _etext = .;       /* The last address of the code in FLASH */
    } > FLASH

    /* _sidata is the first address the the data in FLASH that will copied into SRAM*/
    _sidata = LOADADDR(.data);

    /* DATA Section (Global Variable contains Value, like: uint32_t delay_value = 1000000;) */
    /* Save in FLASH (AT > FLASH) but runs in RAM*/
    .data :
    {
        _sdata = .;       /* Start data in RAM */
        *(.data)
        _edata = .;       /* End data in RAM */
    } > SRAM AT > FLASH

    /* BSS Section (contains global Variabel that have value 0, like uint32_t x;) */
    .bss :
    {
        _sbss = .;        /* Start bss in RAM */
        *(.bss)
        _ebss = .;        /* End bss in RAM */
    } > SRAM
}