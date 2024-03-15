#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long big;

big GCD(big a , big b){
    if( a % b == 0 || b % a == 0){
        return min(a,b);
    }
    else if( a == 0 || b == 0){
        return max(a,b);
    }
    else if( a < b ){
        return GCD(a,(b % a));
    }
    else if( a == 1 || b == 1){
        return min(a,b);
    }
    else{
        return GCD(b,(a % b));
    }
}

int main()
{
    big a , b;
    cin >> a >> b;
    big res = GCD(a,b);
    cout << res << endl;
   return 0;
}