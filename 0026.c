// Implement Insertion sort
#include <stdio.h>
#include <conio.h>

int main() {
	int i, j, n, arr[100], current;
	printf("Enter the number of elements: ");
	scanf("%d", &n);
	printf("Enter the elements: ");
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	for (i = 1; i < n; i++) {
		current = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > current) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = current;
	}

	printf("\nSorted array: ");
	for (i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
}