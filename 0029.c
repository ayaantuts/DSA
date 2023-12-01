// Detect cycle in singly linked list
#include <stdio.h>
#include <conio.h>
#include <malloc.h>

#define sn struct Node

sn {
	int data;
	sn *next;
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
		if (!head) {
			head = newnode;
		} else {
			temp = head;
			while (temp->next) {
				temp = temp->next;
			}
			temp->next = newnode;
		}
	}
}

void detectCycle() {
	sn *slow, *fast;
	slow = fast = head;
	while (slow && fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) {
			printf("\nCycle detected!");
			return;
		}
	}
	printf("\nNo cycle detected!");
}

void main() {
	create();
	detectCycle();
	getch();
}