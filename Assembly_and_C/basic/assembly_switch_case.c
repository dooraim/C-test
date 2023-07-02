#include <stdio.h>
#include <stdint.h>

int main(void){

    uint32_t score;
    char grade;

    switch (score){
        case 10:

        case 9:
        grade = 'A';
        break;

        case 8:
        grade = 'B';
        break;

        case 7:
        grade = 'C';
        break;

        case 6:
        grade = 'D';
        break;
    }

    __asm volatile(
        // Inizializzazione delle variabili
        ".data\n"
        "score:  .word 0\n"
        "grade:  .byte 0\n"

        // Switch-case
        "ldr x0, =score\n"      // Carica l'indirizzo della variabile score nel registro x0
        "ldrb w1, [x0]\n"       // Carica il valore della variabile score nel registro w1

        "cmp w1, #10\n"         // Confronta il valore di score con 10
        "beq case_10\n"         // Se score è uguale a 10, salta all'etichetta case_10

        "cmp w1, #9\n"          // Confronta il valore di score con 9
        "beq case_9\n"          // Se score è uguale a 9, salta all'etichetta case_9

        "cmp w1, #8\n"          // Confronta il valore di score con 8
        "beq case_8\n"          // Se score è uguale a 8, salta all'etichetta case_8

        "cmp w1, #7\n"          // Confronta il valore di score con 7
        "beq case_7\n"          // Se score è uguale a 7, salta all'etichetta case_7

        "cmp w1, #6\n"          // Confronta il valore di score con 6
        "beq case_6\n"          // Se score è uguale a 6, salta all'etichetta case_6

        // Fine dello switch-case
        "end_switch:\n"
        // ...

        // Etichetta case_10
        "case_10:\n"
        "ldr x0, =grade\n"      // Carica l'indirizzo della variabile grade nel registro x0
        "mov w1, #'A'\n"        // Carica il valore ASCII del carattere 'A' nel registro w1
        "strb w1, [x0]\n"       // Salva il valore nel registro w1 nella variabile grade
        "b end_switch\n"        // Salta alla fine dello switch-case

        // Etichetta case_9
        "case_9:\n"
        "ldr x0, =grade\n"      // Carica l'indirizzo della variabile grade nel registro x0
        "mov w1, #'A'\n"        // Carica il valore ASCII del carattere 'A' nel registro w1
        "strb w1, [x0]\n"       // Salva il valore nel registro w1 nella variabile grade
        "b end_switch\n"        // Salta alla fine dello switch-case

        // Etichetta case_8
        "case_8:\n"
        "ldr x0, =grade\n"      // Carica l'indirizzo della variabile grade nel registro x0
        "mov w1, #'B'\n"        // Carica il valore ASCII del carattere 'B' nel registro w1
        "strb w1, [x0]\n"       // Salva il valore nel registro w1 nella variabile grade
        "b end\n"
      );


}


