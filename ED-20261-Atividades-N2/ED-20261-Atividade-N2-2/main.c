//AUTOR: VINICIUS GUEDES

#include <stdio.h>
#include "MINHABIB.h"

void imprimir_nos_internos(No* raiz) {
    if (raiz == NULL)
        return;

    if (raiz->esq != NULL || raiz->dir != NULL)
        printf("%d (%p) ", raiz->valor, (void*)raiz);

    imprimir_nos_internos(raiz->esq);
    imprimir_nos_internos(raiz->dir);
}

void imprimir_folhas(No* raiz) {
    if (raiz == NULL)
        return;

    if (raiz->esq == NULL && raiz->dir == NULL)
        printf("%d (%p) ", raiz->valor, (void*)raiz);

    imprimir_folhas(raiz->esq);
    imprimir_folhas(raiz->dir);
}

void imprimir_niveis(No* raiz, int nivel) {
    if (raiz == NULL)
        return;

    if (nivel == 0) {
        printf("%d (%p) ", raiz->valor, (void*)raiz);
    } else {
        imprimir_niveis(raiz->esq, nivel - 1);
        imprimir_niveis(raiz->dir, nivel - 1);
    }
}

int calcular_altura(No* no) {
    if (no == NULL)
        return -1;

    int esq = calcular_altura(no->esq);
    int dir = calcular_altura(no->dir);

    return (esq > dir ? esq : dir) + 1;
}

int calcular_profundidade(No* raiz, int valor, int nivel) {
    if (raiz == NULL)
        return -1;

    if (raiz->valor == valor)
        return nivel;

    if (valor < raiz->valor)
        return calcular_profundidade(raiz->esq, valor, nivel + 1);
    else
        return calcular_profundidade(raiz->dir, valor, nivel + 1);
}

void imprimir_ancestrais(No* raiz, int valor) {
    if (raiz == NULL)
        return;

    if (valor < raiz->valor) {
        printf("%d ", raiz->valor);
        imprimir_ancestrais(raiz->esq, valor);
    }
    else if (valor > raiz->valor) {
        printf("%d ", raiz->valor);
        imprimir_ancestrais(raiz->dir, valor);
    }
}

void imprimir_descendentes(No* no) {
    if (no == NULL)
        return;

    if (no->esq != NULL) {
        printf("%d (%p) ", no->esq->valor, (void*)no->esq);
        imprimir_descendentes(no->esq);
    }

    if (no->dir != NULL) {
        printf("%d (%p) ", no->dir->valor, (void*)no->dir);
        imprimir_descendentes(no->dir);
    }
}

int fator_balanceamento(No* no) {
    if (no == NULL)
        return 0;

    return calcular_altura(no->esq) -
           calcular_altura(no->dir);
}

void verificar_balanceamento(No* no) {
    if (no == NULL)
        return;

    int fb = fator_balanceamento(no);

    printf("No %d -> FB = %d ", no->valor, fb);

    if (fb < -1 || fb > 1)
        printf("(DESBALANCEADO)");
    else
        printf("(BALANCEADO)");

    printf("\n");

    verificar_balanceamento(no->esq);
    verificar_balanceamento(no->dir);
}

void analisar_arvore(No* raiz, int valorBusca) {
    if (raiz == NULL) {
        printf("Arvore vazia\n");
        return;
    }

    printf("Raiz: %d (%p)\n", raiz->valor, (void*)raiz);

    printf("\nNos internos: ");
    imprimir_nos_internos(raiz);

    printf("\n\nFolhas: ");
    imprimir_folhas(raiz);

    printf("\n");

    int altura = calcular_altura(raiz);

    printf("\nNiveis da arvore:\n");

    for (int i = 0; i <= altura; i++) {
        printf("Nivel %d: ", i);
        imprimir_niveis(raiz, i);
        printf("\n");
    }

    No* atual = raiz;

    while (atual != NULL && atual->valor != valorBusca) {
        if (valorBusca < atual->valor)
            atual = atual->esq;
        else
            atual = atual->dir;
    }

    if (atual == NULL) {
        printf("\nValor nao encontrado\n");
        return;
    }

    int grau = 0;

    if (atual->esq != NULL)
        grau++;

    if (atual->dir != NULL)
        grau++;

    printf("\n---------------------------\n");
    printf("No encontrado: %d (%p)\n", atual->valor, (void*)atual);

    printf("Grau: %d\n", grau);

    printf("Ancestrais: ");

    if (atual == raiz)
        printf("NULL");
    else
        imprimir_ancestrais(raiz, valorBusca);

    printf("\n");

    printf("Descendentes: ");

    if (atual->esq == NULL && atual->dir == NULL)
        printf("NULL");
    else
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

    printf("\nBalanceamento AVL:\n");
    verificar_balanceamento(raiz);
}
