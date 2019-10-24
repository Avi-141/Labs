#include <iostream>
#include <string>
#include <cstring>
using namespace std;

// Function to find Longest common substring of sequences
// X[0..m-1] and Y[0..n-1]
string LCS(string X, string Y, int m, int n)
{
	int maxlen = 0;			// stores the max length of LCS
	int endingIndex = m;	// stores the ending index of LCS in X

	// lookup[i][j] stores the length of LCS of substring
	// X[0..i-1], Y[0..j-1]
	int lookup[m + 1][n + 1];

	// initialize all cells of lookup table to 0
	memset(lookup, 0, sizeof(lookup));

	// fill the lookup table in bottom-up manner
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			// if current character of X and Y matches
			if (X[i - 1] == Y[j - 1])
			{
				lookup[i][j] = lookup[i - 1][j - 1] + 1;

				// update the maximum length and ending index
				if (lookup[i][j] > maxlen)
				{
					maxlen = lookup[i][j];
					endingIndex = i;
				}
			}
		}
	}

	// return Longest common substring having length maxlen
	return X.substr(endingIndex - maxlen, maxlen);
}

// main function
int main()
{
	string X = "ABC", Y = "BABA";
	int m = X.length(), n = Y.length();

	// Find Longest common substring
	cout << "The Longest common substring is " << LCS(X, Y, m, n);

	return 0;
}