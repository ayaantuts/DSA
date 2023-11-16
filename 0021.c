// Implement linear search
#include <stdio.h>
#include <conio.h>

int linearSearch(int arr[], int n, int key) {
	int i;
	for (i = 0; i < n; i++) {
		if (arr[i] == key) {
			return i;
		}
	}
	return -1;
}

int main() {
	int arr[100], i, n;
	printf("Enter the number of elements: ");
	scanf("%d", &n);
	printf("Enter the elements: ");
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	int key;
	printf("Enter the element to be searched: ");
	scanf("%d", &key);
	int index = linearSearch(arr, n, key);
	if (index == -1) {
		printf("Element not found");
	} else {
		printf("Element found at index %d", index);
	}
	return 0;
}