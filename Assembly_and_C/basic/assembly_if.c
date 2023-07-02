#include <stdio.h>

int a = -1;

int main(void){

    // case unsigned, return void

    // int32_t x, y, z;
    // x =1:
    // y = -1;
    // if (x > y)
    //     z = 1;
    // else
    //     z = 0;

    __asm volatile (
        // "ldr X7, =a\n\t"
        // // load content of X0 register, into X1
        // "ldr X2, [X7]\n\t"
        "mov X1, #0x00000001\n\t"
        "mov X2, #0xFFFFFFFFFFFFFFFF\n\t"
        // X1 - X2 and check Z,C,... flags
        "cmp X1, X2\n\t"
        // <=
        "ble else\n\t"
        "mov X3, #1\n\t"
        // exit from if, otherwise else was performed
        "b endif\n\t"
        "else:\n\t"
        "mov X3, #0\n\t"
        "endif:\n\t"
    );

    // if (a < 0 ) {
    //  a = 0 - a;
    // }
    // x = x + 1;
    // X4 = a, X5 = x

    __asm volatile (
        // reset register
        // a = -1
        "mov X4, #0xFFFFFFFFFFFFFFFF\n\t"
        "mov X5, #0\n\t"
        // Compare a with 0
        // X4 - 0 and check Z,C,... flags
        "cmp X4, #0\n\t"
        // Go to endif if a >= 0
        "bge endif2\n\t"
        // a = - a
        "mov X6, #1\n\t"
        "add X4, X4, X6, lsl #31\n\t"
        "endif2:\n\t"
        // x = x + 1
        "add X5, X5, #1\n\t"
    );


    // if(x <= 20 || x >= 25){
    //     a = 1;
    // }
    // b = 1

    __asm volatile (
        "mov X7, #30\n\t"
        // X7 - 20 <= 0 ? then
        "cmp X7, #20\n\t"
        "ble then\n\t"
        // X7 - 25 <= 0 ? then : endif
        "cmp X7, #25\n\t"
        "ble endif3\n\t"
        "then:\n\t"
        "mov X8, #1\n\t"
        "endif3:\n\t"
        "\n\t"
        "mov X9, #1\n\t"
    );

    // if(x > 20 && x < 25){
    //     a = 1;
    // }
    // b = 1

    __asm volatile (
        "mov X9, #0\n\t"
        "mov X8, #0\n\t"
        "mov X7, #12\n\t"
        // X7 - 20 <= 0 ? then
        "cmp X7, #20\n\t"
        "ble endif4\n\t"
        // X7 - 25 >= 0 ? then : endif
        "cmp X7, #25\n\t"
        "bge endif3\n\t"
        "mov X8, #1\n\t"
        "endif4:\n\t"
        "\n\t"
        "mov X9, #1\n\t"
    );


    // if ( x == 5 || (x > 20 && x < 25) )
    //     a = 1;
    // b = 1

    __asm volatile (
        "mov X7, #2\n\t"
        // X7 - 5 = 0 ? then2
        "cmp X7, #5\n\t"
        "beq then2\n\t"
        // X7 - 20 <= 0 ? then : endif
        "cmp X7, #20\n\t"
        "ble endif5\n\t"
        // X7 - 25 >= 0 ? then : endif
        "cmp X7, #25\n\t"
        "bge endif5\n\t"
        "then2:\n\t"
        "mov X8, #1\n\t"
        "endif5:\n\t"
        "\n\t"
        "mov X9, #1\n\t"
    );


}
