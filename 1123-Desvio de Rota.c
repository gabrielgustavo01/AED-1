#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_CIDADES 250
#define INF INT_MAX

typedef struct {
    int destino, custo;
} Estrada;

typedef struct {
    Estrada estradas[MAX_CIDADES * 2];
    int tamanho;
} ListaAdj;

ListaAdj grafo[MAX_CIDADES];
int dist[MAX_CIDADES];
int visitado[MAX_CIDADES];

void inicializar_grafo(int n) {
    for (int i = 0; i < n; i++) {
        grafo[i].tamanho = 0;
    }
}

void adicionar_estrada(int origem, int destino, int custo) {
    grafo[origem].estradas[grafo[origem].tamanho].destino = destino;
    grafo[origem].estradas[grafo[origem].tamanho].custo = custo;
    grafo[origem].tamanho++;
}

void dijkstra(int n, int inicio, int limite) {
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visitado[i] = 0;
    }

    dist[inicio] = 0;

    for (int i = 0; i < n; i++) {
        int u = -1;
        for (int j = 0; j < n; j++) {
            if (!visitado[j] && (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }

        if (dist[u] == INF) break;

        visitado[u] = 1;

        for (int k = 0; k < grafo[u].tamanho; k++) {
            int v = grafo[u].estradas[k].destino;
            int custo = grafo[u].estradas[k].custo;

            if (u < limite && v != u + 1) continue; // Respeitar a rota de serviço

            if (dist[u] + custo < dist[v]) {
                dist[v] = dist[u] + custo;
            }
        }
    }
}

int main() {
    int n, m, c, k;

    while (scanf("%d %d %d %d", &n, &m, &c, &k), n || m || c || k) {
        inicializar_grafo(n);

        for (int i = 0; i < m; i++) {
            int u, v, p;
            scanf("%d %d %d", &u, &v, &p);
            adicionar_estrada(u, v, p);
            adicionar_estrada(v, u, p);
        }

        dijkstra(n, k, c);

        printf("%d\n", dist[c - 1]);
    }

    return 0;
}
