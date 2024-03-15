#include <bits/stdc++.h>

using namespace std;

int fib(long long num ){
    int pre=0,cur=1;
    num = num %60;
    if(num==0){
        return 0;}
    else if (num == 1){
        return 1;
    }
    else{
    	for (int i =2; i<=num; i++){
            int temp = (pre+cur)%60;
            pre = cur;
            cur = temp;
    	}
    }
    
    return(cur); 
}

int main() {
    long long n = 0;
    cin >> n;
    int a = fib(n);
    int b = fib(n+1);
    
    cout<<(a*b)%10;
    
    
}