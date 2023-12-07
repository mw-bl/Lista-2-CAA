#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Solução Simples
int* soluSimples(int* nums, int n, int X) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] + nums[j] == X) {
                int* result = (int*)malloc(2 * sizeof(int));
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }
    return NULL;
}

// Solução Melhorada
int* soluMelhorada(int* nums, int n, int X) {
    int* result = (int*)malloc(2 * sizeof(int));
    int* num = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        int comp = X - nums[i];
        if (num[comp] != -1) {
            result[0] = num[comp];
            result[1] = i;
            free(num);
            return result;
        }
        num[nums[i]] = i;
    }

    free(num);
    free(result);
    return NULL;
}

int main() {
	setlocale(LC_ALL, "Portuguese_Brazil");
    int nums[] = {2, 7, 11, 15};
    int X = 9;
    int n = sizeof(nums) / sizeof(nums[0]);

    // Teste da Solução Simples
    int* result_simples = soluSimples(nums, n, X);
    if (result_simples != NULL) {
        printf("Solução Simples: [%d, %d]\n", result_simples[0], result_simples[1]);
        free(result_simples);
    } else {
        printf("Solução Simples: Sem solução\n");
    }

    // Teste da Solução Melhorada
    int* result_melhorada = soluMelhorada(nums, n, X);
    if (result_melhorada != NULL) {
        printf("Solução Melhorada: [%d, %d]\n", result_melhorada[0], result_melhorada[1]);
        free(result_melhorada);
    } else {
        printf("Solução Melhorada: Sem solução\n");
    }

    return 0;
}
