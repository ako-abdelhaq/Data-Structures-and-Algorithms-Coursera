/* A Tabulated implementation of discrete Knapsack problem without repitions */
// Prerequisite : See the Tabulated Solution of Discrete Knapsack with repititions ;
/* The main idea is to store the optimal solutions of the knapsacks of weight from 1 to W
    where w is our current knapsack weight in 2D-array called "dp" ;
    The dp 2D-array is used to store the calculated optimal subproblems's solutions 
    where the dp[W][i] respresents the maximum value we can obtain by taking the 
    elements from the first element to the element number 'i' into the knapsack 
    of weight w ( our current weight )
*/
#include <bits/stdc++.h> 
using namespace std; 


// Returns the maximum value that 
// can be put in a knapsack of capacity W 
int knapSack(int W, vector<int> wt, vector<int> val) 
{ 
    int n = wt.size();
    vector<vector<int>> dp( W+1 , vector<int>(n+1,0) ); // 2D-array to store the optimal solutions of subproblems
    
    // Loop through all the values of w from 1 to W ( the original Weight );
    for(int w = 0 ; w <= W ; w++){
        
        // Loop through each element from the weights array ;
        for(int i = 0 ; i <= n ; i++){
            
            // If the weight is zero '0' or the items to take between are zero item skip this iteration :
            if(w == 0 || i == 0){
                continue ; 
            }
            
            /* If an item has a weight less than or equal to the current weight 
               , then take the maximum between { " the optimal solution of the current
               knapsack but without taking the item " and " the optimal solution of the knapsack 
               without this item (so its weight is current weight - current item's weight) + 
               value of this item " } : */
            else if(wt[i] <= w){
                dp[w][i] = max(dp[w][i-1] , val[i]+dp[ w-wt[i] ][i-1]);
            }
            // Otherwise , take the optimal solution for a knapsack of the same weight and without 
            // taking the item :
            else{
                dp[w][i] = dp[w][i-1];
            }
        }
    }
    
    // Return the optimal solution of the knapsack of weight W (our Knapsack weight) when we choose 
    // from all the elements :
    return dp[W][n];
} 

int main() 
{ 
    int W , n;
    cin>>W>>n;
	vector<int> val(n+1) , wt(n+1 , 1) ;
	val[0] = 0 ; wt[0] = 0;
	for(int i = 1 ; i <= n ; i++){
	    cin>>val[i];
	}
	for(int i = 1 ; i <= n ; i++){
	    cin>>wt[i];
	}
	
	cout << knapSack(W, wt, val ) << endl;
	
	return 0; 
} 
