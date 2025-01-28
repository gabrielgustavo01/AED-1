#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char frase[51];

    while (fgets(frase, sizeof(frase), stdin)) {
        int upper = 1;
        for (int i = 0; frase[i] != '\0'; i++) {
            if (isalpha(frase[i])) {
                if (upper) {
                    frase[i] = toupper(frase[i]);
                } else {
                    frase[i] = tolower(frase[i]);
                }
                upper = !upper;
            }
        }
        printf("%s", frase);
    }

    return 0;
}
