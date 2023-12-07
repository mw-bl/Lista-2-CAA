#include <stdio.h>
#include <locale.h>

void merge(int nums1[], int m, int nums2[], int n) {
    int p1 = m - 1;
    int p2 = n - 1;
    int p_merge = m + n - 1;

    while (p1 >= 0 && p2 >= 0) {
        if (nums1[p1] > nums2[p2]) {
            nums1[p_merge] = nums1[p1];
            p1--;
        } else {
            nums1[p_merge] = nums2[p2];
            p2--;
        }
        p_merge--;
    }

    while (p2 >= 0) {
        nums1[p_merge] = nums2[p2];
        p2--;
        p_merge--;
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");
  
    int nums1[] = {1, 2, 3, 0, 0, 0};
    int m = 3;
    int nums2[] = {2, 5, 6};
    int n = 3;

    merge(nums1, m, nums2, n);

    printf("Saída esperada:[ ");
    for (int i = 0; i < m + n; i++) {
        printf("%d ", nums1[i]);
    }
    printf("]");
    
    return 0;
}
