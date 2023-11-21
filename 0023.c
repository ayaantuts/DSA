// Implement fibonacci search
#include <stdio.h>
#include <conio.h>
#include <malloc.h>

int min(int x, int y) { return (x < y) ? x : y; }

int *arr = NULL, fibm = 1, fibm1 = 1, fibm2 = 0, offset = -1, n;

int fibSearch(int key) {
	int i;
	while (fibm2 > 0) {
		i = min(offset + fibm2, n - 1);
		if (arr[i] == key)
			return i;
		else if (arr[i] > key) {
			fibm = fibm2;
			fibm1 -= fibm2;
			fibm2 -= fibm1;
		}
		else {
			fibm = fibm1;
			fibm1 = fibm2;
			fibm2 = fibm - fibm1;
			offset = i;
		}
	}

	if (fibm1 && arr[offset + 1] == key)
		return offset + 1;
	return -1;
}

int main() {
	int i, key;
	printf("Enter the number of elements: ");
	scanf("%d", &n);
	arr = (int *) malloc (sizeof(int) * n);
	printf("\nEnter the elements: ");
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	
	while (fibm <= n) {
		fibm2 = fibm1;
		fibm1 = fibm;
		fibm = fibm1 + fibm2;
	}

	printf("\nEnter data to search: ", fibm);
	scanf("%d", &key);
	i = fibSearch(key);
	if (i == -1)
		printf("\nValue not found!");
	else
		printf("\nValue found at index %d!", i);
}