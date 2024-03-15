// A Memoized Solution of Edit Distance Problem ;
// It clculates the minimum operations to convert the string str1 to string str2 ;
#include <bits/stdc++.h>
using namespace std;

// Function to find minimum of three numbers "We need it later" :
int min(int x, int y, int z) { return min(min(x, y), z); }

int editDist(string str1, string str2, int m, int n , vector<vector<int>>& dp)
{
	// First of all , If the minimum operations of the two strings are already calculated and stored then return it
	if(dp[m][n] != -1)  return dp[m][n];
	
	else{
	    
	    // If first string is empty, the only option is to
	    // insert all characters of second string into first
	    if (m == 0){
	        dp[m][n] = n; // Store The Result
	        return n;
	    }
    
    	// If second string is empty, the only option is to
    	// remove all characters of first string
    	if (n == 0){
    	    dp[m][n] = m; // Store The Result
    		return m;
    	}
    
    	// If last characters of two strings are same ,Ignore last characters and recure for the remaining strings.
    	if (str1[m - 1] == str2[n - 1]){
    	    dp[m][n] = editDist(str1, str2, m - 1, n - 1,dp) ; // Store The Result
    		return dp[m][n];
    	}
    
    	// If last characters are not same, consider all three operations :
    	// operations on last character of first string ,
    	// recursively compute minimum cost for all three ,
    	// operations and take minimum of three values.
	    // Then store the result in the lookup table;
    	dp[m][n] = 1+ min(
    	            editDist(str1, str2, m, n - 1, dp), // Insert
    				editDist(str1, str2, m - 1, n, dp), // Remove
    				editDist(str1, str2, m - 1, n - 1, dp) // Replace
    			); // Store The Result
    			
    			
    	// Return the stored value :
    	return dp[m][n];

	}

}


int main()
{
	string str1 , str2 ;
	cin >> str1 ;
	cin >> str2 ;
    vector<vector<int>> dp(str1.length()+1 , vector<int>(str2.length()+1,-1));
	cout << editDist(str1 , str2 , str1.length() , str2.length() , dp) << endl;
	
	return 0;
}
