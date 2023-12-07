#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct Palindromo {
    char *resultado;
    int tamanho;
};

struct Palindromo palindromoM(char *S) {
    int n = strlen(S);
    int **dp = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        dp[i] = (int *)malloc(n * sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }

    for (int cl = 2; cl <= n; cl++) {
        for (int i = 0; i < n - cl + 1; i++) {
            int j = i + cl - 1;
            if (S[i] == S[j] && cl == 2) {
                dp[i][j] = 2;
            } else if (S[i] == S[j]) {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            } else {
                dp[i][j] = (dp[i][j - 1] > dp[i + 1][j]) ? dp[i][j - 1] : dp[i + 1][j];
            }
        }
    }

    char *result = (char *)malloc((n + 1) * sizeof(char));
    int i = 0, j = n - 1, resultIndex = 0;

    while (i < j) {
        if (S[i] == S[j]) {
            result[resultIndex++] = S[i];
            i++;
            j--;
        } else if (dp[i][j - 1] > dp[i + 1][j]) {
            j--;
        } else {
            i++;
        }
    }

    if (i == j) {
        result[resultIndex++] = S[i];
    }

    result[resultIndex] = '\0';

    struct Palindromo resultado;
    resultado.resultado = result;
    resultado.tamanho = resultIndex;

    return resultado;
}

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");
	
    char sequencia[] = "ACGTGTCAAAATCG";
    struct Palindromo resultado = palindromoM(sequencia);

    printf("Subsequência palíndroma: %s\n", resultado.resultado);
    printf("Tamanho da sequência: %d\n", resultado.tamanho);

    free(resultado.resultado);

    return 0;
}
