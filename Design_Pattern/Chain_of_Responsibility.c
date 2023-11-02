#include <stdio.h>
#include <stdlib.h>

// Definizione di una struttura per rappresentare una richiesta di log
typedef struct {
    int level;
    char message[256];
} LogRequest;

// Definizione di una struttura per rappresentare un gestore di log
typedef struct Logger {
    int level;
    void (*log_message)(struct Logger *self, LogRequest *request);
    struct Logger *next;
} Logger;

// Implementazione di un gestore di log
void console_log(Logger *self, LogRequest *request) {
    if (request->level <= self->level) {
        printf("Log in console: %s\n", request->message);
    }
    if (self->next != NULL) {
        self->next->log_message(self->next, request);
    }
}

void file_log(Logger *self, LogRequest *request) {
    if (request->level <= self->level) {
        FILE *file = fopen("log.txt", "a");
        if (file != NULL) {
            fprintf(file, "Log in file: %s\n", request->message);
            fclose(file);
        }
    }
    if (self->next != NULL) {
        self->next->log_message(self->next, request);
    }
}

void email_log(Logger *self, LogRequest *request) {
    if (request->level <= self->level) {
        printf("Invio email con log: %s\n", request->message);
    }
    if (self->next != NULL) {
        self->next->log_message(self->next, request);
    }
}

int main() {
    // Creazione di gestori di log
    // Livello, tipo di log, next
    Logger console = {1, console_log, NULL};
    Logger file = {2, file_log, NULL};
    Logger email = {3, email_log, NULL};

    // Collegamento dei gestori in una catena
    console.next = &file;
    file.next = &email;

    // Creazione di richieste di log
    LogRequest request1 = {2, "Messaggio di log importante"};
    LogRequest request2 = {3, "Messaggio di log critico"};

    // Utilizzo della catena per gestire le richieste di log
    console.log_message(&console, &request1);  // Log in console e file
    console.log_message(&console, &request2);  // Log in console, file ed email

    return 0;
}
