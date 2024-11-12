#include <stdio.h>
#include <stdlib.h>

// Estrutura para um nó da pilha
typedef struct StackNode {
    char data;
    struct StackNode* next;
} StackNode;

// Função para criar um novo nó da pilha
StackNode* createStackNode(char data) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    if (!newNode) {
        printf("Erro ao alocar memória\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Função para empilhar um nó
void push(StackNode** top, char data) {
    StackNode* newNode = createStackNode(data);
    newNode->next = *top;
    *top = newNode;
}

// Função para desempilhar um nó
char pop(StackNode** top) {
    if (*top == NULL) {
        return '\0'; // Retorna nulo se a pilha estiver vazia
    }
    StackNode* temp = *top;
    *top = (*top)->next;
    char data = temp->data;
    free(temp);
    return data;
}

// Função para verificar se os parênteses estão balanceados
int isBalanced(char* expression) {
    StackNode* stack = NULL;
    for (int i = 0; expression[i] != '\0'; i++) {
        if (expression[i] == '(') {
            push(&stack, '(');
        } else if (expression[i] == ')') {
            if (pop(&stack) == '\0') {
                return 0; // Encontrou um ')' sem um '(' correspondente
            }
        }
    }
    return stack == NULL; // Verifica se a pilha está vazia
}

int main() {
    char expression[1001];

    while (scanf("%s", expression) != EOF) {
        if (isBalanced(expression)) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
    }

    return 0;
}
