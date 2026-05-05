#include <stdio.h>
#include "MINHABIB.h"

// Buscar nó na árvore
No* buscar(No* raiz, int valor) {
    if (raiz == NULL || raiz->valor == valor)
        return raiz;

    if (valor < raiz->valor)
        return buscar(raiz->esq, valor);
    else
        return buscar(raiz->dir, valor);
}

// Nós internos
void imprimir_nos_internos(No* raiz) {
    if (raiz == NULL) return;

    if (raiz->esq != NULL || raiz->dir != NULL)
        printf("%d ", raiz->valor);

    imprimir_nos_internos(raiz->esq);
    imprimir_nos_internos(raiz->dir);
}

// Folhas
void imprimir_folhas(No* raiz) {
    if (raiz == NULL) return;

    if (raiz->esq == NULL && raiz->dir == NULL)
        printf("%d ", raiz->valor);

    imprimir_folhas(raiz->esq);
    imprimir_folhas(raiz->dir);
}

// Impressão por nível
void imprimir_niveis(No* raiz, int nivel) {
    if (raiz == NULL) return;

    if (nivel == 0)
        printf("%d ", raiz->valor);
    else {
        imprimir_niveis(raiz->esq, nivel - 1);
        imprimir_niveis(raiz->dir, nivel - 1);
    }
}

// Altura
int calcular_altura(No* no) {
    if (no == NULL) return -1;

    int esq = calcular_altura(no->esq);
    int dir = calcular_altura(no->dir);

    return (esq > dir ? esq : dir) + 1;
}

// Profundidade (genérico)
int calcular_profundidade(No* raiz, int valor, int nivel) {
    if (raiz == NULL) return -1;

    if (raiz->valor == valor)
        return nivel;

    int esq = calcular_profundidade(raiz->esq, valor, nivel + 1);
    if (esq != -1) return esq;

    return calcular_profundidade(raiz->dir, valor, nivel + 1);
}

// Ancestrais (eficiente)
int imprimir_ancestrais(No* raiz, int valor) {
    if (raiz == NULL) return 0;

    if (raiz->valor == valor)
        return 1;

    if (imprimir_ancestrais(raiz->esq, valor) ||
        imprimir_ancestrais(raiz->dir, valor)) {
        printf("%d ", raiz->valor);
        return 1;
    }

    return 0;
}

// Descendentes
void imprimir_descendentes(No* no) {
    if (no == NULL) return;

    if (no->esq) {
        printf("%d ", no->esq->valor);
        imprimir_descendentes(no->esq);
    }

    if (no->dir) {
        printf("%d ", no->dir->valor);
        imprimir_descendentes(no->dir);
    }
}

// Função principal de análise
void analisar_arvore(No* raiz, int valorBusca) {
    if (raiz == NULL) {
        printf("Arvore vazia\n");
        return;
    }

    printf("Raiz: %d\n", raiz->valor);

    printf("Nos internos: ");
    imprimir_nos_internos(raiz);
    printf("\n");

    printf("Folhas: ");
    imprimir_folhas(raiz);
    printf("\n");

    int altura = calcular_altura(raiz);

    for (int i = 0; i <= altura; i++) {
        printf("Nivel %d: ", i);
        imprimir_niveis(raiz, i);
        printf("\n");
    }

    No* atual = buscar(raiz, valorBusca);

    if (atual == NULL) {
        printf("\nValor nao encontrado\n");
        return;
    }

    int grau = 0;
    if (atual->esq) grau++;
    if (atual->dir) grau++;

    printf("\nNo: %d\n", valorBusca);
    printf("Grau: %d\n", grau);

    printf("Ancestrais: ");
    imprimir_ancestrais(raiz, valorBusca);
    printf("\n");

    printf("Descendentes: ");
    imprimir_descendentes(atual);
    printf("\n");

    printf("Altura: %d\n", calcular_altura(atual));

    printf("Profundidade: %d\n",
           calcular_profundidade(raiz, valorBusca, 0));

    printf("\nSubarvore:\n");

    int altSub = calcular_altura(atual);
    for (int i = 0; i <= altSub; i++) {
        printf("Nivel %d: ", i);
        imprimir_niveis(atual, i);
        printf("\n");
    }
}