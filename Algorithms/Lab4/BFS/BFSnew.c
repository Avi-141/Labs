#include <stdio.h>
#include <stdlib.h>

int graph[100][100];

int vertices;

int marked[100];

int queue[100], front = 0, rear = 0;

void push (int vert) {
	queue[rear++] = vert;
}

int pop () {
	if (front == rear) return -1;
	return queue[front++];
}

void bfs_visit (int vert) {
	printf("Current vertex%d\n", vert);
	marked[vert] = 1;
	int i;
	for (i = 0; i < vertices; ++i) {
		if (!marked[i] && graph[vert][i] && i != vert) {
			push(i);
		}
	}
}

void bfscall () {
	int i, x;
	push(0);
	do {
		x = pop();
		if (x != -1 && !marked[x]) {
			bfs_visit(x);
		}
	} while (x != -1);
}

int main (void) {
	printf("Total vertices: ");
	scanf(" %d", &vertices);
	int i, j;
	printf("Enter adj matrix: ");
	for (i = 0; i < vertices; ++i) {
		for (j = 0; j < vertices; ++j) {
			scanf(" %d", &graph[i][j]);
		}
	}
	bfscall();
	return 0;
}
