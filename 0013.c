// Reverse a sentence without reversing the words using stack
#include<stdio.h>
#include<conio.h>

#define SIZE 100
int stack[SIZE];
int top = -1;
char sentence[SIZE], rev[SIZE];
void push(int val) {
	if (top != SIZE - 1) {
		top++;
		stack[top] = val;
	}
}

int pop() {
	int x = -1;
	if (top != -1) {
		x = stack[top];
		top--;
	}
	return x;
}

int peek() {
	int x = -1;
	if (top != -1) {
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
			printf("%c ", stack[i]);
		}
		printf("\n");
	}
}

int main() {
	int i = 0, len = 0, j = 0;
	printf("\nEnter the sentence: ");
	scanf("%[^\n]s", sentence);
	while (sentence[i++] != '\0') {
		len++;
	}
	i = 0;
	j = len - 1;
	while (i <= len) {
		if (sentence[i] != ' ' && sentence[i] != '\0')
			push(sentence[i]);
		else {
			while (peek() != -1) {
				rev[j--] = pop();
			}
			rev[j--] = ' ';
		}
		i++;
	}
	printf("\nReversed: %s\n", rev);
	return 0;
}