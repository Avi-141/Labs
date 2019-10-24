#include <iostream>
using namespace std;

// Return true if there exists a subarray of array[0..n) with given sum
bool subsetSum(int arr[], int n, int sum)
{
	// T[i][j] stores true if subset with sum j can be attained with
	// using items up to first i items
	bool T[n + 1][sum + 1];

	// if 0 items in the list and sum is non-zero
	for (int j = 1; j <= sum; j++)
		T[0][j] = false;

	// if sum is zero
	for (int i = 0; i <= n; i++)
		T[i][0] = true;

	// do for ith item
	for (int i = 1; i <= n; i++)
	{
		// consider all sum from 1 to sum
		for (int j = 1; j <= sum; j++)
		{
			// don't include ith element if j-arr[i-1] is negative
			if (arr[i - 1] > j)
				T[i][j] = T[i - 1][j];
			else
			// find subset with sum j by excluding or including the ith item
				T[i][j] = T[i - 1][j] || T[i - 1][j - arr[i - 1]];
		}
	}

	// return maximum value
	return T[n][sum];
}

// Subset Sum Problem
int main()
{
	// Input: set of items and a sum
	int arr[] = { 7, 3, 2, 5, 8 };
	int sum = 18;

	// number of items
	int n = sizeof(arr) / sizeof(arr[0]);

	if (subsetSum(arr, n, sum))
		cout << "Yes";
	else
		cout << "No";

	return 0;
}