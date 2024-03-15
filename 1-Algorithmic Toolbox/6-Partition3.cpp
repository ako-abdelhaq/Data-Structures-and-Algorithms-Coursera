// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;
map<string, int> dp;

// Function to check array can be
// partition into sum of 3 equal
int checkEqualSumUtil(int arr[], int N,
					int sm1,
					int sm2,
					int sm3, int j)
{
	string s = to_string(sm1)
			+ "_" + to_string(sm2)
			+ to_string(j);

	// Base Case
	if (j == N) {
		if (sm1 == sm2 && sm2 == sm3)
			return 1;
		else
			return 0;
	}

	// If value at particular index is not
	// -1 then return value at that index
	// which ensure no more further calls
	if (dp.find(s) != dp.end())
		return dp[s];

	else {

		// When element at index
		// j is added to sm1
		int l = checkEqualSumUtil(
			arr, N, sm1 + arr[j],
			sm2, sm3, j + 1);

		// When element at index
		// j is added to sm2
		int m = checkEqualSumUtil(
			arr, N, sm1, sm2 + arr[j],
			sm3, j + 1);

		// When element at index
		// j is added to sm3
		int r = checkEqualSumUtil(
			arr, N, sm1, sm2,
			sm3 + arr[j], j + 1);

		// Update the current state and
		// return that value
		return dp[s] = max(max(l, m), r);
	}
}

// Function to check array can be
// partition to 3 subsequences of
// equal sum or not
void checkEqualSum(int arr[], int N)
{
	// Initialise 3 sums to 0
	int sum1, sum2, sum3;

	sum1 = sum2 = sum3 = 0;

	// Function Call
	if (checkEqualSumUtil(
			arr, N, sum1,
			sum2, sum3, 0)
		== 1) {
		cout << "1";
	}
	else {
		cout << "0";
	}
}

// Driver Code
int main()
{
	int n;
	cin>>n;
	int v[n];
	for(int i = 0 ; i < n ;i++){
	    cin>>v[i];
	}
	checkEqualSum(v, n);

	return 0;
}
