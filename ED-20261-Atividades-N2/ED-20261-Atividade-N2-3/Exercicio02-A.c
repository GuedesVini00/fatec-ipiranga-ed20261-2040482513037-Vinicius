/* RA: 2040482513037 - VINICIUS GUEDES SORIANO PEREIRA */
#include <stdio.h>

float obterMedia(float valores[], int tamanho)
{
    float acumulador = 0.0f;

    for (int i = 0; i < tamanho; i++)
    {
        acumulador += valores[i];
    }

    return acumulador / tamanho;
}

void buscarMaiorMenor(float valores[], int tamanho,
                      float *valorMaximo, float *valorMinimo)
{
    *valorMaximo = valores[0];
    *valorMinimo = valores[0];

    for (int i = 1; i < tamanho; i++)
    {
        if (valores[i] > *valorMaximo)
        {
            *valorMaximo = valores[i];
        }

        if (valores[i] < *valorMinimo)
        {
            *valorMinimo = valores[i];
        }
    }
}

void ajustarValores(float valores[], int tamanho)
{
    float maximo, minimo;

    buscarMaiorMenor(valores, tamanho, &maximo, &minimo);

    for (int i = 0; i < tamanho; i++)
    {
        valores[i] /= maximo;
    }
}

void exibirDados(float valores[], int tamanho, const char *mensagem)
{
    printf("\n%s\n", mensagem);

    for (int i = 0; i < tamanho; i++)
    {
        printf("%.4f ", valores[i]);
    }

    printf("\n");
}

int main()
{
    float notasAlunos[] = {7.5f, 3.2f, 9.8f, 6.0f, 5.5f, 8.1f};
    int quantidade = sizeof(notasAlunos) / sizeof(notasAlunos[0]);

    float mediaTurma;
    float maiorNota;
    float menorNota;

    exibirDados(notasAlunos, quantidade, "Notas originais:");

    mediaTurma = obterMedia(notasAlunos, quantidade);

    buscarMaiorMenor(notasAlunos, quantidade,
                     &maiorNota, &menorNota);

    printf("\nMedia da turma: %.4f\n", mediaTurma);
    printf("Maior nota: %.4f\n", maiorNota);
    printf("Menor nota: %.4f\n", menorNota);

    ajustarValores(notasAlunos, quantidade);

    exibirDados(notasAlunos, quantidade,
                "Notas apos a normalizacao:");

    return 0;
}
