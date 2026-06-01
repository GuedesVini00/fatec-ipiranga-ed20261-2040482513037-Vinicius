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
        No *novoNo = malloc(sizeof(No));

        novoNo->dado = valor;
        novoNo->esq = NULL;
        novoNo->dir = NULL;

        return novoNo;
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

int alturaNo(No *atual)
{
    if (atual == NULL)
    {
        return -1;
    }

    int alturaEsquerda = alturaNo(atual->esq);
    int alturaDireita = alturaNo(atual->dir);

    return (alturaEsquerda > alturaDireita)
           ? alturaEsquerda + 1
           : alturaDireita + 1;
}

int profundidadeNo(No *raiz, int valor, int nivel)
{
    if (raiz == NULL)
    {
        return -1;
    }

    if (raiz->dado == valor)
    {
        return nivel;
    }

    if (valor < raiz->dado)
    {
        return profundidadeNo(raiz->esq, valor, nivel + 1);
    }

    return profundidadeNo(raiz->dir, valor, nivel + 1);
}

int grauNo(No *atual)
{
    if (atual == NULL)
    {
        return -1;
    }

    int quantidade = 0;

    if (atual->esq != NULL)
    {
        quantidade++;
    }

    if (atual->dir != NULL)
    {
        quantidade++;
    }

    return quantidade;
}

void listarAncestrais(No *raiz, int valor)
{
    if (raiz == NULL || raiz->dado == valor)
    {
        return;
    }

    if (valor < raiz->dado)
    {
        listarAncestrais(raiz->esq, valor);
    }
    else
    {
        listarAncestrais(raiz->dir, valor);
    }

    printf("%d ", raiz->dado);
}

void exibirEmOrdem(No *subArvore)
{
    if (subArvore == NULL)
    {
        return;
    }

    exibirEmOrdem(subArvore->esq);
    printf("%d ", subArvore->dado);
    exibirEmOrdem(subArvore->dir);
}

void listarDescendentes(No *raiz, int valor)
{
    No *elemento = buscar(raiz, valor);

    if (elemento == NULL)
    {
        printf("Valor nao encontrado");
        return;
    }

    exibirEmOrdem(elemento->esq);
    exibirEmOrdem(elemento->dir);
}

int totalNos(No *raiz)
{
    if (raiz == NULL)
    {
        return 0;
    }

    return 1 + totalNos(raiz->esq) + totalNos(raiz->dir);
}

int quantidadeDescendentes(No *atual)
{
    if (atual == NULL)
    {
        return 0;
    }

    return totalNos(atual->esq) + totalNos(atual->dir);
}

void mostrarRelatorio(No *raiz, int valor)
{
    No *elemento = buscar(raiz, valor);

    if (elemento == NULL)
    {
        printf("Valor %d nao encontrado.\n", valor);
        return;
    }

    printf("\n================================\n");
    printf("RELATORIO DO NO %d\n", valor);
    printf("================================\n");

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
        listarAncestrais(raiz, valor);
    }

    printf("\n");

    printf("Descendentes: ");

    if (quantidadeDescendentes(elemento) == 0)
    {
        printf("nenhum");
    }
    else
    {
        listarDescendentes(raiz, valor);
    }

    printf("\n");

    printf("Quantidade de descendentes: %d\n",
           quantidadeDescendentes(elemento));

    printf("================================\n");
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

    int elementos[] =
    {
        50, 30, 70, 20, 40,
        60, 80, 10, 25, 45, 65
    };

    int tamanho = sizeof(elementos) / sizeof(elementos[0]);

    for (int indice = 0; indice < tamanho; indice++)
    {
        raiz = inserir(raiz, elementos[indice]);
    }

    mostrarRelatorio(raiz, 50);
    mostrarRelatorio(raiz, 30);
    mostrarRelatorio(raiz, 10);
    mostrarRelatorio(raiz, 70);

    liberarArvore(raiz);

    return 0;
}
