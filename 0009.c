// Implement circular linked list
#include <stdio.h>
#include <malloc.h>

struct Node {
	int data;
	struct Node *next;
} *start;

void create() {
	int n, i;
	struct Node *newnode, *temp;
	printf("\nEnter number of nodes: ");
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		newnode = (struct Node*) malloc (sizeof(struct Node));
		printf("\nEnter data: ");
		scanf("%d", &newnode->data);
		newnode->next = NULL;
		if (!start) {
			start = newnode;
			newnode->next = start;
		}
		else {
			temp = start;
			while (temp->next != start)
				temp = temp->next;
			temp->next = newnode;
			newnode->next = start;
		}
	}
}

void insertBegin() {
	struct Node *temp, *newnode;
	int data;
	printf("\nEnter value to be inserted: ");
	scanf("%d", &data);
	newnode = (struct Node*) malloc (sizeof(struct Node));
	newnode->data = data;
	temp = start;
	if (!start) {
		while (temp->next != start)
			temp = temp->next;
		temp->next = newnode;
		start = newnode;
		newnode->next = start;
	}
	else {
		while (temp->next != start)
			temp = temp->next;
		temp->next = newnode;
		newnode->next = start;
		start = newnode;
	}
}

void insertBefore() {
	struct Node *temp, *newnode;
	int val, data;
	printf("\nEnter value to be inserted: ");
	scanf("%d", &data);
	printf("\nEnter value of node to insert before: ");
	scanf("%d", &val);
	newnode = (struct Node*) malloc (sizeof(struct Node));
	newnode->data = data;
	newnode->next = NULL;
	if (start->data == val) {
		temp = start;
		while (temp->next != start)
			temp = temp->next;
		temp->next = newnode;
		newnode->next = start;
		start = newnode;
	}
	else {
		temp = start;
		while (temp->next->data != val)
			temp = temp->next;
		newnode->next = temp->next;
		temp->next = newnode;
	}	
}

void insertAfter() {
	struct Node *temp, *newnode;
	int val, data;
	printf("\nEnter value to be inserted: ");
	scanf("%d", &data);
	printf("\nEnter value of node to insert after: ");
	scanf("%d", &val);
	newnode = (struct Node*) malloc (sizeof(struct Node));
	newnode->data = data;
	newnode->next = NULL;
	temp = start;
	while (temp->data != val)
		temp = temp->next;
	newnode->next = temp->next;
	temp->next = newnode;
}

void deleteNode() {
	struct Node *temp, *del;
	int val;
	printf("\nEnter value of node to be deleted: ");
	scanf("%d", &val);
	if (start->data == val) {
		temp = start;
		while (temp->next != start)
			temp = temp->next;
		temp->next = start->next;
		del = start;
		start = start->next;
	}
	else {
		temp = start;
		while (temp->next->data != val)
			temp = temp->next;
		del = temp->next;
		temp->next = temp->next->next;
	}
	free(del);
}

void display() {
	struct Node *temp = start;
	printf("\nList: ");
	while (temp->next != start) {
		printf("%d -> ", temp->data);
		temp = temp->next;
	}
	printf("%d\n", temp->data);
}

int main() {
	start = NULL;
	create();
	int choice;
	do {
		printf("\n1. Insert at beginning\n2. Insert before\n3. Insert after\n4. Delete\n5. Display\n6. Exit\nEnter choice: ");
		scanf("%d", &choice);
		switch (choice) {
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
				deleteNode();
				break;
			case 5:
				display();
				break;
			case 6:
				break;
			default:
				printf("Invalid choice\n");
				choice = 6;
		}
	} while (choice != 6);
	return 0;
}