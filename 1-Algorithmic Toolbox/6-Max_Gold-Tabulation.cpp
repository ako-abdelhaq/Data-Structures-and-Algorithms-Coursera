#include <bits/stdc++.h> 
#include <vector>
#include <algorithm>
using namespace std; 
  
int knapSackRec(int W, vector<int> wt,  vector<int> val, int i, vector<vector<int>>& dp){ 
    
    // base condition 
    if(i < 0){ 
        return 0;
    }

    if(dp[i][W] != -1){ 
        return dp[i][W];
    }
  
    if(wt[i] > W) { 
        dp[i][W] = knapSackRec(W , wt , val , i - 1, dp); 
        return dp[i][W]; 
    } 
    
    else{ 
        dp[i][W] = max( wt[i]+knapSackRec(W-wt[i],wt,val,i-1,dp) , knapSackRec(W,wt,val,i-1,dp) ); 
        return dp[i][W]; 
    }
    
} 
  
int knapSack(int W , vector<int> wt , vector<int> val , int n ){
    
    vector<vector<int>> dp(n);
    
    for (int i = 0; i < n; i++) 
        dp[i].resize(W + 1); 
  
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < W + 1; j++) 
            dp[i][j] = -1; 

    return knapSackRec(W, wt, val, n - 1, dp); 
} 

  
int main() 
{ 
    int w , n;
    cin>>w>>n;
    vector<int> wt(n);
    
    for(int i = 0 ; i < n ; i++){
        cin>>wt[i];
    }
    
    vector<int> val(n,1);
    
    cout << knapSack(w, wt, val, n); 
    
    return 0; 
}