#include <stdio.h>
#include <locale.h>

void decomporVetor(int S[], int p, int r, int piv, int *q1, int *q2) {
    int i = p - 1, j = p - 1, temp;

    for (int k = p; k <= r; k++) {
        if (S[k] < piv) {
            i++;
            j++;
            
            temp = S[i];
            S[i] = S[k];
            S[k] = temp;
        } else if (S[k] == piv) {
            j++;
            
            temp = S[j];
            S[j] = S[k];
            S[k] = temp;
        }
    }

    *q1 = i;
    *q2 = j;
}

int main() {
	setlocale(LC_ALL, "Portuguese_Brazil");
	
    int S[] = {5, 2, 8, 7, 1, 3, 5, 6};
    int p = 2, r = 6, piv = 5;

    int q1, q2;
    decomporVetor(S, p, r, piv, &q1, &q2);

    printf("Vetor rearranjado: ");
    for (int i = p; i <= r; i++) {
        printf("%d ", S[i]);
    }

    printf("\nÍndices q1 e q2: %d %d\n", q1, q2);

    return 0;
}
