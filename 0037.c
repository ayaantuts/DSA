#include <stdio.h>
#include <conio.h>
#include <malloc.h>

#define sn struct Node

sn {
	int data;
	sn *next;
} *head = NULL;

void create() {
	int n, i;
	sn *temp, *last;
	printf("Enter the number of nodes: ");
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		temp = (sn *)malloc(sizeof(sn));
		temp->data = i + 1;
		temp->next = NULL;
		if (!head) {
			head = last = temp;
		} else {
			last->next = temp;
			last = temp;
		}
	}
}

void display() {
	sn *temp = head;
	while (temp) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
}

void reverse() {
	sn *prev, *curr, *next;
	prev = NULL;
	curr = head;
	while (curr) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	head = prev;
}

int main() {
	create();
	printf("Original list: ");
	display();
	reverse();
	printf("\nReversed list: ");
	display();
	return 0;
}