/* RA: 2040482513037 - VINICIUS GUEDES SORIANO PEREIRA */
#include <stdio.h>

void inverterElementos(int *esquerda, int *direita)
{
    int temp = *esquerda;
    *esquerda = *direita;
    *direita = temp;
}

int main()
{
    int numeros[] = {10, 20, 30, 40, 50};

    int *primeiro = numeros;
    int *ultimo = numeros + 4;

    while (primeiro < ultimo)
    {
        inverterElementos(primeiro, ultimo);

        primeiro++;
        ultimo--;
    }

    printf("Elementos do vetor em ordem inversa:\n");

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", numeros[i]);
    }

    printf("\n");

    return 0;
}
