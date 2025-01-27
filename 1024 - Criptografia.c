#include <stdio.h>
#include <string.h>
#include <ctype.h>

void processLine(char *line) {
    int len = strlen(line);
    for (int i = 0; i < len; i++) {
        if (isalpha(line[i])) {
            line[i] += 3;
        }
    }
    for (int i = 0; i < len / 2; i++) {
        char temp = line[i];
        line[i] = line[len - i - 1];
        line[len - i - 1] = temp;
    }
    for (int i = len / 2; i < len; i++) {
        line[i] -= 1;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    getchar();
    while (n--) {
        char line[1001];
        fgets(line, 1001, stdin);
        line[strcspn(line, "\n")] = 0;
        processLine(line);
        printf("%s\n", line);
    }
    return 0;
}
