// Reverse a Linked List
#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#define sn struct Node

sn {
	int data;
	sn* next;
} *start, *rev;

sn* create(sn* start) {
	int n, i;
	sn *nn, *temp = NULL;
	printf("Enter the number of nodes: ");
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		nn = (sn*) malloc (sizeof(sn));
		nn->data = i + 1;
		nn->next = NULL;
		if (!start)
			start = nn;

		else
			temp->next = nn;
		temp = nn;
	}
	return start;
}

sn* next(sn* temp) {
	if (temp->next == NULL)
		rev = temp;

	else
		next(temp->next)->next = temp;
	return temp;
}

void display(sn* start) {
	sn* temp = start;
	printf("\n");
	if (!temp)
		printf("List is empty!");
	else {
		while (temp->next) {
			printf("%d -> ", temp->data);
			temp = temp->next;
		}
		printf("%d", temp->data);
	}
	printf("\n");
}

int main() {
	start = create(start);
	display(start);
	if (start)
		next(start)->next = NULL;
	display(rev);
}