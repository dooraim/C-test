/*
Il design pattern Mediator è un pattern comportamentale 
che promuove la comunicazione indiretta tra oggetti, 
riducendo le dipendenze tra di essi. Questo pattern 
consente di ridurre l'accoppiamento tra i componenti 
del sistema, favorendo la modularità e la 
manutenibilità del codice. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Dichiarazione della struttura al di fuori delle funzioni
typedef struct HomeAutomationComponent HomeAutomationComponent;

// Struttura per un componente della domotica
struct HomeAutomationComponent {
    const char* name;
    void (*send_message)(struct HomeAutomationComponent* self, const char* sender, const char* message);
    void (*receive_message)(struct HomeAutomationComponent* self, const char* sender, const char* message);
};


// Struttura per il Mediator (mediatore) del sistema di automazione domestica
typedef struct {
    HomeAutomationComponent* components[10];
    int count;
} HomeAutomationSystem;

void send_message(HomeAutomationComponent* self, const char* sender, const char* message) {
    printf("%s invia: %s\n", self->name, message);
    for (int i = 0; i < 10; i++) {
        if (self->receive_message && self->receive_message != self->send_message) {
            self->receive_message(self, self->name, message);
        }
    }
}

void receive_message(HomeAutomationComponent* self, const char* sender, const char* message) {
    printf("%s riceve da %s: %s\n", self->name, sender, message);
}


// Funzione per aggiungere un componente al sistema
void add_component(HomeAutomationSystem* system, HomeAutomationComponent* component) {
    if (system->count < 10) {
        system->components[system->count] = component;
        system->count++;
    }
}

int main() {
    HomeAutomationSystem system;
    system.count = 0;

    HomeAutomationComponent lights = {"Luci", send_message, receive_message};
    HomeAutomationComponent thermostat = {"Termostato", send_message, receive_message};
    HomeAutomationComponent securitySystem = {"Sistema di sicurezza", send_message, receive_message};

    add_component(&system, &lights);
    add_component(&system, &thermostat);
    add_component(&system, &securitySystem);

    lights.send_message(&lights, "Alice", "Accendi le luci del soggiorno.");
    thermostat.send_message(&thermostat, "Bob", "Aumenta la temperatura a 22°C.");
    securitySystem.send_message(&securitySystem, "Charlie", "Attiva l'allarme antifurto.");

    return 0;
}

