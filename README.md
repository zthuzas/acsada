#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* prox;
} No;

typedef struct {
    No* inicio;
    No* fim;
    int tamanho;
} Lista;

No* criarNo(int n) {
    No* novo = (No*) malloc(sizeof(No));
    if (novo) {
        novo->valor = n;
        novo->prox = NULL;
    }
    return novo;
}

void inicializarLista(Lista* lista) {
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
}

void inserirFinal(Lista* lista, int n) {
    No* novo = criarNo(n);
    if (lista->inicio == NULL) {
        lista->inicio = novo;
        lista->fim = novo;
    } else {
        lista->fim->prox = novo;
        lista->fim = novo;
    }
    lista->tamanho++;
}

void imprimir(Lista* lista) {
    No* aux = lista->inicio;
    while (aux != NULL) {
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
    printf("\n");
}

void ordenarDecrescente(Lista* lista) {
    if (lista->inicio == NULL) return;

    int trocado;
    No* atual;
    No* ultimo = NULL;
    do {
        trocado = 0;
        atual = lista->inicio;

        while (atual->prox != ultimo) {
            if (atual->valor > atual->prox->valor) { // Ordenação decrescente
                int temp = atual->valor;
                atual->valor = atual->prox->valor;
                atual->prox->valor = temp;
                trocado = 1;
            }
            atual = atual->prox;
        }
        ultimo = atual;
    } while (trocado);
}

int main() {
    Lista lista;
    inicializarLista(&lista);

    int n, m;
    scanf("%d %d", &n, &m);

    while (n--) {
        int x;
        scanf("%d", &x);
        inserirFinal(&lista, x);
    }

    while (m--) {
        int v;
        scanf("%d", &v);
        inserirFinal(&lista, v);
    }

    ordenarDecrescente(&lista);
    imprimir(&lista);

    return 0;
}
