
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM_MAC_STRING 19

static char mac_str[DIM_MAC_STRING];
static char memcopy_str[DIM_MAC_STRING];


char* restituisciStringa(char * string_to_write) {

    int size = 0;
	size = snprintf(mac_str, 2, "%s", string_to_write); // Scrive la stringa nel buffer
    if (size < 20)
		return NULL;
	
	return mac_str;
}

char* memcopyExample(char * string_to_write) {

    memcpy(memcopy_str, &string_to_write, sizeof(memcopy_str)+1);
    
	return memcopy_str;
}

void scriviInArray(char array[], const char *stringa) {
    int i = 0;

    // Copia i caratteri della stringa nell'array fino a raggiungere '\0' (terminatore della stringa)
    while (*stringa != '\0') {
        array[i] = *stringa;
        i++;
        stringa++;
    }

    // Assicurati di terminare l'array con '\0'
    array[i] = '\0';
}

// Function to copy a string using memcpy
char* copyString(const char* source) {
    // Calculate the length of the source string
    size_t source_length = strlen(source) + 1; // +1 to include the null terminator

    // Use memcpy to copy the source string to the destination string
    memcpy(memcopy_str, source, source_length);

    // Return the copied string
    return memcopy_str;
}

int main() {

    // Chiama la funzione per scrivere una stringa nell'array
    scriviInArray(mac_str, "abcd");

    // Stampa l'array per verificare il risultato
    printf("Contenuto dell'array: %s\n", mac_str);

    scriviInArray(mac_str, "efghi");

    printf("Contenuto dell'array: %s\n", mac_str);

    char buffer[5];
    int risultato = snprintf(buffer, sizeof(buffer), "Il numero è: %d", 42);

    if (risultato < 0 || risultato >= sizeof(buffer)) {
        // Errore o buffer troppo piccolo
        printf("Errore o buffer troppo piccolo\n");
    } else {
        // Operazione riuscita, stampa del risultato
        printf("Stringa formattata: %s\n", buffer);
    }

	char* string_return = restituisciStringa("pippo");

    if (string_return != NULL)
        printf("Stringa restituita: %s\n", string_return);

	string_return = restituisciStringa("pluto");

    if (string_return != NULL)
        printf("Stringa restituita: %s\n", string_return);

	string_return = copyString("ciccio");

    if (string_return != NULL)
        printf("Stringa restituita memcopy: %s\n", string_return);

    return 0;
}
