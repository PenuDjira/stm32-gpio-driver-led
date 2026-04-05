/* Startup code for STM32 microcontroller */

#include <stdint.h>

/* These symbols are defined in the linker script */
extern uint32_t _etext, _sdata, _edata, _sbss, _ebss, _sidata;

/* The top of the stack of SRAM */
#define SRAM_START 0x20000000U
#define SRAM_SIZE (128U * 1024U) /* 128 KB */
#define STACK_TOP (SRAM_START + SRAM_SIZE)

// Function prototypes
void Reset_Handler(void);
extern int main(void);

/* Vector Table: Address list that is read by the CPU during startup */
/* __attribute__((section(".isr_vector"))) ensures that this array is placed in the correct section */
uint32_t vector[] __attribute__((section(".isr_vector"))) = {
    STACK_TOP,                  /* 0x00000000 : first address of Stack Pointer*/
    (uint32_t)Reset_Handler     /* 0x00000004 : The first instructions address after reset */
};

void Reset_Handler(void){
    /* 1. Copy data from Flash to RAM */
    /* Variables that have initial values (like int x = 10) must be copied from FLASH to RAM so they can be modified */
    uint32_t size = (uint32_t)&_edata - (uint32_t)&_sdata; /* Size of data to be copied */
    uint32_t *pDst = (uint32_t *)&_sdata; /* Initial address of data in RAM - Destination: RAM */
    uint32_t *pSrc = (uint32_t *)&_sidata; /* Initial address of data in Flash - Source: FLASH */

    for (uint32_t i = 0; i < size; i++)
    {
        *pDst++ = *pSrc++; /* Copy data from Flash to RAM */
    }

    /* 2. Fill BSS with zeros */
    /* Variables that are not initialized (int y) must be zero at startup */
    size = (uint32_t)&_ebss - (uint32_t)&_sbss; /* Size of BSS */
    pDst = (uint32_t *)&_sbss; /* Initial address of BSS in RAM */
    for(uint32_t i = 0; i < size; i++)
    {
        *pDst++ = 0; /* Every byte in BSS is filled with 0 */
    }

    /* 3. Call main function */
    main();

    /* If main returns, loop forever here */
    while (1);
    
}