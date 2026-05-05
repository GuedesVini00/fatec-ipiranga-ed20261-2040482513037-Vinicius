#include <stdio.h>
#include <stdlib.h>
#include "MINHABIB.h"

No* criar_no(int valor) {
    No* novo = (No*) malloc(sizeof(No));

    if (novo == NULL) {
        printf("Erro de alocacao de memoria!\n");
        exit(1);
    }

    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;

    return novo;
}

No* inserir(No* raiz, int valor) {
    if (raiz == NULL)
        return criar_no(valor);

    if (valor < raiz->valor)
        raiz->esq = inserir(raiz->esq, valor);
    else
        raiz->dir = inserir(raiz->dir, valor);

    return raiz;
}

// Liberar memória (importante!)
void liberar_arvore(No* raiz) {
    if (raiz == NULL) return;

    liberar_arvore(raiz->esq);
    liberar_arvore(raiz->dir);
    free(raiz);
}

int main() {
    No* raiz = NULL;

    int valores[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(valores) / sizeof(valores[0]);

    for (int i = 0; i < n; i++)
        raiz = inserir(raiz, valores[i]);

    analisar_arvore(raiz, 30);

    liberar_arvore(raiz); // evita vazamento de memória

    return 0;
}