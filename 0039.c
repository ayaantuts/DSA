// Check if an expression has balanced paranthesis or not
#include<stdio.h>
#include<conio.h>
#define SIZE 50
char stack[SIZE];
int top = -1;
char expression[SIZE];

void push(char val) {
	if (top != SIZE - 1) {
		top++;
		stack[top] = val;
	}
}

char pop() {
	char x = -1;
	if (top != -1) {
		x = stack[top];
		top--;
	}
	return x;
}

char peek() {
	char x = -1;
	if (top != -1) {
		x = stack[top];
	}
	return x;
}

int main() {
	int i = 0, isValid = 1;
	char x, temp;
	printf("Enter the expression to check: ");
	scanf("%s", expression);
	while (expression[i] != '\0') {
		x = expression[i];
		if (x == '(' || x == '[' || x == '{')
			push(x);
		else if (x == ')' || x == ']' || x == '}') {
			temp = pop();
			if (x == ')' && temp != '(') {
				isValid = 0;
				break;
			}
			else if (x == ']' && temp != '[') {
				isValid = 0;
				break;
			}
			else if (x == '}' && temp != '{') {
				isValid = 0;
				break;
			}
		}
		i++;
	}
	if (peek() != -1)
		isValid = 0;
	if (isValid == 1)
		printf("Expression has balanced paranthesis");
	else
		printf("Expression has unbalanced paranthesis");
	return 0;
}