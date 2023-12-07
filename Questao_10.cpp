#include <stdio.h>

int iSearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return left;
}

int main() {
    int nums1[] = {1, 3, 5, 6};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    int target1 = 5;
    int result1 = iSearch(nums1, size1, target1);
    printf("%d\n", result1);

    int nums2[] = {1, 3, 5, 6};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    int target2 = 2;
    int result2 = iSearch(nums2, size2, target2);
    printf("%d\n", result2);

    return 0;
}
