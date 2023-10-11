// Implement Polynomial addition using Linked List
#include <stdio.h>
#include <malloc.h>

struct Node {
	int coeff, pow;
	struct Node *next;
} *start1, *start2, *start3;

struct Node* createLL(struct Node* start) {
	int i, n, coeff, pow;
	struct Node *newnode, *temp = start;
	printf("\nEnter the number of terms: ");
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		newnode = (struct Node*) malloc(sizeof(struct Node));
		printf("Enter the coefficient and power(separated by space): ");
		scanf("%d %d", &coeff, &pow);
		newnode->coeff = coeff;
		newnode->pow = pow;
		if (!start)
			start = newnode;
		else
			temp->next = newnode;
		
		temp = newnode;
		newnode->next = NULL;
	}
	return start;
}

void insertEnd(struct Node* temp, int c, int p) {
	struct Node *newnode = (struct Node*) malloc(sizeof(struct Node*)), *ptr = temp;
	newnode->coeff = c;
	newnode->pow = p;
	if (!temp)
		temp = newnode;
	else {
		while (ptr->next != NULL) {
			ptr = ptr->next;
		}
		ptr->next = newnode;
	}
	newnode->next = NULL;
}

struct Node* addIt() {
	struct Node *t1 = start1, *t2 = start2, *t3 = start3;
	while(t1 && t2) {
		if (t1->pow > t2->pow) {
			insertEnd(t3, t1->coeff, t1->pow);
			t1 = t1->next;
		}
		else if (t1->pow < t2->pow) {
			insertEnd(t3, t2->coeff, t2->pow);
			t2 = t2->next;
		}
		else {
			insertEnd(t3, t1->coeff + t2->coeff, t1->pow);
			t1 = t1->next;
			t2 = t2->next;
		}
	}
	while (t1) {
		insertEnd(t3, t1->coeff, t1->pow);
		t1 = t1->next;
	}
	
	while (t2) {
		insertEnd(t3, t2->coeff, t2->pow);
		t2 = t2->next;
	}
	return t3;
}

struct Node* display(struct Node* start) {
	printf("\n%dx%d", start->coeff, start->pow);
	struct Node* temp = start->next;
	while (temp != NULL) {
		if (temp->coeff < 0)
			printf("-");
		else
			printf("+");
		printf("%dx%d", temp->coeff, temp->pow);
		temp = temp->next;
	}
	printf("\n");
}

int main() {
	start1 = start2 = start3 = NULL;
	start1 = createLL(start1);
	start2 = createLL(start2);
	start3 = addIt();
	display(start1);
	display(start2);
	display(start3);
	return 0;
}