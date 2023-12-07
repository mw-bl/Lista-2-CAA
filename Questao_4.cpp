#include <stdio.h>
#include <locale.h>

int eMajoritario(int nums[], int size) {
    int c = -1;
    int count = 0;

    for (int i = 0; i < size; i++) {
        if (count == 0) {
            c = nums[i];
            count = 1;
        } else if (nums[i] == c) {
            count++;
        } else {
            count--;
        }
    }

    return c;
}

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");
	
    int nums1[] = {1, 1, 2, 2, 2, 1, 1};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    int saida1 = eMajoritario(nums1, size1);
    printf("Saída 1: %d\n", saida1);

    int nums2[] = {3, 3, 3, 4, 4, 2, 2};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    int saida2 = eMajoritario(nums2, size2);
    printf("Saída 2: %d\n", saida2);

    return 0;
}
