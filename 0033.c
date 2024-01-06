// Implement hashing techniques
#include <stdio.h>
#include <conio.h>

#define SIZE 10
int hash[SIZE] = {0};

int hashcode(int val) {
	return val % SIZE;
}

int linearProbing(int hashcode, int iteration) {
	int index = (hashcode + iteration) % SIZE;
	return index;
}

int quadraticProbing(int hashcode, int iteration)  {
	// c1, c2 will be given
	const int c1 = 1, c2 = 3;
	int index = (hashcode + c1 * iteration + c2 * iteration * iteration) % SIZE;
	return index;
}

void insert(int val) {
	int hashC = hashcode(val), index = hashC, i = 1;
	while (hash[index] != 0 && i < SIZE)
		index = linearProbing(hashC, i++);
	if (i == SIZE)
		printf("Hash table is full\n");
	else
		hash[index] = val;
}

int search(int val) {
	int hashC = hashcode(val), i = 1, index;
	if (hash[hashC] == val) {
		return hashC;
	} else {
		while (hash[index] != val && i < SIZE) {
			index = linearProbing(hashC, i);
			i++;
		}
		if (hash[index] == val) {
			return index;
		} else {
			return -1;
		}
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