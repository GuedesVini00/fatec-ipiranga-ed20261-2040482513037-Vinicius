/* RA: 2040482513037 - VINICIUS GUEDES SORIANO PEREIRA */
#include <stdio.h>

void hanoi(int n, char origem, char destino, char auxiliar)
{
    if (n == 1)
    {
        printf("Mover disco 1 de %c para %c\n", origem, destino);
        return;
    }

    hanoi(n - 1, origem, auxiliar, destino);
    printf("Mover disco %d de %c para %c\n", n, origem, destino);
    hanoi(n - 1, auxiliar, destino, origem);
}

int main(void)
{
    hanoi(3, 'A', 'C', 'B');

    return 0;
}
