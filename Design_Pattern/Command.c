/* Il design pattern Command è un pattern comportamentale 
che incapsula una richiesta come un oggetto, consentendo 
di parametrizzare i client con richieste, accodare 
richieste e supportare operazioni di annullamento. 
In questo pattern, una richiesta viene rappresentata 
come un oggetto, che contiene tutti i dettagli necessari 
per l'esecuzione dell'azione richiesta. 
Questo separa chi emette la richiesta (client) da chi 
effettivamente la esegue (ricevitore), consentendo inoltre 
di modificare o estendere il comportamento del sistema 
in modo flessibile. */

#include <stdio.h>

// Interfaccia del comando
typedef struct {
    void (*execute)(void);
} Command;

// Implementazione concreta del comando
typedef struct {
    Command base;
    void (*receiver_action)(void);
} ConcreteCommand;

// Oggetti ricevitori (dispositivi elettronici)
typedef struct {
    const char *device_name;
    void (*turn_on)(void);
    void (*turn_off)(void);
} TV;
typedef struct {
    const char *device_name;
    void (*start)(void);
    void (*stop)(void);
} Stereo;

// Implementazione del comando per accendere il dispositivo
void turn_on_command_execute(void) {
    printf("Accensione del dispositivo\n");
}

// Implementazione del comando per spegnere il dispositivo
void turn_off_command_execute(void) {
    printf("Spegnimento del dispositivo\n");
}

// Implementazione delle azioni per la TV
void tv_turn_on(void) {
    printf("TV è stata accesa\n");
}
void tv_turn_off(void) {
    printf("TV è stata spenta\n");
}

// Implementazione delle azioni per lo Stereo
void stereo_start(void) {
    printf("Stereo è stato acceso\n");
}
void stereo_stop(void) {
    printf("Stereo è stato spento\n");
}

int main() {
    // Creazione di oggetti ricevitori (TV e Stereo)
    TV living_room_tv = {"TV del soggiorno", tv_turn_on, tv_turn_off};
    Stereo music_system = {"Sistema stereo", stereo_start, stereo_stop};

    // Creazione di comandi concreti associati a diversi ricevitori
    ConcreteCommand tv_on_command = {{turn_on_command_execute}, tv_turn_on};
    ConcreteCommand tv_off_command = {{turn_off_command_execute}, tv_turn_off};
    ConcreteCommand stereo_on_command = {{turn_on_command_execute}, stereo_start};
    ConcreteCommand stereo_off_command = {{turn_off_command_execute}, stereo_stop};

    // Esecuzione dei comandi per accendere e spegnere i dispositivi
    tv_on_command.base.execute();
    tv_off_command.base.execute();
    stereo_on_command.base.execute();
    stereo_off_command.base.execute();

    // Esecuzione delle azioni dei ricevitori (accendere e spegnere i dispositivi)
    living_room_tv.turn_on();
    living_room_tv.turn_off();
    music_system.start();
    music_system.stop();

    return 0;
}
