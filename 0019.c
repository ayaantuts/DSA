// Implement Topological Sort
#include<stdio.h>
#include<conio.h>
#define NODES 8
int visited[NODES] = { 0 };
int incoming[NODES] = { 0 };
char nodes[NODES] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };
int adj[NODES][NODES] = { 0 };
/*
int adj[NODES][NODES] = {
//   A  B  C  D  E  F  G  H 
	{0, 1, 1, 1, 0, 0, 0, 0},
	{0, 0, 1, 1, 1, 0, 0, 0},
	{0, 0, 0, 0, 1, 1, 0, 0},
	{0, 0, 0, 0, 1, 0, 1, 0},
	{0, 0, 0, 0, 0, 1, 1, 0},
	{0, 0, 0, 0, 0, 0, 1, 0},
	{0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 1, 1, 0}
};
*/

void calcIncoming() {
	int i, j;
	for (i = 0; i < NODES; i++)
		for(j = 0; j < NODES; j++)
			if (adj[i][j] == 1)
				incoming[j]++;
}

void sort(int node) {
	int i;
	printf("%c ", nodes[node]);
	visited[node] = 1;
	for (i = 0; i < NODES; i++)
		if (adj[node][i] == 1)
			incoming[i]--;
}

void topologicalSort() {
	int i, j, k;
	for (i = 0; i < NODES; i++)
		if (incoming[i] == 0 && visited[i] == 0)
			sort(i);
	
	for (i = 0; i < NODES; i++)
		if (incoming[i] != 0)
			topologicalSort();
}

int main() {
	int i, j;
	printf("Enter the adjacency matrix: \n");
	for (i = 0; i < NODES; i++)
		for (j = 0; j < NODES; j++)
			scanf("%d", &adj[i][j]);

	calcIncoming();
	topologicalSort();
	return 0;
}