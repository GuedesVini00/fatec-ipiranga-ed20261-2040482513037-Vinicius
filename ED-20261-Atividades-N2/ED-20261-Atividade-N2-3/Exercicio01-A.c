/* RA: 2040482513037 - VINICIUS GUEDES SORIANO PEREIRA */
#include <stdio.h>

void inverterValores(int *primeiro, int *segundo)
{
    int auxiliar = *primeiro;
    *primeiro = *segundo;
    *segundo = auxiliar;
}

int main()
{
    int numeroA = 10;
    int numeroB = 20;

    printf("Valores antes da inversao:\n");
    printf("numeroA = %d | endereco = %p\n", numeroA, (void *)&numeroA);
    printf("numeroB = %d | endereco = %p\n", numeroB, (void *)&numeroB);

    inverterValores(&numeroA, &numeroB);

    printf("\nValores apos a inversao:\n");
    printf("numeroA = %d | endereco = %p\n", numeroA, (void *)&numeroA);
    printf("numeroB = %d | endereco = %p\n", numeroB, (void *)&numeroB);

    return 0;
}
