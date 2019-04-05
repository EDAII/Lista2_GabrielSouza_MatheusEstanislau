#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIM 1000

void selectionSort (int vetor[], int tamVetor);
void insertionSort(int vetor[]);
void bubbleSort(int vetor[]);
void shellSort(int vetor[]);
void popularVetor (int vetor[]);
void imprimirVetor (int vetor[]);
void vetorOrdenado(int vetor[]);
void comparacao(int vetor[]);

int main()
{
    int vetor[DIM];
    int tamVetor = sizeof(vetor)/sizeof(int);
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

void selectionSort (int vetor[], int tamVetor){
    
    int aux, menorIndice;
    for(int i=0;i<tamVetor;i++){
        menorIndice = i;
        for(int j=i+1;j<tamVetor;j++){
            if(vetor[j] < vetor[menorIndice]){
                menorIndice = j;
            }
        }
        if(menorIndice != i){
            aux = vetor[i];
            vetor[i] = vetor[menorIndice];
            vetor[menorIndice] = aux;
        }
    }
}

void insertionSort(int vetor[]){
	int aux,i,j;
	for(i=1;i<DIM;i++){
		j = i;
		while((j!=0) && (vetor[j] < vetor[j-1])){
			aux = vetor[j];
			vetor[j] = vetor[j-1];
			vetor[j-1] = aux;
			j--;
		}
		
	}
}

void bubbleSort(int vetor[]){
    int troca;
    int aux;
    do
    {
        troca = 0;
        for(int i=0;i<DIM-1;i++){
            if(vetor[i] > vetor[i+1]){
                troca = 1;
                aux = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = aux;

            }
        }
    } while (troca == 1);
    
}

void shellSort(int vetor[]){
    int gap = DIM/2;
    int valor, j;

    while(gap>0){
        for(int i=gap;i<DIM;i++){
            valor = vetor[i];
            j = i;
            while(j>=gap && vetor[j-gap] > valor){
                vetor[j] = vetor[j-gap];
                j = j-gap;
            }
            vetor[j] = valor;
        }
        gap = gap/2;
    }
}

void popularVetor(int vetor[]){
    srand( (unsigned)time(NULL) );
    for(int i=0;i<DIM;i++){
        vetor[i] = rand()%DIM;
    }
}

void imprimirVetor(int vetor[]){
    printf("[");
    for(int i=0;i<DIM;i++){
        printf("%d ", vetor[i]);
    }
    printf("]\n");
}

void vetorOrdenado(int vetor[]){
    for(int i=0;i<DIM;i++){
        vetor[i] = i+1;
    }
}

void comparacao(int vetor[]){
    int teste, countSelection = 0,countInsertion = 0, countBubble = 0, countShell = 0;
    double timeSelection, timeInsertion, timeBubble, timeShell;
    clock_t inicio, fim;
    printf("Digite quantos casos de teste deseja fazer: ");
    scanf("%d", &teste);

    for(int i=0;i<teste;i++){
        popularVetor(vetor);
        inicio = clock();
        selectionSort(vetor, DIM);
        fim = clock();
        timeSelection = (float)(fim-inicio)/CLOCKS_PER_SEC;

        popularVetor(vetor);
        inicio = clock();
        insertionSort(vetor);
        fim = clock();
        timeInsertion = (float)(fim-inicio)/CLOCKS_PER_SEC;

        popularVetor(vetor);
        inicio = clock();
        bubbleSort(vetor);
        fim = clock();
        timeBubble = (float)(fim-inicio)/CLOCKS_PER_SEC;

        popularVetor(vetor);
        inicio = clock();
        shellSort(vetor);
        fim = clock();
        timeShell = (float)(fim-inicio)/CLOCKS_PER_SEC;

        if(timeSelection < timeInsertion && timeSelection < timeBubble && timeSelection < timeShell){
            countSelection += 1;
        }

        if(timeInsertion < timeSelection && timeInsertion < timeBubble && timeInsertion < timeShell){
            countInsertion += 1;
        }

        if(timeBubble < timeInsertion && timeBubble < timeSelection && timeBubble < timeShell){
            countBubble += 1;
        }

        if(timeShell < timeInsertion && timeShell < timeSelection && timeShell < timeBubble){
            countShell += 1;
        }
        printf("Selection(%f): %d\t Insertion(%f): %d\t Bubble(%f): %d, Shell(%f): %d\n",timeSelection, countSelection,timeInsertion,countInsertion,timeBubble, countBubble, timeShell, countShell);
    }

    printf("Pontuação Final\n");
    printf("Selection: %d\t Insertion: %d\t Bubble: %d, Shell: %d\n",countSelection,countInsertion,countBubble,countShell);
}