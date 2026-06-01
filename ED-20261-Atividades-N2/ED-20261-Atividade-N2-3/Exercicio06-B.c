/* RA: 2040482513037 - VINICIUS GUEDES SORIANO PEREIRA */
#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int dado;
    struct No *esq;
    struct No *dir;
} No;

No *inserir(No *raiz, int valor)
{
    if (raiz == NULL)
    {
        No *novoElemento = malloc(sizeof(No));

        novoElemento->dado = valor;
        novoElemento->esq = NULL;
        novoElemento->dir = NULL;

        return novoElemento;
    }

    if (valor < raiz->dado)
    {
        raiz->esq = inserir(raiz->esq, valor);
    }
    else if (valor > raiz->dado)
    {
        raiz->dir = inserir(raiz->dir, valor);
    }

    return raiz;
}

No *buscar(No *raiz, int valor)
{
    if (raiz == NULL || raiz->dado == valor)
    {
        return raiz;
    }

    if (valor < raiz->dado)
    {
        return buscar(raiz->esq, valor);
    }

    return buscar(raiz->dir, valor);
}

int alturaNo(No *elemento)
{
    if (elemento == NULL)
    {
        return -1;
    }

    int alturaEsquerda = alturaNo(elemento->esq);
    int alturaDireita = alturaNo(elemento->dir);

    if (alturaEsquerda > alturaDireita)
    {
        return alturaEsquerda + 1;
    }

    return alturaDireita + 1;
}

int profundidadeNo(No *raiz, int valor, int nivelAtual)
{
    if (raiz == NULL)
    {
        return -1;
    }

    if (raiz->dado == valor)
    {
        return nivelAtual;
    }

    if (valor < raiz->dado)
    {
        return profundidadeNo(raiz->esq, valor, nivelAtual + 1);
    }

    return profundidadeNo(raiz->dir, valor, nivelAtual + 1);
}

int grauNo(No *elemento)
{
    if (elemento == NULL)
    {
        return -1;
    }

    int quantidadeFilhos = 0;

    if (elemento->esq != NULL)
    {
        quantidadeFilhos++;
    }

    if (elemento->dir != NULL)
    {
        quantidadeFilhos++;
    }

    return quantidadeFilhos;
}

void imprimirAncestral(No *raiz, int valor)
{
    if (raiz == NULL || raiz->dado == valor)
    {
        return;
    }

    if (valor < raiz->dado)
    {
        imprimirAncestral(raiz->esq, valor);
    }
    else
    {
        imprimirAncestral(raiz->dir, valor);
    }

    printf("%d ", raiz->dado);
}

void imprimirSubarvoreEmOrdem(No *raizSubarvore)
{
    if (raizSubarvore == NULL)
    {
        return;
    }

    imprimirSubarvoreEmOrdem(raizSubarvore->esq);
    printf("%d ", raizSubarvore->dado);
    imprimirSubarvoreEmOrdem(raizSubarvore->dir);
}

void imprimirDescendentes(No *raiz, int valor)
{
    No *elementoEncontrado = buscar(raiz, valor);

    if (elementoEncontrado == NULL)
    {
        printf("Valor nao encontrado");
        return;
    }

    imprimirSubarvoreEmOrdem(elementoEncontrado->esq);
    imprimirSubarvoreEmOrdem(elementoEncontrado->dir);
}

int contarNos(No *raizSubarvore)
{
    if (raizSubarvore == NULL)
    {
        return 0;
    }

    return 1 +
           contarNos(raizSubarvore->esq) +
           contarNos(raizSubarvore->dir);
}

int contarDescendentes(No *elemento)
{
    if (elemento == NULL)
    {
        return 0;
    }

    return contarNos(elemento->esq) +
           contarNos(elemento->dir);
}

void relatorioNo(No *raiz, int valor)
{
    No *elemento = buscar(raiz, valor);

    if (elemento == NULL)
    {
        printf("Erro: valor %d nao encontrado na arvore.\n", valor);
        return;
    }

    printf("\n====================================\n");
    printf("Relatorio do no %d\n", valor);
    printf("====================================\n");

    printf("Profundidade: %d\n",
           profundidadeNo(raiz, valor, 0));

    printf("Altura: %d\n",
           alturaNo(elemento));

    printf("Grau: %d\n",
           grauNo(elemento));

    printf("Ancestrais: ");

    if (valor == raiz->dado)
    {
        printf("nenhum");
    }
    else
    {
        imprimirAncestral(raiz, valor);
    }

    printf("\n");

    printf("Descendentes: ");

    if (contarDescendentes(elemento) == 0)
    {
        printf("nenhum");
    }
    else
    {
        imprimirDescendentes(raiz, valor);
    }

    printf("\n");

    printf("Quantidade de descendentes: %d\n",
           contarDescendentes(elemento));

    printf("====================================\n");
}

void liberarArvore(No *raiz)
{
    if (raiz == NULL)
    {
        return;
    }

    liberarArvore(raiz->esq);
    liberarArvore(raiz->dir);

    free(raiz);
}

int main()
{
    No *raiz = NULL;

    int valores[] = {
        50, 30, 70, 20, 40,
        60, 80, 10, 25, 45, 65
    };

    int quantidadeValores =
        sizeof(valores) / sizeof(valores[0]);

    for (int indice = 0; indice < quantidadeValores; indice++)
    {
        raiz = inserir(raiz, valores[indice]);
    }

    relatorioNo(raiz, 30);

    liberarArvore(raiz);

    return 0;
}
