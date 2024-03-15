/* A DP implementation of 
0-1 Knapsack with repititions problem */

#include <bits/stdc++.h> 
using namespace std; 

int max(int a, int b) { return (a > b) ? a : b; } 

int knapSack(int W , vector<int> wt , vector<int> val , vector<int>& dp) 
{ 
	// Base Case 
	if ( W <= 0 ) 
		return 0; 
    
    // If the result corresponding to the current knapsack weight and has been already calculated then return it
    if(dp[W] != -1) return dp[W];
    
    // Otherwise :
    
    int m = 0; 
    
    // loop through all the elements :
	for(int i = 0 ; i < wt.size() ; i++){
	    // Choose the elements that have weights less than or equal to our current knaspack's weight and choose the one of them that has the  maximum value :
	    if( wt[i] <= W ){
	        // Recursively choose the maximum value using the same logic :
	        m = max( val[i] + knapSack(W - wt[i] ,  wt , val , dp) ,  m); 
	    }
	}
	
	// store the calculated result and return it :
    dp[W] = m;
    
	return dp[W];
} 

int main() 
{ 
	int W , n;
	cin>>W;
	cin>>n;
    vector<int> values(n) , weights(n) ;
    for(int i = 0 ; i < n ; i++){
        cin>>values[i]>>weights[i];
    }
    vector<int> dp( W + 1 , -1);
	cout << knapSack(W, weights, values ,dp) << endl; 
	return 0; 
} 
