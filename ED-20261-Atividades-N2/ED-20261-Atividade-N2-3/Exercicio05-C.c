/* RA: 2040482513037 - VINICIUS GUEDES SORIANO PEREIRA */
#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo
{
    int chave;
    struct Nodo *esquerdo;
    struct Nodo *direito;
} Nodo;

Nodo *inserirElemento(Nodo *raiz, int valor)
{
    if (raiz == NULL)
    {
        Nodo *novo = (Nodo *)malloc(sizeof(Nodo));

        if (!novo)
        {
            printf("Erro de memoria.\n");
            exit(EXIT_FAILURE);
        }

        novo->chave = valor;
        novo->esquerdo = NULL;
        novo->direito = NULL;

        return novo;
    }

    if (valor < raiz->chave)
    {
        raiz->esquerdo = inserirElemento(raiz->esquerdo, valor);
    }
    else if (valor > raiz->chave)
    {
        raiz->direito = inserirElemento(raiz->direito, valor);
    }

    return raiz;
}

Nodo *procurarElemento(Nodo *raiz, int valor)
{
    if (raiz == NULL || raiz->chave == valor)
    {
        return raiz;
    }

    if (valor < raiz->chave)
    {
        return procurarElemento(raiz->esquerdo, valor);
    }

    return procurarElemento(raiz->direito, valor);
}

int calcularAltura(Nodo *raiz)
{
    if (raiz == NULL)
    {
        return -1;
    }

    int alturaEsquerda = calcularAltura(raiz->esquerdo);
    int alturaDireita = calcularAltura(raiz->direito);

    return (alturaEsquerda > alturaDireita)
           ? alturaEsquerda + 1
           : alturaDireita + 1;
}

int calcularProfundidade(Nodo *raiz, int valor, int nivelAtual)
{
    if (raiz == NULL)
    {
        return -1;
    }

    if (raiz->chave == valor)
    {
        return nivelAtual;
    }

    if (valor < raiz->chave)
    {
        return calcularProfundidade(
            raiz->esquerdo,
            valor,
            nivelAtual + 1
        );
    }

    return calcularProfundidade(
        raiz->direito,
        valor,
        nivelAtual + 1
    );
}

int obterGrau(Nodo *raiz)
{
    if (raiz == NULL)
    {
        return -1;
    }

    int quantidadeFilhos = 0;

    if (raiz->esquerdo != NULL)
    {
        quantidadeFilhos++;
    }

    if (raiz->direito != NULL)
    {
        quantidadeFilhos++;
    }

    return quantidadeFilhos;
}

void removerArvore(Nodo *raiz)
{
    if (raiz == NULL)
    {
        return;
    }

    removerArvore(raiz->esquerdo);
    removerArvore(raiz->direito);

    free(raiz);
}

int main()
{
    Nodo *arvore = NULL;

    int elementos[] =
    {
        50, 30, 70, 20, 40,
        60, 80, 10, 25, 45, 65
    };

    int quantidadeElementos =
        sizeof(elementos) / sizeof(elementos[0]);

    for (int i = 0; i < quantidadeElementos; i++)
    {
        arvore = inserirElemento(arvore, elementos[i]);
    }

    Nodo *raizPrincipal = procurarElemento(arvore, 50);
    Nodo *subArvore = procurarElemento(arvore, 30);
    Nodo *folha = procurarElemento(arvore, 10);

    printf("Dados do nodo 50\n");
    printf("Altura: %d\n", calcularAltura(raizPrincipal));
    printf("Profundidade: %d\n",
           calcularProfundidade(arvore, 50, 0));
    printf("Grau: %d\n\n", obterGrau(raizPrincipal));

    printf("Dados do nodo 30\n");
    printf("Altura: %d\n", calcularAltura(subArvore));
    printf("Profundidade: %d\n",
           calcularProfundidade(arvore, 30, 0));
    printf("Grau: %d\n\n", obterGrau(subArvore));

    printf("Dados do nodo 10\n");
    printf("Altura: %d\n", calcularAltura(folha));
    printf("Profundidade: %d\n",
           calcularProfundidade(arvore, 10, 0));
    printf("Grau: %d\n", obterGrau(folha));

    removerArvore(arvore);

    return 0;
}
