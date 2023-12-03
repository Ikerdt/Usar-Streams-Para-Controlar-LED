#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define LED_PATH "/sys/class/leds/gpio-led/brightness"

int main() {
    FILE *ledFile;
    char value;
    int randomValue;

    while (1) {
        ledFile = fopen(LED_PATH, "w");
        if (!ledFile) {
            perror("Error opening LED file");
            return 1;
        }

        FILE *randomFile = fopen("/dev/urandom", "r");
        if (!randomFile) {
            perror("Error opening /dev/urandom");
            return 1;
        }

        // Read a single byte from /dev/urandom
        fread(&randomValue, sizeof(int), 1, randomFile);
        fclose(randomFile);

        value = (randomValue > 128) ? '1' : '0';

        // Control the LED based on the read value
        fprintf(ledFile, "%c", value);
        fclose(ledFile);

        sleep(1); // Wait for a second
    }

    return 0;
}

