//With inbuilt functions
#include <stdio.h>
#include <stdlib.h>
// Comparator function for qsort
int compare(const void *a, const void *b) {
 return (*(int*)a - *(int*)b);
}
void sort_prices_builtin(int prices[], int n) {
 qsort(prices, n, sizeof(int), compare);
}
int main() {
 int n;
 printf("Enter the number of products: ");
 scanf("%d", &n);
 int prices[n];
 printf("Enter the product prices:\n");
 for (int i = 0; i < n; i++) {
 scanf("%d", &prices[i]);
 }
 sort_prices_builtin(prices, n);
 printf("Sorted Prices (Built-in Function):\n");
 for (int i = 0; i < n; i++) {
 printf("%d ", prices[i]);
 }
 printf("\n");
 return 0;
}


//Without inbuilt functions using bubble sort
#include <stdio.h>
void bubble_sort(int arr[], int n) {
 int temp;
 for (int i = 0; i < n - 1; i++) {
 for (int j = 0; j < n - i - 1; j++) {
 if (arr[j] > arr[j + 1]) { // Swap if out of order
 temp = arr[j];
 arr[j] = arr[j + 1];
 arr[j + 1] = temp;
 }
 }
 }
}
int main() {
 int n;
 printf("Enter the number of products: ");
 scanf("%d", &n);
 int prices[n];
 printf("Enter the product prices:\n");
 for (int i = 0; i < n; i++) {
 scanf("%d", &prices[i]);
 }
 bubble_sort(prices, n);
 printf("Sorted Prices (Bubble Sort):\n");
 for (int i = 0; i < n; i++) {
 printf("%d ", prices[i]);
 }
 printf("\n");
 return 0;
}
