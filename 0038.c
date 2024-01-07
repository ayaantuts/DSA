#include <stdio.h>
#include <malloc.h>

#define sn struct Node

sn {
	int data;
	sn *next;
};

sn *hashTable[10] = { NULL };

int hashCode(int val) {
	int index = val % 10;
	return index;
}

void insert(int val) {
	int hash = hashCode(val);
	sn *newNode = (sn *)malloc(sizeof(sn)), *temp;
	newNode->data = val;
	newNode->next = NULL;
	if (!hashTable[hash]) {
		hashTable[hash] = newNode;
	} else {
		temp = hashTable[hash];
		while (temp->next) {
			temp = temp->next;
		}
		temp->next = newNode;
	}
}

void searchVal(int val) {
	int hash = hashCode(val);
	sn *temp = hashTable[hash];
	while (temp && temp->data != val) {
		temp = temp->next;
	}
	if (temp)
		printf("Value found\n");
	else
		printf("Value not found\n");
}

void display() {
	sn *temp;
	for (int i = 0; i < 10; i++) {
		temp = hashTable[i];
		printf("%d: ", i);
		while (temp) {
			printf("%d ", temp->data);
			temp = temp->next;
		}
		printf("\n");
	}
}

int main() {
	int choice, val;
	while (1) {
		printf("1. Insert\n2. Search\n3. Display\n4. Exit\nEnter your choice: ");
		scanf("%d", &choice);
		switch (choice) {
			case 1:
				printf("Enter value to insert: ");
				scanf("%d", &val);
				insert(val);
				break;
			case 2:
				printf("Enter value to search: ");
				scanf("%d", &val);
				searchVal(val);
				break;
			case 3:
				display();
				break;
			case 4:
				return 0;
			default:
				printf("Invalid choice\n");
		}
	}
	return 0;
}