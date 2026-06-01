/* RA: 2040482513037 - VINICIUS GUEDES SORIANO PEREIRA */
#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo
{
    int valor;
    struct Nodo *filhoEsquerdo;
    struct Nodo *filhoDireito;
} Nodo;

Nodo *adicionarNodo(Nodo *arvore, int elemento)
{
    if (arvore == NULL)
    {
        Nodo *novoNodo = (Nodo *)malloc(sizeof(Nodo));

        if (novoNodo == NULL)
        {
            printf("Falha na alocacao de memoria.\n");
            exit(EXIT_FAILURE);
        }

        novoNodo->valor = elemento;
        novoNodo->filhoEsquerdo = NULL;
        novoNodo->filhoDireito = NULL;

        return novoNodo;
    }

    if (elemento < arvore->valor)
    {
        arvore->filhoEsquerdo =
            adicionarNodo(arvore->filhoEsquerdo, elemento);
    }
    else if (elemento > arvore->valor)
    {
        arvore->filhoDireito =
            adicionarNodo(arvore->filhoDireito, elemento);
    }

    return arvore;
}

int calcularAltura(Nodo *raiz)
{
    if (raiz == NULL)
    {
        return -1;
    }

    int ladoEsquerdo = calcularAltura(raiz->filhoEsquerdo);
    int ladoDireito = calcularAltura(raiz->filhoDireito);

    return (ladoEsquerdo > ladoDireito)
               ? ladoEsquerdo + 1
               : ladoDireito + 1;
}

int localizarProfundidade(Nodo *raiz, int chave, int nivelAtual)
{
    if (raiz == NULL)
    {
        return -1;
    }

    if (raiz->valor == chave)
    {
        return nivelAtual;
    }

    if (chave < raiz->valor)
    {
        return localizarProfundidade(
            raiz->filhoEsquerdo,
            chave,
            nivelAtual + 1);
    }

    return localizarProfundidade(
        raiz->filhoDireito,
        chave,
        nivelAtual + 1);
}

int quantidadeFilhos(Nodo *raiz)
{
    if (raiz == NULL)
    {
        return -1;
    }

    int total = 0;

    if (raiz->filhoEsquerdo)
    {
        total++;
    }

    if (raiz->filhoDireito)
    {
        total++;
    }

    return total;
}

void destruirArvore(Nodo *raiz)
{
    if (!raiz)
    {
        return;
    }

    destruirArvore(raiz->filhoEsquerdo);
    destruirArvore(raiz->filhoDireito);

    free(raiz);
}

int main()
{
    Nodo *arvoreBinaria = NULL;

    int elementos[] =
    {
        50, 30, 70, 20, 40,
        60, 80, 10, 25, 45, 65
    };

    int quantidade =
        sizeof(elementos) / sizeof(elementos[0]);

    for (int indice = 0; indice < quantidade; indice++)
    {
        arvoreBinaria =
            adicionarNodo(arvoreBinaria, elementos[indice]);
    }

    printf("Estrutura criada com sucesso!\n");

    printf("Altura da arvore: %d\n",
           calcularAltura(arvoreBinaria));

    printf("Profundidade do elemento 45: %d\n",
           localizarProfundidade(arvoreBinaria, 45, 0));

    printf("Quantidade de filhos da raiz: %d\n",
           quantidadeFilhos(arvoreBinaria));

    destruirArvore(arvoreBinaria);

    return 0;
}
