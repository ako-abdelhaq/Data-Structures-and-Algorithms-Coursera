#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

int minRefills(int d , int m , vector<int>& stations){
    int n = -1 , currentPosition = 0 , i = 0 , lastPosition;
    sort(stations.begin(),stations.end());
    while( currentPosition + m < d && i < (int)stations.size() ){
        lastPosition = currentPosition;
        while( i < (int)stations.size() ){
            if( stations[i] - currentPosition > m ){
                i--;
                break;   
            }
            else if( stations[i] - currentPosition == m){    
                break;
            }
            else{
                i++;
            }
        }
        if( i == (int)stations.size() ){
            i--;
        }
        currentPosition = stations[i];
        if( lastPosition == currentPosition ){
            break;
        }
        if( d <= currentPosition ){
            break;    
        }
        n++;
    }
    if( (d-currentPosition) > m )   return -1;
    if( (d-currentPosition) <= m && currentPosition < d){
        n++;
    }
    return n;
}


int main()
{
    int d , m , n;
    cin>>d;
    cin>>m;
    cin>>n;
    vector<int> stations(n);
    for(int i = 0 ; i < n ; i++){
        cin >> stations[i];
    }
    cout<<minRefills( d , m , stations)<<endl;
   
    return 0;
}