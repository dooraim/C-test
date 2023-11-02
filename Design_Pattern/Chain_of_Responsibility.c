/* Il design pattern "Chain of Responsibility" è utile quando hai una serie 
di oggetti che devono gestire una richiesta in sequenza e ognuno di essi 
ha la possibilità di gestire o trasmettere la richiesta al successivo nella catena.  */

#include <stdio.h>
#include <stdlib.h>

enum LevelLog{
    CONSOLE,
    FILE_L,
    EMAIL
};

// Definizione di una struttura per rappresentare una richiesta di log
typedef struct {
    enum LevelLog level;
    char message[256];
} LogRequest;

// Definizione di una struttura per rappresentare un gestore di log
typedef struct Logger {
    enum LevelLog level;
    void (*log_message)(struct Logger *self, LogRequest *request);
    struct Logger *next;
} Logger;

// Implementazione di un gestore di log
void console_log(Logger *self, LogRequest *request) {
    if (request->level <= self->level) {
        printf("Log in console: %s\n", request->message);
    } else if (self->next != NULL) {
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
    } else if (self->next != NULL) {
        self->next->log_message(self->next, request);
    }
}

void email_log(Logger *self, LogRequest *request) {
    if (request->level <= self->level) {
        printf("Invio email con log: %s\n", request->message);
    } else if (self->next != NULL) {
        self->next->log_message(self->next, request);
    }
}

int main() {
    // Creazione di gestori di log
    // Livello, tipo di log, next
    Logger console = {CONSOLE, console_log, NULL};
    Logger file = {FILE_L, file_log, NULL};
    Logger email = {EMAIL, email_log, NULL};

    // Collegamento dei gestori in una catena
    console.next = &file;
    file.next = &email;

    // Creazione di richieste di log
    // definisci il livello che deve avere la richiesta e poi il messaggio della richiesta
    LogRequest request1 = {FILE_L, "Messaggio di log importante"};
    LogRequest request2 = {EMAIL, "Messaggio di log critico"};

    // Utilizzo della catena per gestire le richieste di log
    console.log_message(&console, &request1);  // Log in console e file
    console.log_message(&console, &request2);  // Log in console, file ed email

    return 0;
}
