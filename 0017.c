// Implement DFS
#include <stdio.h>
#include <conio.h>
#define SIZE 50
int stack[SIZE];
int top = -1;
#define NODES 8
int visited[NODES] = {0};
char nodes[NODES] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
int adj[NODES][NODES] = {
//   A  B  C  D  E  F  G  H 
	{0, 1, 1, 1, 0, 0, 0, 0},
	{1, 0, 0, 0, 1, 0, 0, 1},
	{1, 0, 0, 0, 1, 0, 0, 0},
	{1, 0, 0, 0, 0, 1, 0, 0},
	{0, 1, 1, 0, 0, 0, 1, 0},
	{0, 0, 0, 1, 0, 0, 1, 0},
	{0, 0, 0, 0, 1, 1, 0, 1},
	{0, 1, 0, 0, 0, 0, 1, 0}
};

void push(int val) {
	if (top != SIZE - 1)
		stack[++top] = val;
}

int pop() {
	if (top != -1)
		return stack[top--];
	return -1;
}

int peek() {
	if (top != -1)
		return stack[top];
	return -1;
}

void dfs(int start) {
	int i, j;
	push(start);
	visited[start] = 1;
	printf("%c ", nodes[start]);
	for (i = 0; i < NODES; i++) {
		if (adj[start][i] == 1 && visited[i] == 0) {
			dfs(i);
		}
	}
	pop();
}

int main() {
	int i;
	printf("DFS: ");
	dfs(0);
	printf("\n");
	return 0;
}