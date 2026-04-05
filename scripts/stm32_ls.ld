/* STM32_LS.ld Code */

/* 1. Definisikan Kapasitas Memori STM32F411CEU6 */
MEMORY
{
    /* Nama(Atribut) : ORIGIN = Alamat Start, LENGTH = Ukuran */
    FLASH(rx) : ORIGIN = 0x08000000, LENGTH = 512K
    SRAM(rwx) : ORIGIN = 0x20000000, LENGTH = 128K
}

/* 2. Definisikan Penempatan Section */
SECTIONS
{
    /* Bagian KODE (Program) diletakkan di FLASH */
    .text :
    {
        *(.isr_vector)    /* Tabel Interupsi (Wajib di paling awal) */
        *(.text)          /* Semua kode program .c Anda */
        *(.rodata)        /* Data konstanta (Read-Only) */
        _etext = .;       /* Tandai alamat akhir kode di Flash */
    } > FLASH

    /* _sidata adalah alamat awal data di Flash yang akan dikopi ke RAM */
    _sidata = LOADADDR(.data);

    /* Bagian DATA (Variabel Global Berisi Nilai, misal: int x = 10) */
    /* Disimpan di Flash (AT > FLASH) tapi dijalankan di RAM */
    .data :
    {
        _sdata = .;       /* Start data di RAM */
        *(.data)
        _edata = .;       /* End data di RAM */
    } > SRAM AT > FLASH

    /* Bagian BSS (Variabel Global Bernilai Nol, misal: int y) */
    .bss :
    {
        _sbss = .;        /* Start bss di RAM */
        *(.bss)
        _ebss = .;        /* End bss di RAM */
    } > SRAM
}