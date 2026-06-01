/* RA: 2040482513037 - VINICIUS GUEDES SORIANO PEREIRA */
#include <stdio.h>

int totalMovimentos = 0;

void torreDeHanoi(int quantidadeDiscos, char torreInicial,
                  char torreFinal, char torreAuxiliar)
{
    if (quantidadeDiscos == 1)
    {
        printf("Disco 1: %c -> %c\n", torreInicial, torreFinal);
        totalMovimentos++;
        return;
    }

    torreDeHanoi(quantidadeDiscos - 1,
                 torreInicial,
                 torreAuxiliar,
                 torreFinal);

    printf("Disco %d: %c -> %c\n",
           quantidadeDiscos,
           torreInicial,
           torreFinal);

    totalMovimentos++;

    torreDeHanoi(quantidadeDiscos - 1,
                 torreAuxiliar,
                 torreFinal,
                 torreInicial);
}

int calcularPotenciaDeDois(int expoente)
{
    int valor = 1;

    for (int i = 1; i <= expoente; i++)
    {
        valor *= 2;
    }

    return valor;
}

int main()
{
    for (int discos = 1; discos <= 6; discos++)
    {
        totalMovimentos = 0;

        printf("\n===== %d disco(s) =====\n", discos);

        torreDeHanoi(discos, 'A', 'C', 'B');

        printf("Total de movimentos realizados: %d\n",
               totalMovimentos);

        printf("Valor teorico (2^n - 1): %d\n",
               calcularPotenciaDeDois(discos) - 1);
    }

    return 0;
}
