/* A Memoized implementation of discrete Knapsack problem without repitions */
// Prerequisite : See the Memoized Solution of Discrete Knapsack with repititions ;
/* The main idea is to recursively return the maximum value case between two cases :
    1/ If we take the current element into the knapsack ;
                or
    2/ If we don't take the element ; 
    
    The dp 2D-array is used to store the calculated optimal subproblems's solutions 
    where the dp[W][i] respresents the maximum value we can obtain by taking the 
    elements from the first element to the element number 'i' into the knapsack 
    of weight W ( our current weight )
*/

#include <bits/stdc++.h> 
using namespace std; 


// Returns the maximum value that 
// can be put in a knapsack of capacity W 
int knapSack(int W, vector<int> wt, vector<int> val, int i , vector<vector<int>>& dp) 
{ 

	// Base Case 
	if ( W == 0 ){
	    dp[W][i] = 0;
	    return 0;
	}
    //If the optimal solution of the current size and the first i-items is already exists then return it
    if(dp[W][i] != -1){
        return dp[W][i];
    }
	// If weight of the nth item is more 
	// than Knapsack capacity W, then 
	// this item cannot be included 
	// in the optimal solution , So
	// we don't take it into our knapsack 
	// and we continue further to the other elements :
	if (wt[i] > W) {
		dp[W][i] = knapSack(W, wt, val, i - 1 , dp); 
		return dp[W][i];
	}

	// Return the maximum of two cases: 
	// (1) i-th item included  
	// (2) not included 
	else{
		dp[W][i] = max( val[i] + knapSack(W - wt[i], wt, val, i-1, dp), knapSack(W, wt, val, i-1 , dp)); 
		// Store the result and return it :
		return dp[W][i];
	}
	
} 

int main() 
{ 
    int W , n;
    cin>>W>>n;
	vector<int> val(n+1) , wt(n+1 , 1) ;
	vector<vector<int>> dp(W+1,vector<int>(n+1,-1));
	val[0] = 0 ; wt[0] = 0;
	for(int i = 1 ; i <= n ; i++){
	    cin>>val[i];
	}
	for(int i = 1 ; i <= n ; i++){
	    cin>>wt[i];
	}
	
	cout << knapSack(W, wt, val, n , dp) << endl;
	
	return 0; 
} 
