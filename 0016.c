// Implement Doubly Linked List
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#define sn struct Node

sn {
	int data;
	sn *prev, *next;
} *start;

void createLL() {
	int i, n, data;
	sn *nn, *temp = start;
	printf("Enter the number of nodes: ");
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		nn = (sn*) malloc(sizeof(sn));
		printf("Enter data for node %d: ", i + 1);
		scanf("%d", &data);
		nn->data = data;
		nn->prev = temp;
		nn->next = NULL;
		if (!start) {
			start = nn;
		}
		else {
			temp->next = nn;
		}
		temp = nn;
	}
}

void display() {
	sn* temp = start;
	printf("\n");
	if (!start)
		printf("List is empty!\n");
	else {
		while (temp->next) {
			printf("%d <-> ", temp->data);
			temp = temp->next;
		}
		printf("%d", temp->data);
	}
	printf("\n");
}

void insertBegin() {
	int data;
	sn* nn = (sn*) malloc(sizeof(sn));
	printf("Enter data for node: ");
	scanf("%d", &data);
	nn->data = data;
	nn->prev = NULL;
	if (!start)
		start = nn;
	else {
		nn->next = start;
		start = nn;
	}
}

void insertBefore() {
	int data, val;
	sn *temp = start, *nn = (sn*) malloc(sizeof(sn));
	printf("\nEnter the data to insert: ");
	scanf("%d", &data);
	nn->data = data;
	nn->prev = NULL;
	nn->next = NULL;
	printf("\nEnter the data of the node before which you want to add: ");
	scanf("%d", &val);
	while (temp && temp->data != val)
		temp = temp->next;
	if (!temp) {
		printf("\nNode not found!");
	}
	else {
		if (temp == start) {
			nn->next = start;
			start = nn;
		}
		else {
			nn->prev = temp->prev;
			nn->next = temp;
			temp->prev->next = nn;
			temp->prev = nn;
		}
	}
}

void insertAfter() {
	int data, val;
	sn *temp = start, *nn = (sn*) malloc(sizeof(sn));
	printf("\nEnter the data to insert: ");
	scanf("%d", &data);
	nn->data = data;
	nn->prev = NULL;
	nn->next = NULL;
	printf("\nEnter the data of the node after which you want to add: ");
	scanf("%d", &val);
	while (temp && temp->data != val)
		temp = temp->next;
	if (!temp) {
		printf("\nNode not found!");
	}
	else {
		nn->prev = temp;
		nn->next = temp->next;
		if (temp->next)
			temp->next->prev = nn;
		temp->next = nn;
	}
}

void insertEnd() {
	int data;
	sn *nn = (sn*) malloc(sizeof(sn)), *temp = start;
	printf("\nEnter data for node: ");
	scanf("%d", &data);
	nn->data = data;
	nn->prev = NULL;
	nn->next = NULL;
	while (temp->next)
		temp = temp->next;
	if (!start)
		start = nn;
	else {
		nn->prev = temp;
		temp->next = nn;
	}
}

void deleteNode() {
	sn *temp = start, *del;
	int val;
	printf("\nEnter the data of node to delete: ");
	scanf("%d", &val);
	while (temp && temp->data != val)
		temp = temp->next;
	if (!temp)
		printf("\nNode not found!");
	else {
		del = temp;
		if (start->data == val) {
			start = start->next;
			if (start->next)
				start->prev = NULL;
		}
		else {
			if (temp->next)
				temp->next->prev = temp->prev;
			temp->prev->next = temp->next;
		}
		free(del);
	}
}

int main() {
	int choice;
	start = NULL;
	createLL();
	do {
		printf("\n1. Insert Begin\n2. Insert Before\n3. Insert After\n4. Insert End\n5. Delete a node\n6. Display\n7. Exit\nEnter your choice: ");
		scanf("%d", &choice);
		switch(choice) {
			case 1:
				insertBegin();
				break;
			case 2:
				insertBefore();
				break;
			case 3:
				insertAfter();
				break;
			case 4:
				insertEnd();
				break;
			case 5:
				deleteNode();
				break;
			case 6:
				display();
				break;
			case 7:
				break;
			default:
				printf("\nInvalid choice!!!\n");
				choice = 7;
		}
	} while (choice != 7);
	return 0;
}