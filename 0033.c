// Implement hashing techniques
#include <stdio.h>
#include <conio.h>

#define SIZE 10
int hash[SIZE] = {0};

int hashcode(int val) {
	return val % SIZE;
}

void insert(int val) {
	int index = hashcode(val);
	if (hash[index] == 0) {
		hash[index] = val;
	} else {
		int i = 1;
		while (hash[index + i] != 0) {
			i++;
		}
		hash[index + i] = val;
	}
}

int search(int val) {
	int index = hashcode(val);
	if (hash[index] == val) {
		return index;
	} else {
		int i = 1;
		while (hash[index + i] != val) {
			i++;
		}
		return index + i;
	}
}

void display() {
	int i;
	for (i = 0; i < SIZE; i++) {
		printf("%d ", hash[i]);
	}
	printf("\n");
}

int main() {
	int choice, val, index;
	do {
		printf("1. Insert\n2. Search\n3. Display\n4. Exit\n");
		scanf("%d", &choice);
		switch (choice) {
			case 1:
				printf("Enter value: ");
				scanf("%d", &val);
				insert(val);
				break;
			case 2:
				printf("Enter value: ");
				scanf("%d", &val);
				index = search(val);
				if (index != -1) {
					printf("Found at index %d\n", index);
				} else {
					printf("Not found\n");
				}
				break;
			case 3:
				display();
				break;
			case 4:
				break;
			default:
				printf("Invalid choice\n");
		}
	} while (choice != 4);
	return 0;
}