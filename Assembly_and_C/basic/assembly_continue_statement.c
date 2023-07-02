#include <stdio.h>

int main(void){

    int i = 0;
    int sum = 0;

    for(i = 0; i < 10; i++) {
        if (i == 5)
            continue;
        sum += i;
    }

    printf("sum %d", sum);

    __asm volatile (
        // Inizializzazione delle variabili
        "mov X0, #0\n\t"      // i = 0
        "mov X1, #0\n\t"      // sum = 0

        // Ciclo for
        "for_loop:\n\t"
        "cmp X0, #10\n\t"     // confronta i con 10
        "bge end_loop\n\t"    // se i >= 10, esce dal ciclo
        "cmp X0, #5\n\t"      // confronta i con 5
        "beq continue\n\t"    // se i == 5, salta all'etichetta CONTINUE
        "add X1, X1, X0\n\t"  // sum += i
        "add X0, X0, #1\n\t"  // i++
        "b for_loop\n\t"      // torna all'inizio del ciclo

        // Etichetta CONTINUE
        "continue:\n\t"
        "add X0, X0, #1\n\t"  // i++
        "b for_loop\n\t"      // torna all'inizio del ciclo

        // Fine del ciclo
        "end_loop:\n\t"
        "\n\t"
    );

}


