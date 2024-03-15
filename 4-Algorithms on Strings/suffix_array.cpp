#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <utility>

using std::cin;
using std::cout;
using std::endl;
using std::make_pair;
using std::pair;
using std::string;
using std::vector;

// Build suffix array of the string text and
// return a vector result of the same length as the text
// such that the value result[i] is the index (0-based)
// in text where the i-th lexicographically smallest
// suffix of text starts.
vector<int> BuildSuffixArray(const string& text) {
  vector<int> result;
  // Implement this function yourself
  int n = text.size();
  vector<pair<string,int>> suffixes;
  string s = "";
  string t;
  for(int i = n-1 ; i > -1 ; i--){
    s += text[i];
    t = s;
    reverse(t.begin(),t.end());
    suffixes.push_back(make_pair(t,i));
  }
  sort(suffixes.begin() , suffixes.end());
  
  for(auto& suffix : suffixes){
    result.push_back(suffix.second);
  }
  return result;
}

int main() {
  string text;
  cin >> text;
  vector<int> suffix_array = BuildSuffixArray(text);
  for (int i = 0; i < suffix_array.size(); ++i) {
    cout << suffix_array[i] << ' ';
  }
  cout << endl;
  return 0;
}
