// Implement Topological Sort
#include<stdio.h>
#include<conio.h>
#define NODES 8
int visited[NODES] = { 0 };
char nodes[NODES] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };
int adj[NODES][NODES] = {
//   A  B  C  D  E  F  G  H 
	{0, 1, 1, 1, 0, 0, 0, 0},
	{0, 0, 1, 1, 1, 0, 0, 0},
	{0, 0, 0, 0, 1, 1, 0, 0},
	{0, 0, 0, 0, 1, 0, 1, 0},
	{0, 0, 0, 0, 0, 1, 1, 0},
	{0, 0, 0, 0, 0, 0, 1, 0},
	{0, 0, 0, 0, 0, 1, 1, 0}
};
int decOrder[NODES] = { 0 };
int incoming[NODES] = { 0 };

void dec(int node) {
	int i = 0;
	for (i = 0; i < NODES; i++) {
		if (adj[node][i] == 1 && incoming[i] != 0)
			incoming[i]--;
	}
}

void calcIncoming() {
	int i, j;
	for (i = 0; i < NODES; i++)
		for (j = 0; j < NODES; j++)
			if (adj[j][i] == 1)
				incoming[i]++;
}

int main() {
	int i, j, k = 0;
	calcIncoming();
	for (i = 0; i < NODES; i++)
		printf("%c: %d\t", nodes[i], incoming[i]);
}