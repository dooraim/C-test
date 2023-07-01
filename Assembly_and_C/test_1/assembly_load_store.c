#include <stdio.h>

int a = 1;

int main(void)
{

    __asm (
        // load address of a into X0 register
        "ldr X0, =a\n\t"
        // load content of X0 register, into X1
        "ldr X1, [X0]\n\t"
    );

    return 0;
}
