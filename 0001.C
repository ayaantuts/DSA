// Implement stack using array
#include<stdio.h>
#include<conio.h>

#define SIZE 5
int stack[SIZE];
int top = -1;

void push(int val) {
	if (top == SIZE - 1) {
		printf("\nStack overflow!\n");
	}
	else {
		top++;
		stack[top] = val;
	}
}

int pop() {
	int x = -1;
	if (top == -1) {
		printf("\nStack underflow\n");
	}
	else {
		x = stack[top];
		top--;
	}
	return x;
}

int peek() {
	int x = -1;
	if (top == -1) {
		printf("\nStack underflow\n");
	}
	else {
		x = stack[top];
	}
	return x;
}

void display() {
	int i;
	if (top == -1)
		printf("\nStack is empty\n");
	else {
		for (i = top; i >= 0; i--) {
			printf("%d ", stack[i]);
		}
		printf("\n");
	}
}

int main() {
	int choice, input, x;
	// clrscr();
	do {
		printf("Enter a choice\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
		scanf("%d", &choice);
		switch (choice) {
			case 1:
				printf("\nEnter the element to push: ");
				scanf("%d", &input);
				push(input);
				break;
			case 2:
				x = pop();
				if (x != -1)
					printf("\nElement popped is %d\n", x);
				break;
			case 3:
				x = peek();
				if (x != -1)
					printf("\nElement at the top is %d\n", x);
				break;
			case 4:
				printf("\nThe stack currently is:\n");
				display();
				break;
			case 5:
				break;
			default:
				printf("\nInvalid choice!\tTry again later\n");
				choice = 5;
		}
	} while (choice != 5);
	printf("\nExited! Press any key to close\n");
	// getch();
	return 0;
}