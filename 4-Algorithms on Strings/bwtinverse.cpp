#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::pair;

/*void create(const string& bwt){
    int n = bwt.size();
    vector<pair<char,int>> col1(n) , col2(n);
    for(int i = 0 ; i < n ; i++){
        col2[i] = {bwt[i] , i};
        col1[i] = {bwt[i] , i};
    }
    sort(col1.begin(),col1.end());
    for(int i = 0 ; i < n ; i++){
        col2[col1[i].second].second = i;
        col1[i].second = i;
    }
    for(int i = 0 ; i < n ; i++){
        cout<<col1[i].first<<"  "<<col1[i].second<<"-------"<<col2[i].first<<" "<<col2[i].second<<endl;
    }
}
*/
string InverseBWT(const string& bwt) {
  string text = "";

  // write your code here
  
    int n = bwt.size();
    vector<pair<char,int>> col1(n) , col2(n);
    for(int i = 0 ; i < n ; i++){
        col2[i] = {bwt[i] , i};
        col1[i] = {bwt[i] , i};
    }
    sort(col1.begin(),col1.end());
    for(int i = 0 ; i < n ; i++){
        col2[col1[i].second].second = i;
        col1[i].second = i;
    }
    int curr = 0;
    for(int i = 0 ; i < n ; i++){
        text += col1[curr].first;
        curr = col2[curr].second;
    }
    reverse(text.begin(),text.end());
    return text;
}

int main() {
  string bwt;
  cin >> bwt;
  cout << InverseBWT(bwt) << endl;
  return 0;
}
