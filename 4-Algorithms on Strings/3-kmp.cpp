#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::string;
using std::vector;

// Find all occurrences of the pattern in the text and return a
// vector with all positions in the text (starting from 0) where 
// the pattern starts in the text.

vector<int> computePrefix(const string& text){
    int n = text.size();
    vector<int> prefix(n);
    prefix[0] = 0;
    int border = 0;
    for(int i = 1 ; i < n ; i++){
        while( border > 0 && text[border] != text[i] ){
            border = prefix[border-1];
        }
        if(text[i] == text[border]){
            border++;
        }else{
            border = 0;
        }
        prefix[i] = border;
    }
    return prefix;
}

vector<int> find_pattern(const string& pattern, const string& text) {
  vector<int> result;
  // Implement this function yourself
  
  int m = pattern.size() , n = text.size();
  vector<int> prefix = computePrefix(pattern + '@' + text);
  for(int i = m+1 ; i <= m+n ; i++){
    if( prefix[i] == m ){
        result.push_back(i - 2*m);
    }
  }
  return result;
}

int main() {
  string pattern, text;
  cin >> pattern;
  cin >> text;
  vector<int> result = find_pattern(pattern, text);
  for (int i = 0; i < result.size(); ++i) {
    printf("%d ", result[i]);
  }
  printf("\n");
  return 0;
}
