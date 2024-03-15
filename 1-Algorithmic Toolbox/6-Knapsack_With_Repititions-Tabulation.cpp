/* A DP implementation of 
Discrete Knapsack with repititions problem */

#include <bits/stdc++.h> 
using namespace std; 

int max(int a, int b) { return (a > b) ? a : b; } 

int knapSack(int W , vector<int> wt , vector<int> val , vector<int> dp) 
{ 
	
	// The first loop ( variable : w ) represents all the knapsacks from 0 to W so: 
	for(int w = 0 ; w < W+1 ; w++){
	    
	    //The second loop ( variable : i) represents all the weigths W_i
	    for(int i = 0 ; i < wt.size() ; i++){
	        
	        // If the weight is less than or equal to the current knapsack's weight :
	        if( wt[i] <= w ){
	            /* Then the optimal solution is the maximum of { value( w - W_i ) + val[i] } 
	            which represents the value of 
	            " The knapsack without the element W_i ( value( w - W_i ) ) + the value corresponding to its weight ( val[i] ) " 
	            from all the elements that their weight less than or equal to the current knapsack's weight  */
	            dp[w] = max( dp[ w - wt[i] ] + val[i] , dp[w] );
	        }
	        
	    }
	    
	}
	
	//Return the optimal solution of the Knapsack of weight W :
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
    vector<int> dp( W + 1 , 0);
	cout << knapSack(W, weights, values ,dp) << endl; 
	return 0; 
} 
