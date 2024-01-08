// Implement Linked List
#include <stdio.h>
#include <conio.h>
#include <malloc.h>

struct Node {
	int data;
	struct Node* next;
} *start;

void insert_begin(int val) {
	struct Node* new_node;
	new_node = (struct Node*) malloc(sizeof(struct Node));
	new_node->data = val;
	new_node->next = start;
	start = new_node;
}

void insert_before(int val, int num) {
	struct Node* new_node, *ptr;
	new_node = (struct Node*) malloc(sizeof(struct Node));
	new_node->data = val;
	ptr = start;
	if (ptr->data == num) {
		start = new_node;
		new_node->next = ptr;
	}
	else {
		while (ptr->next->data != num) {
			ptr = ptr->next;
		}
		new_node->next = ptr->next;
		ptr->next = new_node;
	}
}

void insert_after(int val, int num) {
	struct Node* new_node, *ptr;
	new_node = (struct Node*) malloc(sizeof(struct Node));
	new_node->data = val;
	ptr = start;
	while (ptr->data != num) {
		ptr = ptr->next;
	}
	new_node->next = ptr->next;
	ptr->next = new_node;
}

void delete_node(int val) {
	if (!start) {
		printf("The list is empty\n");
	}
	else {
		struct Node* ptr, *preptr;
		ptr = start;
		if (ptr->data == val) {
			start = ptr->next;
			free(ptr);
		} else {
			while (ptr->data != val) {
				preptr = ptr;
				ptr = ptr->next;
			}
			preptr->next = ptr->next;
			free(ptr);
		}
	}
}

void print() {
	struct Node* ptr;
	if (!start) {
		printf("The list is empty\n");
		return;
	}
	else {
		ptr = start;
		printf("The list is: ");
		while (ptr->next != NULL) {
			printf("%d->", ptr->data);
			ptr = ptr->next;
		}
		printf("%d", ptr->data);
		printf("\n");
	}
}

int main() {
	start = NULL;
	int choice, data, num;
	do {
		printf("\n1. Insert Begin\n2. Insert Before\n3. Insert after\n4. Delete a node\n5. Print\n6. Exit\n\nEnter a choice: ");
		scanf("%d", &choice);
		switch(choice) {
			case 1:
				printf("Enter data: ");
				scanf("%d", &data);
				insert_begin(data);
				break;
			case 2:
				printf("Enter data: ");
				scanf("%d", &data);
				printf("Enter number before which you want to insert: ");
				scanf("%d", &num);
				insert_before(data, num);
				break;
			case 3:
				printf("Enter data: ");
				scanf("%d", &data);
				printf("Enter number after which you want to insert: ");
				scanf("%d", &num);
				insert_after(data, num);
				break;
			case 4:
				printf("Enter data: ");
				scanf("%d", &data);
				delete_node(data);
				break;
			case 5:
				print();
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