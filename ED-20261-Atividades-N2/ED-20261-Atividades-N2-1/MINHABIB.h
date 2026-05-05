#ifndef MINHABIB_H
#define MINHABIB_H

typedef struct No {
    int valor;
    struct No *esq;
    struct No *dir;
} No;

// Função principal
void analisar_arvore(No* raiz, int valorBusca);

// Impressões
void imprimir_nos_internos(No* raiz);
void imprimir_folhas(No* raiz);
void imprimir_niveis(No* raiz, int nivel);

// Cálculos
int calcular_altura(No* no);
int calcular_profundidade(No* raiz, int valor, int nivel);

// Funções auxiliares
No* buscar(No* raiz, int valor);
int imprimir_ancestrais(No* raiz, int valor);
void imprimir_descendentes(No* no);

#endif