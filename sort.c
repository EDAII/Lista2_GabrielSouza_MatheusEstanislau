#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIM 10

void selectionSort(int vetor[], int tamVetor);
void insertionSort(int vetor[]);
void bubbleSort(int vetor[]);
void shellSort(int vetor[]);
void quick_sort(int *a, int inicio, int fim);
void popularVetor(int vetor[]);
void imprimirVetor(int vetor[]);
void vetorOrdenado(int vetor[]);
void comparacao(int vetor[]);

int main()
{
    int vetor[DIM];
    int tamVetor = sizeof(vetor) / sizeof(int);
    size_t inicio, fim;
    double tempo;

    popularVetor(vetor);

    // imprimirVetor(vetor);
    // shellSort(vetor);
    // imprimirVetor(vetor);
    //imprimirVetor(vetor);
    // inicio = time(NULL);
    // bubbleSort(vetor);
    // fim = time(NULL);

    // //imprimirVetor(vetor);
    // tempo = difftime(fim,inicio);
    // printf("Tempo de Execução: %.2lfs\n", tempo);

    comparacao(vetor);

    return 0;
}

void selectionSort(int vetor[], int tamVetor)
{

    int aux, menorIndice;
    for (int i = 0; i < tamVetor; i++)
    {
        menorIndice = i;
        for (int j = i + 1; j < tamVetor; j++)
        {
            if (vetor[j] < vetor[menorIndice])
            {
                menorIndice = j;
            }
        }
        if (menorIndice != i)
        {
            aux = vetor[i];
            vetor[i] = vetor[menorIndice];
            vetor[menorIndice] = aux;
        }
    }
}

void insertionSort(int vetor[])
{
    int aux, i, j;
    for (i = 1; i < DIM; i++)
    {
        j = i;
        while ((j != 0) && (vetor[j] < vetor[j - 1]))
        {
            aux = vetor[j];
            vetor[j] = vetor[j - 1];
            vetor[j - 1] = aux;
            j--;
        }
    }
}

void bubbleSort(int vetor[])
{
    int troca;
    int aux;
    do
    {
        troca = 0;
        for (int i = 0; i < DIM - 1; i++)
        {
            if (vetor[i] > vetor[i + 1])
            {
                troca = 1;
                aux = vetor[i];
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = aux;
            }
        }
    } while (troca == 1);
}

void shellSort(int vetor[])
{
    int gap = DIM / 2;
    int valor, j;

    while (gap > 0)
    {
        for (int i = gap; i < DIM; i++)
        {
            valor = vetor[i];
            j = i;
            while (j >= gap && vetor[j - gap] > valor)
            {
                vetor[j] = vetor[j - gap];
                j = j - gap;
            }
            vetor[j] = valor;
        }
        gap = gap / 2;
    }
}

void quick_sort(int *a, int inicio, int fim)
{
    int esquerda, direita, pivo, aux;

    esquerda = inicio;
    direita = fim;
    pivo = a[(inicio + fim) / 2];

    while (esquerda <= direita)
    {
        while (a[esquerda] < pivo && esquerda < fim)
        {
            esquerda++;
        }
        while (a[direita] > pivo && direita > inicio)
        {
            direita--;
        }
        if (esquerda <= direita)
        {
            aux = a[esquerda];
            a[esquerda] = a[direita];
            a[direita] = aux;
            esquerda++;
            direita--;
        }
    }

    if (direita > inicio)
    {
        quick_sort(a, inicio, direita);
    }
    if (esquerda < fim)
    {
        quick_sort(a, esquerda, fim);
    }
}

void popularVetor(int vetor[])
{
    srand((unsigned)time(NULL));
    for (int i = 0; i < DIM; i++)
    {
        vetor[i] = rand() % DIM;
    }
}

void imprimirVetor(int vetor[])
{
    printf("[");
    for (int i = 0; i < DIM; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("]\n");
}

void vetorOrdenado(int vetor[])
{
    for (int i = 0; i < DIM; i++)
    {
        vetor[i] = i + 1;
    }
}

void comparacao(int vetor[])
{
    int teste, countSelection = 0, countInsertion = 0, countBubble = 0, countShell = 0, countQuick = 0;
    double timeSelection, timeInsertion, timeBubble, timeShell, timeQuick;
    clock_t inicio, fim;
    printf("Digite quantos casos de teste deseja fazer: ");
    scanf("%d", &teste);

    for (int i = 0; i < teste; i++)
    {
        //Selection
        popularVetor(vetor);
        inicio = clock();
        selectionSort(vetor, DIM);
        fim = clock();
        timeSelection = (float)(fim - inicio) / CLOCKS_PER_SEC;

        //Insertion
        popularVetor(vetor);
        inicio = clock();
        insertionSort(vetor);
        fim = clock();
        timeInsertion = (float)(fim - inicio) / CLOCKS_PER_SEC;

        //Bubble
        popularVetor(vetor);
        inicio = clock();
        bubbleSort(vetor);
        fim = clock();
        timeBubble = (float)(fim - inicio) / CLOCKS_PER_SEC;

        //Shell
        popularVetor(vetor);
        inicio = clock();
        shellSort(vetor);
        fim = clock();
        timeShell = (float)(fim - inicio) / CLOCKS_PER_SEC;

        //Quick
        popularVetor(vetor);
        inicio = clock();
        quick_sort(vetor, 0, DIM - 1);
        fim = clock();
        timeQuick = (float)(fim - inicio) / CLOCKS_PER_SEC;

        //Tempo Selection
        if (timeSelection < timeInsertion && timeSelection < timeBubble && timeSelection < timeShell && timeSelection < timeQuick)
        {
            countSelection += 1;
        }

        //Tempo Insertion
        if (timeInsertion < timeSelection && timeInsertion < timeBubble && timeInsertion < timeShell && timeInsertion < timeQuick)
        {
            countInsertion += 1;
        }

        //Tempo Bubble
        if (timeBubble < timeInsertion && timeBubble < timeSelection && timeBubble < timeShell && timeBubble < timeQuick)
        {
            countBubble += 1;
        }

        //Tempo Shell
        if (timeShell < timeInsertion && timeShell < timeSelection && timeShell < timeBubble && timeShell < timeQuick)
        {
            countShell += 1;
        }

        //Tempo Quick
        if (timeQuick < timeBubble && timeQuick < timeInsertion && timeQuick < timeSelection && timeQuick < timeShell)
        {
            countQuick += 1;
        }

        printf("Selection(%fms): %d\t Insertion(%fms): %d\t Bubble(%fms): %d\t Shell(%fms): %d\t Quick(%fms): %d\n", timeSelection, countSelection, timeInsertion, countInsertion, timeBubble, countBubble, timeShell, countShell, timeQuick, countQuick);
    }

    printf("Pontuação Final\n");
    printf("Selection: %d\t Insertion: %d\t Bubble: %d\t Shell: %d\t Quick: %d\n", countSelection, countInsertion, countBubble, countShell, countQuick);
}