#include <iostream>

using namespace std;

int moneyChange(int m){
    int n=0;
    if(m<=0)    return 0;
    while(m>0){
        while(m>=10){
            m-=10;
            n++;
        }
        while(m<10 && m>=5){
            m-=5;
            n++;
        }
        while(m<5 && m>0){
            m--;
            n++;
        }
    }
    return n;
}

int main()
{
    int m;
    cin >> m;
    cout << moneyChange(m) << endl; 
   
   return 0;
}