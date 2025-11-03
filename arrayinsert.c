#include <stdio.h>
int main()
{
    int a[100], n, i, data, pos;
    printf("Enter the number of elements:\n");
    scanf("%d", &n);
    printf("Enter the array elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("Enter the data to insert:\n");
    scanf("%d", &data);
    printf("Enter the position for insertion (1 to %d):\n", n + 1);
    scanf("%d", &pos);
    if (pos < 1 || pos > n + 1) {
        printf("Invalid position! Must be between 1 and %d\n", n + 1);
        return 1;
    }
    for (i = n - 1; i >= pos - 1; i--) {
        a[i + 1] = a[i];
    }
    a[pos - 1] = data;
    n++;  
    printf("Array after insertion:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}

