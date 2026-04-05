/* Startup code for STM32 microcontroller */

#include <stdint.h>

/* Simbol-simbol ini didefinisikan di Linker Script (stm32_ls.ld) */
extern uint32_t _etext, _sdata, _edata, _sbss, _ebss, _sidata;

/* Ujung stack (128KB dari start RAM) */
#define SRAM_START 0x20000000U
#define SRAM_SIZE (128U * 1024U) /* 128 KB */
#define STACK_TOP (SRAM_START + SRAM_SIZE)

void Reset_Handler(void);
extern int main(void);

/* Vector Table: Daftar alamat yang dibaca CPU saat startup */
/* __attribute__((section(".isr_vector"))) memastikan ini ada di paling depan Flash */
uint32_t vector[] __attribute__((section(".isr_vector"))) = {
    STACK_TOP,                  /* 0x00000000 : Alamat awal Stack Pointer*/
    (uint32_t)Reset_Handler     /* 0x00000004 : Alamat instruksi pertama setelah reset */
};

void Reset_Handler(void){
    /* 1. Copy data dari Flash ke RAM */
    /* Variabel yang ada isinya (seperti int x = 10) harus dipindahkan dari FLASH Ke RAM agar bisa diubah */
    uint32_t size = (uint32_t)&_edata - (uint32_t)&_sdata; /* Ukuran data yang perlu disalin */
    uint32_t *pDst = (uint32_t *)&_sdata; /* Alamat awal data di RAM - Destination: RAM */
    uint32_t *pSrc = (uint32_t *)&_sidata; /* Alamat awal data di Flash - Source: FLASH */

    for (uint32_t i = 0; i < size; i++)
    {
        *pDst++ = *pSrc++; /* Salin data dari Flash ke RAM */
    }

    /* 2. Isi BSS dengan angka 0 */
    /* Variabel yang tidak diinisialisasi (int y) wajib nol saat startup */
    size = (uint32_t)&_ebss - (uint32_t)&_sbss; /* Ukuran BSS */
    pDst = (uint32_t *)&_sbss; /* Alamat awal BSS di RAM */
    for(uint32_t i = 0; i < size; i++)
    {
        *pDst++ = 0; /* Setiap byte di BSS diisi dengan 0 */
    }

    /* 3. Panggil fungsi main */
    main();

    /* Jika main kembali, loop selamanya di sini */
    while (1);
    
}