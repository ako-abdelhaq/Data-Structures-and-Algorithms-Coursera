#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Min_Hops(int n , vector<int>& v){
    if(v[n] != -1){
        return v[n];
    }
    else{
        if(n%2 == 0){
            if(n%3 == 0){
                v[n] = min(min(1+Min_Hops(n-1 , v),1+Min_Hops(n/2 , v)) , 1+Min_Hops(n/3 , v));
            }
            else{
                v[n] = min(1+Min_Hops(n-1 , v),1+Min_Hops(n/2 , v));
            }
        }
        else{
            if(n%3 == 0){
                v[n] = min(1+Min_Hops(n-1 , v) , 1+Min_Hops(n/3 , v));
            }
            else{
                v[n] = 1+Min_Hops(n-1 , v);
            }
        }
        return v[n];
    }
}

vector<int> OptimalSequence( vector<int> seq){
    vector<int> ans ;
    int i  = seq.size() - 1;
    while(i > 0) {
        ans.push_back(i);
        if(i % 3 == 0) {
            if(seq[i / 3] == seq[i] - 1){
                i /= 3;
            } else {
                i -= 1;
            }
        }else if(i % 2 == 0){
            if(seq[i / 2] == seq[i] - 1){
                i /= 2;
            }else{
                i -= 1;
            }
        }else{
            i -= 1;
        }
    }
    ans.shrink_to_fit();
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int> v(n+1,-1);
    v[0] = -1;
    v[1] = 0;
    int a = Min_Hops(n , v);
    cout<<a<<endl;
    vector<int> s = OptimalSequence(v);
    for(int i = s.size()-1 ; i > -1 ; i--){
        cout<<s[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}