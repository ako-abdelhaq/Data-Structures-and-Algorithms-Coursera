#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int ChangeMoney( int n , vector<int>& DP){

    if(n==0 || n==2){
        DP[n] = n;
        return n;
    }
    
    if( n==1 || n==3 || n==4 ){
        DP[n] = 1;
        return 1;
    }
    
    if( DP[n] == -1 && n-4 > 0  ){
        DP[n] = min(1+ChangeMoney(n-1,DP),min(1+ChangeMoney(n-3,DP),1+ChangeMoney(n-4,DP)));
    } 
    
    return DP[n];
}

int main()
{
    int n;
    cin>>n;
    vector<int> precalculated(n+1 , -1);
    cout<<ChangeMoney(n,precalculated)<<endl;
    return 0;
}