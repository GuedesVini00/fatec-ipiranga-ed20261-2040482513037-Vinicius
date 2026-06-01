/* RA: 2040482513037 - VINICIUS GUEDES SORIANO PEREIRA */
#include <stdio.h>

int main()
{
    int numeros[] = {10, 20, 30, 40, 50};
    int total = 0;

    int *ponteiroNumeros = numeros;

    for (int i = 0; i < 5; i++)
    {
        printf("Elemento: %d | Endereco de memoria: %p\n",
               *(ponteiroNumeros + i),
               (void *)(ponteiroNumeros + i));

        total += *(ponteiroNumeros + i);
    }

    printf("\nTotal da soma dos elementos = %d\n", total);

    return 0;
}
