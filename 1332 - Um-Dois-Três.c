#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char palavra[6];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", palavra);

        if (strlen(palavra) == 3) {
            int um = 0, dois = 0;

            if (palavra[0] == 'o') um++;
            if (palavra[1] == 'n') um++;
            if (palavra[2] == 'e') um++;

            if (palavra[0] == 't') dois++;
            if (palavra[1] == 'w') dois++;
            if (palavra[2] == 'o') dois++;

            if (um >= 2) printf("1\n");
            else if (dois >= 2) printf("2\n");
        } else if (strlen(palavra) == 5) {
            printf("3\n");
        }
    }

    return 0;
}
