/* RA: 2040482513037 - VINICIUS GUEDES SORIANO PEREIRA */
#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo
{
    int valor;
    struct Nodo *filhoEsquerdo;
    struct Nodo *filhoDireito;
} Nodo;

Nodo *adicionarNodo(Nodo *arvore, int chave)
{
    if (arvore == NULL)
    {
        Nodo *novoNodo = (Nodo *)malloc(sizeof(Nodo));

        novoNodo->valor = chave;
        novoNodo->filhoEsquerdo = NULL;
        novoNodo->filhoDireito = NULL;

        return novoNodo;
    }

    if (chave < arvore->valor)
    {
        arvore->filhoEsquerdo =
            adicionarNodo(arvore->filhoEsquerdo, chave);
    }
    else if (chave > arvore->valor)
    {
        arvore->filhoDireito =
            adicionarNodo(arvore->filhoDireito, chave);
    }

    return arvore;
}

Nodo *localizarNodo(Nodo *arvore, int chave)
{
    if (arvore == NULL || arvore->valor == chave)
    {
        return arvore;
    }

    if (chave < arvore->valor)
    {
        return localizarNodo(arvore->filhoEsquerdo, chave);
    }

    return localizarNodo(arvore->filhoDireito, chave);
}

void exibirAncestrais(Nodo *arvore, int chave)
{
    if (arvore == NULL || arvore->valor == chave)
    {
        return;
    }

    if (chave < arvore->valor)
    {
        exibirAncestrais(arvore->filhoEsquerdo, chave);
    }
    else
    {
        exibirAncestrais(arvore->filhoDireito, chave);
    }

    printf("%d ", arvore->valor);
}

void percorrerEmOrdem(Nodo *raiz)
{
    if (raiz == NULL)
    {
        return;
    }

    percorrerEmOrdem(raiz->filhoEsquerdo);
    printf("%d ", raiz->valor);
    percorrerEmOrdem(raiz->filhoDireito);
}

void exibirDescendentes(Nodo *arvore, int chave)
{
    Nodo *nodoEncontrado = localizarNodo(arvore, chave);

    if (nodoEncontrado == NULL)
    {
        printf("Elemento nao localizado");
        return;
    }

    percorrerEmOrdem(nodoEncontrado->filhoEsquerdo);
    percorrerEmOrdem(nodoEncontrado->filhoDireito);
}

int quantidadeNodos(Nodo *raiz)
{
    if (raiz == NULL)
    {
        return 0;
    }

    return 1
           + quantidadeNodos(raiz->filhoEsquerdo)
           + quantidadeNodos(raiz->filhoDireito);
}

int totalDescendentes(Nodo *raiz)
{
    if (raiz == NULL)
    {
        return 0;
    }

    return quantidadeNodos(raiz->filhoEsquerdo)
           + quantidadeNodos(raiz->filhoDireito);
}

void destruirArvore(Nodo *arvore)
{
    if (arvore == NULL)
    {
        return;
    }

    destruirArvore(arvore->filhoEsquerdo);
    destruirArvore(arvore->filhoDireito);

    free(arvore);
}

int main()
{
    Nodo *raiz = NULL;

    int numeros[] =
    {
        50, 30, 70, 20, 40,
        60, 80, 10, 25, 45, 65
    };

    int quantidade =
        sizeof(numeros) / sizeof(numeros[0]);

    for (int i = 0; i < quantidade; i++)
    {
        raiz = adicionarNodo(raiz, numeros[i]);
    }

    printf("Nos ancestrais de 30: ");
    exibirAncestrais(raiz, 30);

    printf("\nNos descendentes de 30: ");
    exibirDescendentes(raiz, 30);

    Nodo *elemento30 = localizarNodo(raiz, 30);

    printf("\nTotal de descendentes de 30: %d\n",
           totalDescendentes(elemento30));

    destruirArvore(raiz);

    return 0;
}
