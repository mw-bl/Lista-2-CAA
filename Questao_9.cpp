#include <stdio.h>
#include <locale.h>

// Pesquisa1
void Pesquisa1(int A[], int n) {
    if (n > 1) {
        int i = n * n * n;
        Pesquisa1(A, n / 3);
    }
}

/* Função de Complexidade na pesquisa1: O(nlogn);
Chamada recursiva feita em n/3 por iteração, com condição de parada igual a n>1. */

// Pesquisa2
void Pesquisa2(int A[], int n) {
    if (n <= 1) {
        return;
    } else {
        Pesquisa2(A, 3 * n / 5);
    }
}

/* Função de Complexidade na pesquisa2: O(logn); 
Chamada recursiva feita em 3n/5 por iteração, com condição de parada igual a n<=1. */

// Pesquisa3
void Pesquisa3(int A[], int n) {
    if (n <= 1) {
        return;
    } else {
        Pesquisa3(A, 2 * n / 3);
    }
}

/* Função de Complexidade na pesquisa3: O(logn);
Chamada recursiva feita em 2n/3 por iteração, com condição de parada igual a n<=1. */

// Enigmas
typedef struct {
    int Chave;
} Item;

void Enigma2(Item A[], int m, int n, int i, int j) {
    Item x = A[(i + j) / 2];
    while (1) {
        while (x.Chave > A[i].Chave) {
            i++;
        }
        while (x.Chave < A[j].Chave) {
            j--;
        }
        if (i <= j) {
            Item temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i++;
            j--;
        }
        if (i > j) {
            break;
        }
    }
}

void Enigma1(Item A[], int m, int n) {
    int i = 0, j = 0;
    Enigma2(A, m, n, i, j);
    if (m < j) {
        Enigma1(A, m, j);
    }
    if (i < n) {
        Enigma1(A, i, n);
    }
}

/* Função de Complexidade nos enigmas: O(nlogn);
Algoritmo usado nos enigmas: QuickSort. */

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");
    
     // Teste para Pesquisa1
    int array1[] = {1, 2, 3, 4, 5};
    int size1 = sizeof(array1) / sizeof(array1[0]);
    Pesquisa1(array1, size1);
    printf("Pesquisa1\n");

    // Teste para Pesquisa2
    int array2[] = {1, 2, 3, 4, 5};
    int size2 = sizeof(array2) / sizeof(array2[0]);
    Pesquisa2(array2, size2);
    printf("Pesquisa2\n");

    // Teste para Pesquisa3
    int array3[] = {1, 2, 3, 4, 5};
    int size3 = sizeof(array3) / sizeof(array3[0]);
    Pesquisa3(array3, size3);
    printf("Pesquisa3\n");

    return 0;
}
