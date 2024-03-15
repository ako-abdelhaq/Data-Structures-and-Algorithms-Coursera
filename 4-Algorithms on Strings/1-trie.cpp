#include <string>
#include <iostream>
#include <vector>
#include <map>

using std::map;
using std::vector;
using std::string;
using std::pair;

typedef map<char, int> edges;
typedef vector<edges> trie;

trie build_trie(vector<string> & patterns) {
  trie t;
  // write your code here
  edges e;
  t.push_back(e);
  int node = 0;
  for(auto& p : patterns){
    int currNode = 0;
    for(char& c : p){
        if(currNode<t.size() && t[currNode].find(c) != t[currNode].end()){
            currNode = t[currNode][c];
        }
        else{
            t[currNode][c] = ++node;
            edges e;
            t.push_back(e);
            currNode = node;
        }
    }
  }
  return t;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<string> patterns;
  for (size_t i = 0; i < n; i++) {
    string s;
    std::cin >> s;
    patterns.push_back(s);
  }

  trie t = build_trie(patterns);
  for (size_t i = 0; i < t.size(); ++i) {
    for (const auto & j : t[i]) {
      std::cout << i << "->" << j.second << ":" << j.first << "\n";
    }
  }

  return 0;
}