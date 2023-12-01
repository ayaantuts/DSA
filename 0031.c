// Queue using Linked list
#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#define sn struct Node

sn {
	int data;
	sn* next;
} *front, *rear;

void enqueue() {
	int val;
	sn* newnode = (sn*) malloc (sizeof(sn));
	printf("Enter value: ");
	scanf("%d", &val);
	newnode->data = val;
	newnode->next = NULL;
	if (rear) {
		rear->next = newnode;
		rear = newnode;
	} else {
		front = rear = newnode;
	}
}

int dequeue() {
	int data = -1;
	sn* temp = front;
	if (front) {
		data = front->data;
		front = front->next;
		free(temp);
	}
	return data;
}

int peek() {
	int data = -1;
	if (front) {
		data = front->data;
	}
	return data;
}

void display() {
	sn* temp = front;
	while (temp) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main() {
	int choice, val;
	front = rear = NULL;
	do {
		printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
		scanf("%d", &choice);
		switch (choice) {
			case 1:
				enqueue();
				break;
			case 2:
				val = dequeue();
				if (val != -1) {
					printf("Dequeued: %d\n", val);
				} else {
					printf("Queue is empty\n");
				}
				break;
			case 3:
				val = peek();
				if (val != -1) {
					printf("Peeked: %d\n", val);
				} else {
					printf("Queue is empty\n");
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
}