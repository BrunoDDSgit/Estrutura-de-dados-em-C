#include <stdio.h>
#include <stdlib.h>

void preencherVetor(int *v, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        printf("Digite o primeiro valor: ");
        scanf("%d", &v[i]);
    }
    printf("\nVetor Preenchido com sucesso!");
}

void imprimirVetor(int *v, int tam)
{
    printf("\nVetor: ");
    for (int i = 0; i < tam; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void bubbleSort(int *v, int tam)
{
    int aux, continuar = 0;
    do
    {
        for (int i = 0; i < tam - 1; i++)
        {
            if (v[i] > v[i + 1])
            {
                aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
            }
            continuar = i;
        }
        tam--;
    } while (continuar != 0);

    printf("\n\nVetor Ordenado por bubbleSort com sucesso!");
}

void insertSort(int *v, int tam)
{
    for (int i = 1; i < tam; i++)
    {
        int aux = v[i], j = i - 1;
        while (j >= 0 && v[j] > aux)
        {
            v[j + 1] = v[j];
            j--;
        }
        v[j+1] = aux;
    }

    printf("\n\nVetor Ordenado por insertSort com sucesso!");
}

int main()
{
    int tamanho;

    printf("Indique o tamanho do vetor: ");
    scanf("%d", &tamanho);

    int *vet = malloc(tamanho * sizeof(int));
    if (vet)
    {
        printf("Vetor Alocado com sucesso!\n");
    }
    else
        printf("Falha na alocação de memória | ponteiro: NULL");

    preencherVetor(vet, tamanho);
    imprimirVetor(vet, tamanho);

    bubbleSort(vet, tamanho);
    imprimirVetor(vet, tamanho);

    insertSort(vet, tamanho);
    imprimirVetor(vet, tamanho);

    free(vet);

    return 0;
}