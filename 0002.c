// infix to postfix
#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#define SIZE 50
char stack[SIZE];
int top = -1;
char infix[SIZE], postfix[SIZE];

void push(char val) {
	if (top == SIZE - 1) {
		printf("\nStack overflow!\n");
	}
	else {
		top++;
		stack[top] = val;
	}
}

char pop() {
	char x = -1;
	if (top == -1) {
		printf("\nStack underflow\n");
	}
	else {
		x = stack[top];
		top--;
	}
	return x;
}

char peek() {
	char x = -1;
	if (top == -1) {
		printf("\nStack underflow\n");
	}
	else {
		x = stack[top];
	}
	return x;
}

int getPriority(char op) {
	if (op == '*' || op == '/' || op == '%') return 3;
	if (op == '+' || op == '-') return 2;

	return 1;
}

int main() {
	int i=0, j=0;
	char x;
	// clrscr();
	printf("Enter the infix string: ");
	scanf("%s", infix);
	while (infix[i] != '\0') {
		x = infix[i];
		if(isalnum(x))
			postfix[j++] = x;
		else if(x == '+' || x == '-' || x == '*' || x == '/' || x == '%')
			if (top != -1 && getPriority(x) > getPriority(peek()))
				push(x);
			else {
				while (top != -1 && getPriority(x) <= getPriority(peek())) {
					postfix[j++] = pop();
				}
				push(x);
			}
		else if(x == '(')
			push(x);
		else if(x == ')') {
			while(top != -1 && peek() != '(') {
				postfix[j++] = pop();
			}
			pop();
		}
		else {
			printf("\nInvalid char");
			break;
		}
		i++;
	}
	while (top != -1) {
		postfix[j++] = pop();
	}
	printf("\n\n\nPostfix: %s\n\n\n", postfix);
	// getch();
	return 0;
}
