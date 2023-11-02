/*
Il design pattern Iterator è un pattern 
comportamentale che fornisce un modo per 
accedere sequenzialmente agli elementi di 
una collezione senza esporre i dettagli 
interni della struttura della collezione. 
*/

#include <stdio.h>
#include <stdlib.h>

// Struttura per un elemento nella lista
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Struttura per un iteratore
typedef struct Iterator {
    Node* current;
} Iterator;

// Funzione per creare un nuovo nodo nella lista
Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Funzione per aggiungere un elemento alla fine della lista
void append(Node** head, int data) {
    Node* new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
    } else {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

// Funzione per inizializzare un iteratore
Iterator create_iterator(Node* list) {
    Iterator it;
    it.current = list;
    return it;
}

// Funzione per verificare se ci sono altri elementi da iterare
int has_next(Iterator* it) {
    return it->current != NULL;
}

// Funzione per ottenere l'elemento corrente e avanzare l'iteratore
int next(Iterator* it) {
    if (has_next(it)) {
        int data = it->current->data;
        it->current = it->current->next;
        return data;
    }
    return -1; // Valore di ritorno predefinito se non ci sono più elementi
}

int main() {
    Node* list = NULL;
    append(&list, 1);
    append(&list, 2);
    append(&list, 3);
    append(&list, 4);

    Iterator it = create_iterator(list);

    printf("Elementi nella lista: ");
    while (has_next(&it)) {
        printf("%d ", next(&it));
    }
    printf("\n");

    return 0;
}
