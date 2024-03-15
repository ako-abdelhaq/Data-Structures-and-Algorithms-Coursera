#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

struct{
    bool operator()(pair<double,pair<int,int>> p1 , pair<double,pair<int,int>> p2){
        return p1.first>p2.first;
    }
}CustomCompare;

long double maximumLoot(vector<pair<double,pair<int,int>>>& values , int w){
    long double loot = 0;
    sort( values.begin() , values.end() , CustomCompare);
    int i = 0;
    while( w > 0 && i < (int)values.size() ){
        while(values[i].second.second > 0 && w > 0){
            loot += values[i].first ;
            w--;
            values[i].second.second--;
        }
        i++;
    }
    return loot;
}

int main()
{
    int n , w;
    cin >> n >> w;
    vector<pair<int,int>> items(n);
    vector<pair<double,pair<int,int>>> values(n);
    for(int i=0 ; i < n ; i++){
        cin >> items[i].first >> items[i].second;
        values[i].first = (double)items[i].first / (double)items[i].second;
        values[i].second.first = items[i].first;
        values[i].second.second = items[i].second;
    }
    cout << dec << right << fixed << setprecision(4); 
    cout << maximumLoot(values,w);
   
   return 0;
}