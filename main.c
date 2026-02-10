#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define ARRAY_SIZE  100

// Function that returns the output string (no malloc)
uint8_t* removeDuplicates(uint8_t *pinputString, char *pOutputString) {
    int index = 0;

    for (int i = 0; pinputString[i] != '\0'; i++) {
        uint8_t c = pinputString[i];
        int found = 0;

        // Check manually if c is already in uniqueString
        for (int j = 0; j < index; j++) {
            if (pOutputString[j] == c) {
                found = 1;
                break;
            }
        }

        if (!found) {
            pOutputString[index++] = c;
        }
    }
    pOutputString[index] = '\0'; // null terminate

    return pOutputString; // return pointer to caller's buffer
}

int main() 
{
    uint8_t ucInputString[ARRAY_SIZE];
    uint8_t ucOutputString[ARRAY_SIZE]; // caller provides buffer

    printf("Enter a string: ");
    if (fgets(ucInputString, sizeof(ucInputString), stdin) != NULL) {
        size_t len = strlen(ucInputString);
        if (len > 0 && ucInputString[len - 1] == '\n') {
            ucInputString[len - 1] = '\0';
        }
    }

    uint8_t *ucResult = removeDuplicates(ucInputString, ucOutputString);

    printf("Original string: %s\n", ucInputString);
    printf("String without duplicates: %s\n", ucResult);

    return 0;
}
