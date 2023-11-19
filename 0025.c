// Implement selection sort
#include <stdio.h>
#include <conio.h>

int main() {
	int i, j, n, arr[100], min, temp;
	printf("Enter the number of elements: ");
	scanf("%d", &n);
	printf("Enter the elements: ");
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	for (i = 0; i < n - 1; i++) {
		min = i;
		for (j = i; j < n; j++) {
			if (arr[j] < arr[min]) {
				min = j;
			}
		}
		if (min != i) {
			temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}	
	}

	printf("\nSorted array: ");
	for (i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
}