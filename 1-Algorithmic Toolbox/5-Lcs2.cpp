#include <iostream> 
#include <algorithm>
#include <vector>

using namespace std; 

int lcs( vector<int> X, vector<int> Y, int m, int n , vector<vector<int>>& dp) { 
	if (m == 0 || n == 0){
	    dp[m][n] = 0;
		return 0; 
	}
	
	if(dp[m][n] != -1){
	    return dp[m][n];
	}
	
	if (X[m-1] == Y[n-1]){ 
	    dp[m][n] = 1 + lcs(X, Y, m-1, n-1, dp); 
		return dp[m][n];
	}
	else{
	    dp[m][n] = max( lcs(X, Y, m, n-1, dp) , lcs(X, Y, m-1, n, dp) ); 
		return dp[m][n];
	}
} 


int main() 
{ 
    int n1 , n2;
    cin>>n1;
	vector<int> arr1(n1);
	for(int i = 0 ; i < n1 ; i++){
	    cin>>arr1[i];
	}
	cin>>n2;
    vector<int> arr2(n2);
    for(int i = 0 ; i < n2 ; i++){
	    cin>>arr2[i];
	}
	vector<vector<int>> dp(n1+1 , vector<int>(n2+1,-1));
	cout<<lcs( arr1, arr2, n1, n2 ,dp) <<endl; 
	
	return 0; 
} 