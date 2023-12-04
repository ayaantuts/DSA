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

struct Node* createNode(int c, int p) {
	struct Node *newnode;
	newnode = (struct Node*) malloc(sizeof(struct Node));
	newnode->coeff = c;
	newnode->pow = p;
	newnode->next = NULL;
	return newnode;
}

void addIt() {
	int c, p;
	struct Node *t1 = start1, *t2 = start2, *t3 = start3;
	while(t1 && t2) {
		if (t1->pow > t2->pow) {
			c = t1->coeff;
			p = t1->pow;
			t1 = t1->next;
		}
		else if (t1->pow < t2->pow) {
			c = t2->coeff;
			p = t2->pow;
			t2 = t2->next;
		}
		else {
			c = t1->coeff + t2->coeff;
			p = t1->pow;
			t1 = t1->next;
			t2 = t2->next;
		}
		t3->next = createNode(c, p);
		t3 = t3->next;
	}
	while (t1) {
		t3->next = createNode(t1->coeff, t1->pow);
		t1 = t1->next;
		t3 = t3->next;
	}
	
	while (t2) {
		t3->next = createNode(t2->coeff, t2->pow);
		t2 = t2->next;
		t3 = t3->next;
	}
}

void subIt() {
	int c, p;
	struct Node *t1 = start1, *t2 = start2, *t4 = start4;
	while(t1 && t2) {
		if (t1->pow > t2->pow) {
			c = t1->coeff;
			p = t1->pow;
			t1 = t1->next;
		}
		else if (t1->pow < t2->pow) {
			c = -1 * t2->coeff;
			p = t2->pow;
			t2 = t2->next;
		}
		else {
			c = t1->coeff - t2->coeff;
			p = t1->pow;
			t1 = t1->next;
			t2 = t2->next;
		}
		t4->next = createNode(c, p);
		t4 = t4->next;
	}
	while (t1) {
		t4->next = createNode(t1->coeff, t1->pow);
		t1 = t1->next;
		t4 = t4->next;
	}
	
	while (t2) {
		t4->next = createNode(-1 * t2->coeff, t2->pow);
		t2 = t2->next;
		t4 = t4->next;
	}
}

void display(struct Node* start) {
	if (!start) {
		printf("\nEmpty polynomial");
		return;
	}
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

// Remove dummy nodes
void removeDummy() {
	struct Node *temp = start3;
	start3 = start3->next;
	free(temp);
	temp = start4;
	start4 = start4->next;
	free(temp);
}

int main() {
	start1 = start2 = NULL;
	start1 = createLL(start1);
	start2 = createLL(start2);
	// Dummy nodes
	start3 = createNode(0, 0);
	start4 = createNode(0, 0);
	addIt();
	subIt();
	removeDummy();
	printf("\nPolynomial 1: ");
	display(start1);
	printf("\nPolynomial 2: ");
	display(start2);
	printf("\nAddition: ");
	display(start3);
	printf("\nSubtraction: ");
	display(start4);
	return 0;
}