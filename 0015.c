// Merge two linked lists
#include <stdio.h>
#include <conio.h>
#include <malloc.h>

#define sn struct Node

sn {
	int data;
	sn* next;
} *start1, *start2, *merged;

sn* create(sn* start) {
	int n, i;
	printf("Enter the number of nodes: ");
	scanf("%d", &n);
	sn *temp, *nn;
	for (i = 0; i < n; i++) {
		nn = (sn*)malloc(sizeof(sn));
		nn->data = i + 1;
		nn->next = NULL;
		if (!start) {
			start = nn;
		}
		else {
			temp->next = nn;
		}
		temp = nn;
	}
	return start;
}

void print(sn* start) {
	sn* ptr;
	if (!start) {
		printf("\nThe list is empty\n");
		return;
	}
	else {
		ptr = start;
		printf("\nThe list is: ");
		while (ptr->next != NULL) {
			printf("%d -> ", ptr->data);
			ptr = ptr->next;
		}
		printf("%d", ptr->data);
		printf("\n");
	}
}

sn* merge(sn *l1, sn *l2) {
	sn* temp = l1;
	while (temp->next)
		temp = temp->next;
	
	temp->next = l2;
	return l1;
}

int main() {
	start1 = start2 = NULL;
	start1 = create(start1);
	start2 = create(start2);
	printf("\n\nList 1: ");
	print(start1);
	printf("\n\nList 2: ");
	print(start2);
	merged = merge(start1, start2);
	printf("\n\nMerged List: ");
	print(merged);
	return 0;
}