#include <stdio.h>

int main() {
    int n1, n2;

    printf("Enter number of elements in first array: ");
    scanf("%d", &n1);
    int arr1[n1];
    printf("Enter %d elements: ", n1);
    for (int i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter number of elements in second array: ");
    scanf("%d", &n2);
    int arr2[n2];
    printf("Enter %d elements: ", n2);
    for (int i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
    }

    int merged[n1 + n2];
    for (int i = 0; i < n1; i++) merged[i] = arr1[i];
    for (int i = 0; i < n2; i++) merged[n1 + i] = arr2[i];


    for (int i = 0; i < n1 + n2 - 1; i++) {
        for (int j = 0; j < n1 + n2 - i - 1; j++) {
            if (merged[j] > merged[j + 1]) {
                int temp = merged[j];
                merged[j] = merged[j + 1];
                merged[j + 1] = temp;
            }
        }
    }

  
    printf("Merged and sorted array: ");
    for (int i = 0; i < n1 + n2; i++) {
        printf("%d ", merged[i]);
    }
    printf("\n");

    return 0;
}

