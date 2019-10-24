#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// M x N matrix
#define M 5
#define N 5

// Iterative function to find the minimum cost to traverse from the
// first cell to last cell of a matrix
int findMinCost(int cost[M][N])
{
	// T[i][j] maintains minimum cost to reach cell (i, j) from cell (0, 0)
	int T[M][N];

	// fill matrix in bottom-up manner
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			T[i][j] = cost[i][j];

			// fill first row (there is only one way to reach any cell in
			// the first row, that is from its adjacent left cell)
			if (i == 0 && j > 0)
				T[0][j] += T[0][j - 1];

			// fill first column (there is only one way to reach any cell
			// in the first column, that is from its adjacent top cell)
			else if (j == 0 && i > 0)
				T[i][0] += T[i - 1][0];

			// fill rest of the matrix (there are two way to reach any cell
			// in the rest of the matrix, that is from its adjacent left
			// cell or adjacent top cell)
			else if (i > 0 && j > 0)
				T[i][j] += min(T[i - 1][j], T[i][j - 1]);
		}
	}

	// last cell of T[][] stores min cost to reach destination cell
	// (M-1, N-1) from source cell (0, 0)
	return T[M - 1][N - 1];
}

// main function
int main()
{
	int cost[M][N] =
	{
		{ 4, 7, 8, 6, 4 },
		{ 6, 7, 3, 9, 2 },
		{ 3, 8, 1, 2, 4 },
		{ 7, 1, 7, 3, 7 },
		{ 2, 9, 8, 9, 3 }
	};

	cout << "The minimum cost is " << findMinCost(cost);

	return 0;
}