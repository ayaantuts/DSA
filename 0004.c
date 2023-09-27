// Create next larger number using stack
#include <stdio.h>
#include <math.h>
#define SIZE 50
int stack[2][SIZE];
int top[2] = {-1, -1};

void push(int val, int i) {
	if (top[i] == SIZE - 1) {
		printf("\nStack overflow!\n");
	}
	else {
		top[i]++;
		stack[i][top[i]] = val;
	}
}

int pop(int i) {
	int x = -1;
	if (top[i] != -1) {
		x = stack[i][top[i]];
		top[i]--;
	}
	return x;
}

int peek(int i) {
	int x = -1;
	if (top[i] != -1) {
		x = stack[i][top[i]];
	}
	return x;
}

void display() {
	for(int i = top[0]; i >= 0; i--) {
		printf("%d", stack[0][i]);
	}
}

int main() {
	int num, n, rem, len = 0;
	printf("Enter the number: ");
	scanf("%d", &num);
	n = num;
	while (num > 0) {
		rem = num % 10;
		push(rem, 0);
		num /= 10;
		len++;
	}

	num = n;
	while(peek(0) != -1) {
		push(pop(0), 1);
	}

	int temp = peek(1);
	while (peek(1) >= temp) {
		push(pop(1), 0);
	}
	int a = pop(1);
	push(temp, 1);
	push(a, 1);
	while(peek(0) != -1) {
		push(pop(0), 1);
	}
	pop(1);
	while(peek(1) != -1) {
		push(pop(1), 0);
	}

	display();
	return 0;
}
