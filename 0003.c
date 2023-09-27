// Postfix expression evaluation
#include<stdio.h>
#include<conio.h>
#include<ctype.h>

#define SIZE 40
char postfix[SIZE];
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
	int i = 0, j = 0, result, op1, op2;
	char x;
	// clrscr();
	printf("Enter the postfix expression: ");
	scanf("%s", postfix);
	while (postfix[i] != '\0') {
		x = postfix[i];
		if (isalnum(x)) {
			push(x - '0');
		}
		else if (x == '+' || x == '-' || x == '*' || x == '/' || x == '%') {
			op2 = pop();
			op1 = pop();
			if (x == '+')
				result = op1 + op2;

			else if (x == '-')
				result = op1 - op2;
			
			else if (x == '*')
				result = op1 * op2;
			
			else if (x == '/')
				result = op1 / op2;
			
			else if (x == '%')
				result = op1 % op2;
			push(result);
		}
		else {
			printf("\nInvalid character!\n");
			break;
		}
		i++;
	}

	printf("\n\n\nThe result is %d\n\n\n", pop());
	// getch();
	return 0;
}
