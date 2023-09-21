// Implement Linked List
#include <stdio.h>
#include <conio.h>
#include <malloc.h>

struct Node {
	int data;
	struct Node* next;
} *start;

void insert(int data) {
	if (!start) {
		start = (struct Node*) malloc(sizeof(struct Node));
		start->data = data;
		start->next = NULL;
		return;
	}
	struct Node* temp = start;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = (struct Node*) malloc(sizeof(struct Node));
	temp->next->data = data;
	temp->next->next = NULL;
}

void delete(int data) {
	if (!start) {
		printf("\nList is empty!");
		return;
	}
	struct Node* del;
	if (start->data == data) {
		if (start->next == NULL) {
			free(start);
			start = NULL;
			return;
		}
		del = start;
		start = start->next;
		free(del);
		return;
	}
	struct Node* temp = start;
	while(temp->next == NULL || temp->next->data != data) {
		temp = temp->next;
	}
	if (temp->next == NULL) {
		printf("\nElement not found!");
		return;
	}
	del = temp->next;
	temp->next = temp->next->next;
	free(del);
}

void display() {
	if (!start) {
		printf("\nList is empty!");
		return;
	}
	struct Node* temp = start;
	printf("\n");
	while(temp->next != NULL) {
		printf("%d->", temp->data);
		temp = temp->next;
	}
	printf("%d\n", temp->data);
}

int main() {
	start = NULL;
	int choice, data;
	do {
		printf("\n1. Insert\n2. Delete\n3. Print\n4. Exit\nEnter a choice: ");
		scanf("%d", &choice);
		switch (choice) {
			case 1:
				printf("\nEnter the value: ");
				scanf("%d", &data);
				insert(data);			
				break;
			case 2:
				printf("\nEnter the data to delete: ");
				scanf("%d", &data);
				delete(data);
				break;
			case 3:
				display();
				break;
			case 4:
				break;
			default:
				printf("\nInvalid choice!");
				choice = 4;
		}
	} while (choice != 4);
	return 0;
}