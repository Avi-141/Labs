#include <iostream>
#include <string>
using namespace std;

// Function to find best way to cut a rod of length n
// where rod of length i has a cost price[i-1]
int rodCut(int price[], int n)
{
	// T[i] stores maximum profit achieved from rod of length i
	int T[n + 1];

	// initialize maximum profit to 0
	for (int i = 0; i <= n; i++)
		T[i] = 0;

	// consider rod of length i
	for (int i = 1; i <= n; i++)
	{
		// divide the rod of length i into two rods of length j
		// and i-j each and take maximum
		for (int j = 1; j <= i; j++)
			T[i] = max(T[i], price[j - 1] + T[i - j]);
	}

	// T[n] stores maximum profit achieved from rod of length n
	return T[n];
}

// main function
int main()
{
	// int length[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int price [] = { 1, 5, 8, 9, 10, 17, 17, 20 };

	// rod length
	int n = 4;

	cout << "Profit is " << rodCut(price, n);

	return 0;
}