// Implement Quick Sort
#include<stdio.h>
#include<conio.h>
#include<malloc.h>

int *a = NULL, n;

void swap(int i, int j) {
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

int partition(int l, int r) {
	int pivot = a[r], i, j;
	i = l - 1;
	for (j = l; j < r; j++)
		if (a[j] < pivot) {
			i++;
			swap(i, j);
		}
	swap(i + 1, r);
	return i + 1;
}

void quickSort(int l, int r) {
	int pivot;
	if (l < r) {
		pivot = partition(l, r);
		quickSort(l, pivot - 1);
		quickSort(pivot + 1, r);
	}
}

int main() {
	int i;
	printf("Enter the number of elements: ");
	scanf("%d", &n);
	a = (int *)malloc(n * sizeof(int));
	printf("Enter the elements: ");
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	quickSort(0, n - 1);
	for(i = 0; i < n; i++)
		printf("%d ", a[i]);
}