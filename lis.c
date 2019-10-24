#include <iostream>
#include <climits>
using namespace std;

// Iterative function to find length of longest increasing subsequence
// of given array
int LIS(int arr[], int n)
{
	// array to store sub-problem solution. L[i] stores the length
	// of the longest increasing subsequence ends with arr[i]
	int L[n] = { 0 };

	// longest increasing subsequence ending with arr[0] has length 1
	L[0] = 1;

	// start from second element in the array
	for (int i = 1; i < n; i++)
	{
		// do for each element in subarray arr[0..i-1]
		for (int j = 0; j < i; j++)
		{
			// find longest increasing subsequence that ends with arr[j]
			// where arr[j] is less than the current element arr[i]

			if (arr[j] < arr[i] && L[j] > L[i])
				L[i] = L[j];
		}

		// include arr[i] in LIS
		L[i]++;
	}

	// find longest increasing subsequence (having maximum length)
	int lis = INT_MIN;
	for (int x : L)
		lis = max(lis, x);

	return lis;
}

// main function
int main()
{
	int arr[] = { 0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15 };
	int n = sizeof(arr)/sizeof(arr[0]);

	cout << "Length of LIS is " << LIS(arr, n);

	return 0;
}