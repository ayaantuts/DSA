// Implement binary search
#include <stdio.h>
#include <conio.h>

int binarySearch(int arr[], int n, int key) {
	int low = 0, mid, high = n;
	while (low <= high) {
		mid = (low + high) / 2;
		if (arr[mid] == key) {
			return mid;
		} else if (arr[mid] < key) {
			low = mid + 1;
		} else {
			high = mid - 1;
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
	int index = binarySearch(arr, n, key);
	if (index == -1) {
		printf("Element not found");
	} else {
		printf("Element found at index %d", index);
	}
	return 0;
}