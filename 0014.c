// Find n-th element from end of Linked List (using recursion)
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#define sn struct Node

sn {
	int data;
	sn *next;
} *head;

int n = 0;

sn* createLL() {
	int n, i;
	sn *temp, *nn;
	printf("Enter the number of nodes: ");
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		nn = (sn*) malloc(sizeof(sn));
		nn->data = i + 1;
		nn->next = NULL;
		if(!head) {
			head = nn;
		} else {
			temp->next = nn;
		}
		temp = nn;
	}
}

int nthFromLast(sn* temp) {
	int NumToGo;
	if (temp->next == NULL) {
		return n;
	}

	NumToGo = nthFromLast(temp->next);
	if (NumToGo > 1) {
		return --NumToGo;
	}
	else if (NumToGo == 1) {
		printf("%d", temp->data);
		return -1;
	}
	else {
		return -1;
	}
}

int main() {
	createLL();
	printf("N-th from last?: ");
	scanf("%d", &n);
	n -= 1;
	nthFromLast(head);
	return 0;
}