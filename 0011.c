// Addition of two numbers using Linked list for representation
#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#define sn struct Node

sn {
	int data;
	sn *next;
} *num1, *num2, *sumNum;

sn* create(sn* start) {
	sn *temp = start, *nn;
	int n;
	printf("\nEnter the number: ");
	scanf("%d", &n);
	while (n > 0) {
		nn = (sn*)malloc(sizeof(sn));
		nn->data = n % 10;
		nn->next = NULL;
		if (start == NULL) {
			start = nn;
		} else {
			temp->next = nn;
		}
		temp = nn;
		n /= 10;
	}
	return start;
}

void append(int el) {
	sn *temp = sumNum, *nn = (sn*)malloc(sizeof(sn));
	nn->data = el;
	nn->next = NULL;
	if (!sumNum)
		sumNum = nn;
	else {
		while (temp->next) {
			temp = temp->next;
		}
		temp->next=nn;
	}
}

void sum() {
	int currSum, carry = 0;
	sn* t1 = num1, *t2 = num2;
	while (t1 && t2) {
		currSum = t1->data + t2->data + carry;
		carry = 0;
		if (currSum > 9) {
			carry++;
			currSum -= 10;
		}
		append(currSum);
		t1 = t1->next;
		t2 = t2->next;
	}
	while (t1) {
		append(t1->data);
		t1 = t1->next;
	}
	while (t2) {
		append(t2->data);
		t2 = t2->next;
	}
}

void display(sn* start) {
	sn *temp;
	temp = start;
	printf("\n");
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main() {
	num1 = num2 = sumNum = NULL;
	num1 = create(num1);
	num2 = create(num2);
	sum();
	display(num1);
	display(num2);
	display(sumNum);
	return 0;
}