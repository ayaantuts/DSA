// Stack using Linked list
#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#define sn struct Node

sn {
	int data;
	sn* next;
} *top;

void push(int val) {
	sn* newnode = (sn*) malloc (sizeof(sn));
	newnode->data = val;
	newnode->next = top;
	top = newnode;
}

int pop() {
	int data = -1;
	sn* temp = top;
	if (top) {
		data = top->data;
		top = top->next;
		free(temp);
	}
	return data;
}

int peek() {
	int data = -1;
	if (top) {
		data = top->data;
	}
	return data;
}

void display() {
	sn* temp = top;
	while (temp) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}


int main() {
	int choice, val;
	top = NULL;
	do {
		printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
		scanf("%d", &choice);
		switch (choice) {
			case 1:
				printf("Enter value: ");
				scanf("%d", &val);
				push(val);
				break;
			case 2:
				val = pop();
				if (val == -1) {
					printf("Stack is empty\n");
				} else {
					printf("Popped value: %d\n", val);
				}
				break;
			case 3:
				val = peek();
				if (val == -1) {
					printf("Stack is empty\n");
				} else {
					printf("Top value: %d\n", val);
				}
				break;
			case 4:
				display();
				break;
			case 5:
				break;
			default:
				printf("Invalid choice\n");
		}
	} while (choice != 5);
	return 0;
}