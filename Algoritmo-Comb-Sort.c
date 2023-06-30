/*************************************************************************************************
Algoritmo Comb Sort para ordenacao de vetores
**************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int tamanho_vetor;
    printf("Quantidade de elementos: "); // Solicita ao usuario a quantidade de elementos
    scanf("%d", &tamanho_vetor);

    if (tamanho_vetor <= 0) {
        printf("\nTamanho do vetor invalido!"); // Verifica se o tamanho do vetor eh invalido
        return 1;
    }

    int *numero = malloc(tamanho_vetor * sizeof(int));
    if (numero == NULL) {
        printf("\nErro de alocacao de memoria!"); // Verifica se houve erro na alocacao de memoria
        return 1;
    }

    printf("\nInforme os elementos:\n");
    for (int i = 0; i < tamanho_vetor; i++) {
        printf("Indice [%d] = ", i); // Solicita ao usuario o valor para o indice i
        scanf("%d", &numero[i]);
    }

    printf("\nLista nao ordenada:\n");
    for (int j = 0; j < tamanho_vetor; j++) {
        printf("%d ", numero[j]); // Exibe a lista nao ordenada
    }
    printf("\n");

    int troca = 0, quantidade_troca = 0, comparacao = 0;
    int intervalo = tamanho_vetor;

    while (intervalo > 1 || troca != 0) {
        intervalo = (int)(intervalo / 1.3); // Calcula o novo intervalo
        if (intervalo < 1) {
            intervalo = 1; // Garante que o intervalo seja pelo menos 1
        }

        troca = 0;

        for (int i = 0; (i + intervalo) < tamanho_vetor; i++) {
            comparacao += 1; // Incrementa o contador de comparacoes

            if (numero[i] > numero[i + intervalo]) { // Verifica se eh necessario realizar a troca
                int aux = numero[i];
                numero[i] = numero[i + intervalo];
                numero[i + intervalo] = aux;

                troca = 1; // Indica que houve uma troca
                quantidade_troca += troca; // Incrementa o contador de trocas
            }
        }
    }

    printf("\nLista ordenada:\n");
    for (int j = 0; j < tamanho_vetor; j++) {
        printf("%d ", numero[j]); // Exibe a lista ordenada
    }
    printf("\n\n");

    printf("Quantidade de trocas: %d\n", quantidade_troca);
    printf("Quantidade de comparacoes: %d\n", comparacao);

    free(numero);

    return 0;
}