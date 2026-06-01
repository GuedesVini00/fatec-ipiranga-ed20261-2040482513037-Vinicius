/* RA: 2040482513037 - VINICIUS GUEDES SORIANO PEREIRA */
#include <stdio.h>

int contadorMovimentos = 0;

void exibirRecuo(int nivel)
{
    for (int i = 0; i < nivel; i++)
    {
        printf("  ");
    }
}

void resolverHanoi(int discos, char torreOrigem,
                   char torreDestino, char torreAuxiliar,
                   int profundidade)
{
    if (discos == 1)
    {
        exibirRecuo(profundidade);

        printf("[Profundidade %d] Disco 1: %c -> %c\n",
               profundidade,
               torreOrigem,
               torreDestino);

        contadorMovimentos++;
        return;
    }

    resolverHanoi(discos - 1,
                  torreOrigem,
                  torreAuxiliar,
                  torreDestino,
                  profundidade + 1);

    exibirRecuo(profundidade);

    printf("[Profundidade %d] Disco %d: %c -> %c\n",
           profundidade,
           discos,
           torreOrigem,
           torreDestino);

    contadorMovimentos++;

    resolverHanoi(discos - 1,
                  torreAuxiliar,
                  torreDestino,
                  torreOrigem,
                  profundidade + 1);
}

int main()
{
    int casosTeste[] = {1, 3, 4};
    int quantidadeCasos = 3;

    for (int indice = 0; indice < quantidadeCasos; indice++)
    {
        contadorMovimentos = 0;

        printf("\n===== Caso %d (n = %d) =====\n", indice + 1, casosTeste[indice]);

        resolverHanoi(casosTeste[indice],'A', 'C','B',0);

        printf("Quantidade total de movimentos: %d\n",
               contadorMovimentos);
    }

    return 0;
}
