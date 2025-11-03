#include <stdio.h>

int main() {
    int arr[100], n, ch, pos, val, s, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) scanf("%d", &arr[i]);

    while (1) {
        printf("\n0.Insert  1.Delete  2.Search  3.Exit\nChoose: ");
        scanf("%d", &ch);

        if (ch == 0) { 
            printf("Enter index (0-%d): ", n);
            scanf("%d", &pos);
            printf("Value to insert: ");
            scanf("%d", &val);
            if (pos < 0 || pos > n) {
                printf("Invalid index!\n");
                continue;
            }
            for (i = n; i > pos; i--) arr[i] = arr[i - 1];
            arr[pos] = val;
            n++;
            printf("Inserted. Array: ");
            for (i = 0; i < n; i++) printf("%d ", arr[i]);
            printf("\n");
        }

        else if (ch == 1) { 
            printf("Enter index (0-%d): ", n - 1);
            scanf("%d", &pos);
            if (pos < 0 || pos >= n) {
                printf("Invalid index!\n");
                continue;
            }
            for (i = pos; i < n - 1; i++) arr[i] = arr[i + 1];
            n--;
            printf("Deleted. Array: ");
            for (i = 0; i < n; i++) printf("%d ", arr[i]);
            printf("\n");
        }

        else if (ch == 2) { 
            printf("Enter value to search: ");
            scanf("%d", &s);
            for (i = 0; i < n; i++) if (arr[i] == s) break;
            if (i < n) printf("Found at index %d.\n", i);
            else printf("Not found.\n");
        }

        else if (ch == 3) break; 
        else printf("Invalid choice!\n");
    }

    return 0;
}

