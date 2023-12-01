// Implement Polynomial addition and subtraction using Linked List
#include <stdio.h>
#include <malloc.h>

struct Node {
	int coeff, pow;
	struct Node *next;
} *start1, *start2, *start3, *start4;

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

void insertEnd3(int c, int p) {
	struct Node *newnode, *temp = start3;
	newnode = (struct Node*) malloc(sizeof(struct Node));
	newnode->coeff = c;
	newnode->pow = p;
	if (!start3)
		start3 = newnode;
	else {
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = newnode;
	}
	newnode->next = NULL;
}

void insertEnd4(int c, int p) {
	struct Node *newnode, *temp = start4;
	newnode = (struct Node*) malloc(sizeof(struct Node));
	newnode->coeff = c;
	newnode->pow = p;
	if (!start4)
		start4 = newnode;
	else {
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = newnode;
	}
	newnode->next = NULL;
}

void addIt() {
	struct Node *t1 = start1, *t2 = start2;
	while(t1 && t2) {
		if (t1->pow > t2->pow) {
			insertEnd3(t1->coeff, t1->pow);
			t1 = t1->next;
		}
		else if (t1->pow < t2->pow) {
			insertEnd3(t2->coeff, t2->pow);
			t2 = t2->next;
		}
		else {
			insertEnd3(t1->coeff + t2->coeff, t1->pow);
			t1 = t1->next;
			t2 = t2->next;
		}
	}
	while (t1) {
		insertEnd3(t1->coeff, t1->pow);
		t1 = t1->next;
	}
	
	while (t2) {
		insertEnd3(t2->coeff, t2->pow);
		t2 = t2->next;
	}
}

void subIt() {
	struct Node *t1 = start1, *t2 = start2;
	while(t1 && t2) {
		if (t1->pow > t2->pow) {
			insertEnd4(t1->coeff, t1->pow);
			t1 = t1->next;
		}
		else if (t1->pow < t2->pow) {
			insertEnd4(-1 * t2->coeff, t2->pow);
			t2 = t2->next;
		}
		else {
			insertEnd4(t1->coeff - t2->coeff, t1->pow);
			t1 = t1->next;
			t2 = t2->next;
		}
	}
	while (t1) {
		insertEnd4(t1->coeff, t1->pow);
		t1 = t1->next;
	}
	
	while (t2) {
		insertEnd4(-1 * t2->coeff, t2->pow);
		t2 = t2->next;
	}
}

void display(struct Node* start) {
	printf("\n%dx^%d", start->coeff, start->pow);
	struct Node* temp = start->next;
	while (temp != NULL) {
		if (temp->coeff >= 0)
			printf("+");
		printf("%dx^%d", temp->coeff, temp->pow);
		temp = temp->next;
	}
	printf("\n");
}

int main() {
	start1 = start2 = start3 = start4 =  NULL;
	start1 = createLL(start1);
	start2 = createLL(start2);
	addIt();
	subIt();
	display(start1);
	display(start2);
	printf("\nAddition: ");
	display(start3);
	printf("\nSubtraction: ");
	display(start4);
	return 0;
}