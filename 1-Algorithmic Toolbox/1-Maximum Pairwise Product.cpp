#include <iostream>
#include <vector>

using namespace std;

typedef long long big;

big MaxProduct(vector<int> v){
    int m = v.size();
    big result = v[0];
    int index1 = 0 , index2 = -1;
    for(int i = 0 ; i < m ; i++){
        if( v[index1] <= v[i]){
            index1 = i ;
        }
    }
    for(int i = 0 ; i < m ; i++){
        if( ( v[index2] <= v[i] && index2 != -1 && i != index1 ) || ( index2 == -1 && i != index1 ) ){
            index2 = i ;
        }
    }
    return m > 1 ? (big)v[index1]*v[index2] : (big)v[index1];
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0 ; i < n ; i++)  cin>>v[i];
    cout << MaxProduct(v) << endl;
   return 0;
}