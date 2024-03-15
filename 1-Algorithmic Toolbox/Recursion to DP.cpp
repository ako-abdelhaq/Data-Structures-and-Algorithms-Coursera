/* Solving some problems to demonstrate how we can go from a recursive solution to a Dynamic programming solution
 (with memoization or tabulation) and vice versa
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Find all possible paths in a n*m grid

/*int grid_paths(int n , int m){
    vector<vector<int>> grid(n,vector<int>(m , 0));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if( i == 0 || j == 0 ){
                grid[i][j] = 1;
            }
            if( i+1 < n ){
                grid[i+1][j] += grid[i][j] ;
            }
            if( j+1 < m ){
                grid[i][j+1] += grid[i][j] ;
            }
        }
    }
    return grid[n-1][m-1];
}*/



// Count the number of parts of 'a' objects using parts up to 'b' partitions

/*int count(int a , int b){
    vector<vector<int>> dp( a+1 , vector<int>(b+1 , 0) );
    for(int i = 0 ; i < a+1 ; i++){
        for(int j = 0 ; j < b+1 ; j++){
            if( i == 0 ){
                dp[i][j] = 1;
            }
            
            else if( j == 0 ){
                dp[i][j] = 0;
            }
            
            if( j < b ){
                dp[i][j+1] += dp[i][j];
            }
            if( i+j <= a && j > 0 ){
                
                dp[i+j][j] += dp[i][j];
            }
            
        }
    }
    
    //for(int i = 0 ; i < a+1 ; i++){
        //for(int j = 0 ; j < b+1 ; j++){
            //cout<<dp[i][j]<<"  ";
        }
        //cout<<endl;
    //}
    
    return dp[a][b];
}
*/



// Calculate the Longest increasing subsequence of a sequence of n elements

int LIS(vector<int> v , int n , int max_){
    if(v.empty()){
        return 0;
    }
    if(n == 0){
        return 1;
    }
    vector<int> a;
    for(int i = n ; i > -1 ; i--){
        if(v[i] < v[n]){
            a.push_back(i);
        }
    }
    for(int i = 0 ; i < a.size() ; i++){
        max_ = max( max_ , 1 + LIS(v , a[i] , 0) );
    }
    max_ = max( max_ , LIS(v , n-1 , 0));
    
    return max_;
}

// Google Kickstart Round A 2020 stack of plates Problem :

int max_a(vector<vector<int>> stacks , int i , int p , int global_max){
    if( i == stacks.size()-1 && p < stacks[i].size() && p >= 0 ){
        return stacks[i][p];
    }
    else if(i == stacks.size()-1 && ( p > stacks[i].size()-1 || p < 0 )){
        return stacks[i][0];
    }
    else if( i > stacks.size()-1 ){
        return 0;
    }
    int local_max = 0;
    for(int j = 1 ; j < stacks[i].size() ; j++){
        if( p-j >= 0 ){
            local_max = max( stacks[i][j] + max_a(stacks,i+1, p-j , 0),
                                max_a( stacks , i+1 , p , 0) );
        }
        global_max = max(local_max , global_max);
    }
    return global_max;
}

int main()
{
   //cout << count( 7 , 4 ) << endl;
   vector<int> v = { 3, 7, 40, 80 } ;
   int n = v.size()-1;
   cout << LIS(v,n,0) << endl;
   return 0;
}