#include <stdio.h>

int main(void){

    int i;
    int sum = 0;

    for(i=0; i < 10; i++){
        sum += i;
    }

    printf("sum %d i %d\n", sum, i);

    __asm volatile (
        // clean register
        "mov X0, #0\n\t"
        "mov X1, #0\n\t"
        // for debug
        "mov X2, #0\n\t"

        // go to check
        "b check\n\t"
        "loop:\n\t"
        "add X1, X1, X0\n\t"
        "add X0, X0, #1\n\t"
        // for debug
        "mov X2, X0\n\t"
        "check:\n\t"
        "cmp X0, #10\n\t"
        // X0 - 10 ? Less Than
        "blt loop\n\t"
        "endloop:\n\t"
        "\n\t"
        "mov X9, #1\n\t"
    );

    __asm volatile (
        // clean register
        "mov X0, #0\n\t"
        "mov X1, #0\n\t"
        // debug
        "mov X2, #0\n\t"

        "loop2:\n\t"
        "cmp X0, #10\n\t"
        // X0 - 10 >= 0
        "bge endloop2\n\t"
        "add X1, X1, X0\n\t"
        "add X0, X0, #1\n\t"
        // for debug
        "mov X2, X0\n\t"
        "b loop2\n\t"
        "endloop2:\n\t"
        "\n\t"
        "mov X9, #1\n\t"
    );

}
