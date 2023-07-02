#include <stdio.h>

int main(void){

    int sum = 0;
    int i = 10;
    do{
        sum += i;
        i--;
    } while( i > 0 );

    __asm volatile (
        // clean register
        "mov X0, #10\n\t"
        "mov X1, #0\n\t"

        "loop:\n\t"
        "add X1, X1, X0\n\t"
        "sub X0, X0, #1\n\t"
        "cmp X0, #0\n\t"
        // X0 - 10 > 0? Loop : endloop
        "bgt loop\n\t"
        "endloop:\n\t"
        "\n\t"
        "mov X9, #1\n\t"
    );

    __asm volatile (
        // clean register
        "mov X0, #10\n\t"
        "mov X1, #0\n\t"

        "loop2:\n\t"
        "add X1, X1, X0\n\t"
        // instead of compare use suffix S
        "subs X0, X0, #1\n\t"
        // X0 - 10 > 0? Loop : endloop
        "bgt loop2\n\t"
        "endloop2:\n\t"
        "\n\t"
        "mov X9, #1\n\t"
    );

}
