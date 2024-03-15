#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

string leftRotate(string s, int d) {
    
    string rotated = s;
    reverse(rotated.begin(), rotated.begin()+d);
    reverse(rotated.begin()+d, rotated.end());
    reverse(rotated.begin(), rotated.end());
    
    return rotated;
}

string BWT(const string& text) {
  string result = "";
  
  // write your code here
  
  int n = text.size();
  vector<string> textRotations(n , "");
  
  for(int i = 0 ; i < n ; i++){
    textRotations[i] = leftRotate(text , i);
  }
  
  sort(textRotations.begin() , textRotations.end());
  
  for(int i = 0 ; i < n ; i++){
    result += textRotations[i][n-1];
  }
  
  return result;
}

int main() {
  string text;
  cin >> text;
  cout << BWT(text) << endl;
  return 0;
}