// Implement BFS and DFS menu-driven
#include <stdio.h>
#include <conio.h>
#include <malloc.h>

#define SIZE 50
int stack[SIZE], queue[SIZE], front = -1, rear = -1, top = -1;

#define NODES 8
int visited[NODES] = {0};
char nodes[NODES] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
int adj[NODES][NODES] = {0};

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

void enqueue(int val) {
	if (rear != SIZE - 1) {
		if (front == -1)
			front = 0;
		queue[++rear] = val;
	}
}

int dequeue() {
	int x = -1;
	if (front != -1)
		if (front != rear) {
			x = queue[front];
			front++;
		} else {
			x = queue[front];
			front = rear = -1;
		}
	return x;
}

int peekq() {
	if (front != -1)
		return queue[front];
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

void bfs(int start) {
	int i;
	visited[start] = 1;
	printf("%c ", nodes[start]);
	for (i = 0; i < NODES; i++) {
		if (adj[start][i] == 1 && visited[i] == 0) {
			enqueue(i);
			visited[i] = 1;
		}
	}
	dequeue();
	if (peekq() != -1)
		bfs(peekq());
}

int main() {
	int i, j, choice;
	printf("Enter adjacency matrix:\n");
	for (i = 0; i < NODES; i++) {
		for (j = 0; j < NODES; j++) {
			scanf("%d", &adj[i][j]);
		}
	}
	do {
		for (i = 0; i < NODES; i++) {
			visited[i] = 0;
		}
		printf("1. DFS\n2. BFS\n3. Exit\n");
		scanf("%d", &choice);
		switch (choice) {
			case 1:
				printf("DFS: ");
				dfs(0);
				printf("\n");
				break;
			case 2:
				printf("BFS: ");
				enqueue(0);
				bfs(0);
				printf("\n");
				break;
			case 3:
				break;
			default:
				printf("Invalid choice\n");
		}
	} while (choice != 3);
	return 0;
}