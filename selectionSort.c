#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIM 80000

void selectionSort (int vetor[], int tamVetor);
void popularVetor (int vetor[]);
void imprimirVetor (int vetor[]);

int main()
{
    int vetor[DIM];
    int tamVetor = sizeof(vetor)/sizeof(int);
    size_t inicio, fim;
    double tempo;

    printf("Vetor Desordenado:\n");
    popularVetor(vetor);
    imprimirVetor(vetor);
    printf("Vetor Ordenado:\n");
    inicio = time(NULL);
    selectionSort(vetor, tamVetor);
    fim = time(NULL);
    imprimirVetor(vetor); 

    tempo = difftime(fim, inicio);

    printf("Tempo de Execução: %.2lfs\n", tempo); 

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