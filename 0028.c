// Doubly Linked List
#include <stdio.h>
#include <conio.h>
#include <malloc.h>

#define sn struct Node

sn {
	int data;
	sn *next, *prev;
} *head = NULL;

void create() {
	int i, n, data;
	sn *temp, *newnode;
	printf("\nEnter number of nodes: ");
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		newnode = (sn *) malloc(sizeof(sn));
		printf("\nEnter data for node %d: ", i + 1);
		scanf("%d", &data);
		newnode->data = data;
		newnode->next = NULL;
		newnode->prev = NULL;
		if (!head) {
			head = newnode;
		} else {
			temp = head;
			while (temp->next) {
				temp = temp->next;
			}
			temp->next = newnode;
			newnode->prev = temp;
		}
	}
}

void insertBefore() {
	int data, key;
	sn *temp, *newnode;
	printf("\nEnter data to be inserted: ");
	scanf("%d", &data);
	printf("\nEnter data before you want to insert: ");
	scanf("%d", &key);
	newnode = (sn *) malloc(sizeof(sn));
	newnode->data = data;
	newnode->next = NULL;
	newnode->prev = NULL;
	if (!head) {
		head = newnode;
	} else {
		temp = head;
		while (temp->data != key) {
			temp = temp->next;
		}
		newnode->next = temp;
		newnode->prev = temp->prev;
		temp->prev->next = newnode;
		temp->prev = newnode;
	}
}

void insertAfter() {
	int data, key;
	sn *temp, *newnode;
	printf("\nEnter data to be inserted: ");
	scanf("%d", &data);
	printf("\nEnter data after you want to insert: ");
	scanf("%d", &key);
	newnode = (sn *) malloc(sizeof(sn));
	newnode->data = data;
	newnode->next = NULL;
	newnode->prev = NULL;
	if (!head) {
		head = newnode;
	} else {
		temp = head;
		while (temp->data != key) {
			temp = temp->next;
		}
		newnode->next = temp->next;
		newnode->prev = temp;
		temp->next->prev = newnode;
		temp->next = newnode;
	}
}

void deleteNode() {
	int key;
	sn *temp;
	printf("\nEnter data to be deleted: ");
	scanf("%d", &key);
	if (!head) {
		printf("\nList is empty.\n");
	} else {
		temp = head;
		while (temp->data != key) {
			temp = temp->next;
		}
		if (temp == head) {
			head = head->next;
			head->prev = NULL;
		} else if (!temp->next) {
			temp->prev->next = NULL;
		} else {
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
		}
		free(temp);
	}
}

void display() {
	sn *temp;
	if (!head) {
		printf("List is empty.\n");
	} else {
		temp = head;
		while (temp) {
			printf("%d <-> ", temp->data);
			temp = temp->next;
		}
		printf("\n");
	}
}

int main() {
	int choice;
	do {
		printf("\n1. Create\n2. Insert Before\n3. Insert After\n4. Delete\n5. Display\n6. Exit\nEnter your choice: ");
		scanf("%d", &choice);
		switch (choice) {
			case 1:
				create();
				break;
			case 2:
				insertBefore();
				break;
			case 3:
				insertAfter();
				break;
			case 4:
				deleteNode();
				break;
			case 5:
				display();
				break;
			case 6:
				break;
			default:
				printf("\nInvalid choice.\n");
		}
	} while (choice != 6);
	return 0;
}