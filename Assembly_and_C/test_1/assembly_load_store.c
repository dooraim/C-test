#include <stdio.h>

int a = 1;
int b = 0;
int array[5] = {1, 2, 3, 4, 5};

int main(void)
{


    // clean register
    __asm volatile (
        "mov X0, #0\n\t"
        "mov X1, #0\n\t"
        "mov X2, #0\n\t"
        "mov X3, #0\n\t"
        "mov X4, #0\n\t"
        "mov X5, #0\n\t"
        "mov X6, #0\n\t"
        "mov X7, #0\n\t"
        "mov X8, #0\n\t"
    );


    __asm volatile (
        // load address of a into X0 register
        "ldr X0, =a\n\t"
        // load content of X0 register, into X1
        "ldr X1, [X0]\n\t"
    );

    __asm volatile (
        // load address of b into X2 register
        "ldr X2, =b\n\t"
        // store content of a (X1 register), into X2
        // can't see it on layout regs of gdb, please see print
        "str X1, [X2]\n\t"
    );

    printf("b value 0x%X\n", b);

    // Suppose we want to load an array of five integers into
    // registers rl, r2, r3, r4, and rs.

      __asm volatile (
        "ldr X3, =array\n\t"
        "ldr X4, [X3]\n\t"
        "add X4, X4, #1\n\t"
        "ldr X5, [X3, #4]\n\t"
        "add X5, X5, #1\n\t"
        "ldr X6, [X3, #8]\n\t"
        "add X6, X6, #1\n\t"
        "ldr X7, [X3, #12]\n\t"
        "add X7, X7, #1\n\t"
        "ldr X8, [X3, #16]\n\t"
        "add X8, X8, #1\n\t"
    );


    return 0;
}
