#include <stdio.h>

int main(void)
{

    // single instruction in assembly
    __asm (
        "mov X0, #0xFFFF\n\t"
    );


    // multiple instruction in assembly
    __asm (
        "mov X1, #0xFFFF\n\t"
        "mov X2, #0xFFFF\n\t"
        "mov X3, #0xFFFF\n\t"
        "mov X4, #0xFFFF\n\t"
    );

    return 0;
}
