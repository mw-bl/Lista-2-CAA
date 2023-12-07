#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int* ordemQuadrados(int nums[], int n) {
    int* resultado = (int*)malloc(n * sizeof(int));

    int esq = 0;
    int dir = n - 1;
    int indice = n - 1;

    while (esq <= dir) {
        int quadradoEsq = nums[esq] * nums[esq];
        int quadradoDir = nums[dir] * nums[dir];

        if (quadradoEsq > quadradoDir) {
            resultado[indice] = quadradoEsq;
            esq++;
        } else {
            resultado[indice] = quadradoDir;
            dir--;
        }

        indice--;
    }

    return resultado;
}

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");
    
    int nums[] = {-4, -1, 0, 3, 10};
    int tamanho = sizeof(nums) / sizeof(nums[0]);

    int* saida = ordemQuadrados(nums, tamanho);

    printf("Saída: [");
    for (int i = 0; i < tamanho; i++) {
        printf("%d", saida[i]);
        if (i < tamanho - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    free(saida);

    return 0;
}
