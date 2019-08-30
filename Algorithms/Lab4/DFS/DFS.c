#include <stdio.h>
#include <stdlib.h>

int graph[100][100];

int Vertices;

int mark[100];

void dfs_visit(int Vertices) {
	printf("Visiting %d\n", Vertices);
	mark[Vertices] = 1;
	int i;
	for (i = 0; i < Vertices; ++i) {
		if ((graph[Vertices][i] == 1) && (i != Vertices) && !(mark[i]) ) {
			dfs_visit(i);
		}
	}
}

void dfs_main() {
	int i;
	for (i = 0; i < Vertices; ++i) {
		if (!mark[i]) {
			dfs_visit(i);
		}
	}
}

int main (void) {
	printf("Enter no of vertices: ");
	scanf(" %d", &Vertices);
	int i, j;
	printf("Enter adjacency matrix: ");
	for (i = 0; i < Vertices; ++i) {
		for (j = 0; j < Vertices; ++j) {
			scanf(" %d", &graph[i][j]);
		}
	}
	dfs_main();
	return 0;
}
