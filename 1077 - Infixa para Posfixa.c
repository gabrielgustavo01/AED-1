#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 300
#define PILHA_MAX 300

char pilha[PILHA_MAX];
int topo = -1;

void empilhar(char c) {
    if (topo < PILHA_MAX - 1) {
        pilha[++topo] = c;
    }
}

char desempilhar() {
    if (topo >= 0) {
        return pilha[topo--];
    }
    return '\0';
}

char topo_pilha() {
    if (topo >= 0) {
        return pilha[topo];
    }
    return '\0';
}

int precedencia(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

void infixa_para_posfixa(char* infixa, char* posfixa) {
    int i, j = 0;
    for (i = 0; infixa[i] != '\0'; i++) {
        if ((infixa[i] >= 'a' && infixa[i] <= 'z') || (infixa[i] >= 'A' && infixa[i] <= 'Z') || (infixa[i] >= '0' && infixa[i] <= '9')) {
            posfixa[j++] = infixa[i];
        } else if (infixa[i] == '(') {
            empilhar('(');
        } else if (infixa[i] == ')') {
            while (topo_pilha() != '(') {
                posfixa[j++] = desempilhar();
            }
            desempilhar();
        } else {
            while (topo >= 0 && precedencia(topo_pilha()) >= precedencia(infixa[i])) {
                posfixa[j++] = desempilhar();
            }
            empilhar(infixa[i]);
        }
    }
    while (topo >= 0) {
        posfixa[j++] = desempilhar();
    }
    posfixa[j] = '\0';
}

int main() {
    int n;
    char infixa[MAX], posfixa[MAX];

    scanf("%d", &n);
    while (n--) {
        scanf("%s", infixa);
        infixa_para_posfixa(infixa, posfixa);
        printf("%s\n", posfixa);
    }

    return 0;
}
