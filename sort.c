#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define DIM 100
#define DEZ 10
#define MIL 1000
#define DEZ_MIL 10000

typedef struct
{
    int prioridade;
    char nome[30];
} Task;

Task tarefa[5];

void selectionSort(int vetor[], int tamVetor);
void insertionSort(int vetor[]);
void insertionSortTarefa(Task *tarefa, int n);
void bubbleSort(int vetor[]);
void shellSort(int vetor[]);
void quick_sort(int *a, int inicio, int fim);
void popularVetor(int vetor[], int tamanho);
void imprimirVetor(int vetor[]);
void vetorOrdenado(int vetor[]);
void comparacao(int vetor[], int tamanho);
int menuPrincipal();
int menuOrdenacaoIndividual();
int menuComparativoAlgoritimos();
int menuTuturial();
void pause(float delay1);

int main()
{

    int vetorDez[DEZ],
        vetorCem[DIM],
        vetorMil[MIL],
        vetorDezMil[DEZ_MIL];
    size_t inicio, fim;
    double tempo;
    char lixo;
    int menuPri, menuOrdenacao, menuComparativo, menuTuto;

    //Menu Principal
    do
    {
        menuPri = menuPrincipal();
        switch (menuPri)
        {
        //Ordenação Individual
        case 1:
            do
            {
                menuOrdenacao = menuOrdenacaoIndividual();
                switch (menuOrdenacao)
                {
                //Insertion Sort
                case 1:
                    system("clear");
                    popularVetor(vetorCem, DIM);
                    printf("Vetor desordenado:\n");
                    imprimirVetor(vetorCem);
                    insertionSort(vetorCem);
                    printf("Vetor Ordenado: \n");
                    imprimirVetor(vetorCem);
                    break;

                //Selection Sort
                case 2:
                    system("clear");
                    popularVetor(vetorCem, DIM);
                    printf("Vetor desordenado:\n");
                    imprimirVetor(vetorCem);
                    selectionSort(vetorCem, DIM);
                    printf("Vetor Ordenado: \n");
                    imprimirVetor(vetorCem);
                    break;

                //Bubble Sort
                case 3:
                    system("clear");
                    popularVetor(vetorCem, DIM);
                    printf("Vetor desordenado:\n");
                    imprimirVetor(vetorCem);
                    bubbleSort(vetorCem);
                    printf("Vetor Ordenado: \n");
                    imprimirVetor(vetorCem);
                    break;

                //Shell Sort
                case 4:
                    system("clear");
                    popularVetor(vetorCem, DIM);
                    printf("Vetor desordenado:\n");
                    imprimirVetor(vetorCem);
                    shellSort(vetorCem);
                    printf("Vetor Ordenado: \n");
                    imprimirVetor(vetorCem);
                    break;

                //Quick Sort
                case 5:
                    system("clear");
                    popularVetor(vetorCem, DIM);
                    printf("Vetor desordenado:\n");
                    imprimirVetor(vetorCem);
                    quick_sort(vetorCem, 0, DIM - 1);
                    printf("Vetor Ordenado: \n");
                    imprimirVetor(vetorCem);
                    break;
                case 0:
                    break;

                default:
                    printf("\aVocê quis dizer: \n");
                    break;
                }
            } while (menuOrdenacao);
            break;
        //Comparativo dos Algorítimos
        case 2:
            do
            {
                menuComparativo = menuComparativoAlgoritimos();
                switch (menuComparativo)
                {
                case 1:
                    comparacao(vetorDez, DEZ);
                    break;
                case 2:
                    comparacao(vetorMil, MIL);
                    break;
                case 3:
                    comparacao(vetorDezMil, DEZ_MIL);
                    break;
                case 0:
                    break;

                default:
                    printf("\aVocê quis dizer: \n");
                    break;
                }

            } while (menuComparativo);

            break;

        //Quer Saber Mais? "Matheus"
        case 3:
            for (int i = 0; i < 5; i++)
            {
                printf("Tarefa: ");
                setbuf(stdin, NULL);
                fgets(tarefa[i].nome, 30, stdin);
                printf("Prioridade (1 - 5): ");
                scanf("%d", &tarefa[i].prioridade);
            }

            insertionSortTarefa(tarefa, 5);

            for (int i = 0; i < 5; i++)
            {
                puts(tarefa[i].nome);
                printf("Prioridade: %d\n", tarefa[i].prioridade);
            }
            printf("Tecle ENTER para continuar");
            setbuf(stdin, NULL);
            scanf("%c", &lixo);

            break;

        default:
            break;
        }
    } while (menuPri);

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

void insertionSortTarefa(Task *tarefa, int n)
{
    int i, j;
    Task aux;
    for (i = 0; i < n; i++)
    {
        aux = tarefa[i];
        for (j = i; (j > 0) && (aux.prioridade < tarefa[j - 1].prioridade); j--)
        {
            tarefa[j] = tarefa[j - 1];
        }
        tarefa[j] = aux;
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

void popularVetor(int vetor[], int tamanho)
{
    srand((unsigned)time(NULL));
    for (int i = 0; i < tamanho; i++)
    {
        vetor[i] = rand() % tamanho;
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

void comparacao(int vetor[], int tamanho)
{
    int teste, countSelection = 0, countInsertion = 0, countBubble = 0, countShell = 0, countQuick = 0;
    double timeSelection, timeInsertion, timeBubble, timeShell, timeQuick;
    clock_t inicio, fim;
    printf("Digite quantos casos de teste deseja fazer: ");
    scanf("%d", &teste);

    for (int i = 0; i < teste; i++)
    {
        //Selection
        popularVetor(vetor, tamanho);
        inicio = clock();
        selectionSort(vetor, DIM);
        fim = clock();
        timeSelection = (float)(fim - inicio) / CLOCKS_PER_SEC;

        //Insertion
        popularVetor(vetor, tamanho);
        inicio = clock();
        insertionSort(vetor);
        fim = clock();
        timeInsertion = (float)(fim - inicio) / CLOCKS_PER_SEC;

        //Bubble
        popularVetor(vetor, tamanho);
        inicio = clock();
        bubbleSort(vetor);
        fim = clock();
        timeBubble = (float)(fim - inicio) / CLOCKS_PER_SEC;

        //Shell
        popularVetor(vetor, tamanho);
        inicio = clock();
        shellSort(vetor);
        fim = clock();
        timeShell = (float)(fim - inicio) / CLOCKS_PER_SEC;

        //Quick
        popularVetor(vetor, tamanho);
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

int menuPrincipal()
{
    int opcao;

    system("clear");
    printf("******************** Menu ******************\n");
    printf("*1 - Ordenacao Individual                  *\n");
    printf("*2 - Comparativo dos Algoritimos           *\n");
    printf("*3 - Quer saber mais?                      *\n");
    printf("*0 - Sair                                  *\n");
    printf("********************************************\n");

    printf("Digite sua opcao: ");
    scanf("%d", &opcao);

    return opcao;
}

// Working
int menuOrdenacaoIndividual()
{
    int opcao;

    printf("*********** Ordenacao Individual ***********\n");
    printf("*1 - Insertion Sort                        *\n");
    printf("*2 - Selection Sort                        *\n");
    printf("*3 - Bubble Sort                           *\n");
    printf("*4 - Shell Sort                            *\n");
    printf("*5 - Quick Sort                            *\n");
    printf("*0 - Voltar                                *\n");
    printf("********************************************\n");

    printf("Digite sua opcao individual: ");
    scanf("%d", &opcao);

    return opcao;
}

int menuComparativoAlgoritimos()
{
    int opcao;

    printf("******** Comparativo dos Algoritimos *******\n");
    printf("*1 - Vetor com 10 elementos                *\n");
    printf("*2 - Vetor com 1.000 elementos             *\n");
    printf("*3 - Vetor com 10.000 elementos            *\n");
    printf("*0 - Voltar                                *\n");
    printf("********************************************\n");

    printf("Digite sua opcao: ");
    scanf("%d", &opcao);

    return opcao;
}

int menuTuturial()
{
    int opcao;

    printf("***************** Tutorial *****************\n");
    printf("*1 - Insertion Sort                        *\n");
    printf("*2 - Selection Sort                        *\n");
    printf("*3 - Bubble Sort                           *\n");
    printf("*4 - Shell Sort                            *\n");
    printf("*5 - Quick Sort                            *\n");
    printf("*0 - Voltar                                *\n");
    printf("********************************************\n");

    scanf("%d", &opcao);

    return opcao;
}

void pause(float delay1)
{

    if (delay1 < 0.001)
        return; // pode ser ajustado e/ou evita-se valores negativos.

    float inst1 = 0, inst2 = 0;

    inst1 = (float)clock() / (float)CLOCKS_PER_SEC;

    while (inst2 - inst1 < delay1)
    {
        inst2 = (float)clock() / (float)CLOCKS_PER_SEC;
    }

    return;
}