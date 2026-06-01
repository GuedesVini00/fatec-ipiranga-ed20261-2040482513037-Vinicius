/* RA: 2040482513037 - VINICIUS GUEDES SORIANO PEREIRA */
#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo
{
    int valor;
    struct Nodo *esquerda;
    struct Nodo *direita;
} Nodo;

Nodo *adicionar(Nodo *arvore, int numero)
{
    if (arvore == NULL)
    {
        Nodo *novoNodo = (Nodo *)malloc(sizeof(Nodo));

        if (novoNodo == NULL)
        {
            printf("Falha ao criar nodo.\n");
            exit(EXIT_FAILURE);
        }

        novoNodo->valor = numero;
        novoNodo->esquerda = NULL;
        novoNodo->direita = NULL;

        return novoNodo;
    }

    if (numero < arvore->valor)
    {
        arvore->esquerda = adicionar(arvore->esquerda, numero);
    }
    else if (numero > arvore->valor)
    {
        arvore->direita = adicionar(arvore->direita, numero);
    }

    return arvore;
}

Nodo *localizar(Nodo *arvore, int chave)
{
    if (arvore == NULL || arvore->valor == chave)
    {
        return arvore;
    }

    if (chave < arvore->valor)
    {
        return localizar(arvore->esquerda, chave);
    }

    return localizar(arvore->direita, chave);
}

int obterAltura(Nodo *raiz)
{
    if (raiz == NULL)
    {
        return -1;
    }

    int alturaEsquerda = obterAltura(raiz->esquerda);
    int alturaDireita = obterAltura(raiz->direita);

    return (alturaEsquerda > alturaDireita)
               ? alturaEsquerda + 1
               : alturaDireita + 1;
}

int obterProfundidade(Nodo *raiz, int elemento, int nivel)
{
    if (raiz == NULL)
    {
        return -1;
    }

    if (raiz->valor == elemento)
    {
        return nivel;
    }

    if (elemento < raiz->valor)
    {
        return obterProfundidade(
            raiz->esquerda,
            elemento,
            nivel + 1
        );
    }

    return obterProfundidade(
        raiz->direita,
        elemento,
        nivel + 1
    );
}

int contarFilhos(Nodo *nodo)
{
    if (nodo == NULL)
    {
        return -1;
    }

    int filhos = 0;

    if (nodo->esquerda)
    {
        filhos++;
    }

    if (nodo->direita)
    {
        filhos++;
    }

    return filhos;
}

void listarGraus(Nodo *raiz)
{
    if (raiz == NULL)
    {
        return;
    }

    listarGraus(raiz->esquerda);

    printf("Elemento %d possui grau %d\n",
           raiz->valor,
           contarFilhos(raiz));

    listarGraus(raiz->direita);
}

void destruir(Nodo *raiz)
{
    if (!raiz)
    {
        return;
    }

    destruir(raiz->esquerda);
    destruir(raiz->direita);

    free(raiz);
}

int main()
{
    Nodo *arvore = NULL;

    int numeros[] =
    {
        50, 30, 70, 20, 40,
        60, 80, 10, 25, 45, 65
    };

    int totalNumeros =
        sizeof(numeros) / sizeof(numeros[0]);

    for (int i = 0; i < totalNumeros; i++)
    {
        arvore = adicionar(arvore, numeros[i]);
    }

    int elementosAltura[] = {50, 30, 70, 20, 10};

    printf("Consulta de alturas:\n");

    for (int i = 0; i < 5; i++)
    {
        Nodo *resultado =
            localizar(arvore, elementosAltura[i]);

        printf("Nodo %d -> altura %d\n",
               elementosAltura[i],
               obterAltura(resultado));
    }

    int elementosProfundidade[] = {50, 30, 70, 45, 10};

    printf("\nConsulta de profundidades:\n");

    for (int i = 0; i < 5; i++)
    {
        printf("Nodo %d -> profundidade %d\n",
               elementosProfundidade[i],
               obterProfundidade(
                   arvore,
                   elementosProfundidade[i],
                   0));
    }

    printf("\nGraus dos nodos (em ordem crescente):\n");
    listarGraus(arvore);

    printf("\nAltura geral da arvore: %d\n",
           obterAltura(arvore));

    destruir(arvore);

    return 0;
}
