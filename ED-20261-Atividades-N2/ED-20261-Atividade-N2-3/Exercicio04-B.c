/* RA: 2040482513037 - VINICIUS GUEDES SORIANO PEREIRA */
#include <stdio.h>

long long exponenciacaoOtimizada(long long numero, int potencia, int *contadorChamadas)
{
    (*contadorChamadas)++;

    if (potencia == 0)
    {
        return 1;
    }

    if (potencia % 2 == 0)
    {
        long long resultadoParcial =
            exponenciacaoOtimizada(numero,
                                  potencia / 2,
                                  contadorChamadas);

        return resultadoParcial * resultadoParcial;
    }

    return numero *
           exponenciacaoOtimizada(numero,
                                 potencia - 1,
                                 contadorChamadas);
}

long long exponenciacaoSimples(long long numero, int potencia, int *contadorChamadas)
{
    (*contadorChamadas)++;

    if (potencia == 0)
    {
        return 1;
    }

    return numero *
           exponenciacaoSimples(numero,
                               potencia - 1,
                               contadorChamadas);
}

int main()
{
    long long valoresBase[] = {2, 3, 5, 7};
    int valoresExpoente[] = {10, 7, 0, 12};

    for (int indice = 0; indice < 4; indice++)
    {
        int chamadasOtimizada = 0;
        int chamadasSimples = 0;

        long long respostaOtimizada =
            exponenciacaoOtimizada(
                valoresBase[indice],
                valoresExpoente[indice],
                &chamadasOtimizada);

        long long respostaSimples =
            exponenciacaoSimples(
                valoresBase[indice],
                valoresExpoente[indice],
                &chamadasSimples);

        printf("%lld elevado a %d = %lld\n",
               valoresBase[indice],
               valoresExpoente[indice],
               respostaOtimizada);

        printf("Chamadas (versao otimizada): %d\n",
               chamadasOtimizada);

        printf("Chamadas (versao simples): %d\n\n",
               chamadasSimples);

        (void)respostaSimples;
    }


    return 0;
}
