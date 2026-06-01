/* RA: 2040482513037 - VINICIUS GUEDES SORIANO PEREIRA */

#include <stdio.h>

int pesquisarBinariamente(int vetor[], int esquerda, int direita,
                          int valorProcurado, int *contador)
{
    (*contador)++;

    if (esquerda > direita)
    {
        return -1;
    }

    int centro = esquerda + (direita - esquerda) / 2;

    if (vetor[centro] == valorProcurado)
    {
        return centro;
    }

    if (valorProcurado < vetor[centro])
    {
        return pesquisarBinariamente(vetor,
                                     esquerda,
                                     centro - 1,
                                     valorProcurado,
                                     contador);
    }

    return pesquisarBinariamente(vetor,
                                 centro + 1,
                                 direita,
                                 valorProcurado,
                                 contador);
}

int main()
{
    int numerosOrdenados[] = {2, 5, 8, 12, 16, 23, 38, 45, 72, 91};
    int quantidadeElementos =
        sizeof(numerosOrdenados) / sizeof(numerosOrdenados[0]);

    int valoresBusca[] = {23, 50, 2};

    for (int indice = 0; indice < 3; indice++)
    {
        int totalChamadas = 0;

        int posicao = pesquisarBinariamente(
            numerosOrdenados,
            0,
            quantidadeElementos - 1,
            valoresBusca[indice],
            &totalChamadas
        );

        printf("Procurando o valor %d...\n", valoresBusca[indice]);

        if (posicao >= 0)
        {
            printf("Resultado: encontrado na posicao %d\n", posicao);
        }
        else
        {
            printf("Resultado: valor inexistente no vetor\n");
        }

        printf("Numero de chamadas da funcao: %d\n\n",
               totalChamadas);
    }

    return 0;
}
