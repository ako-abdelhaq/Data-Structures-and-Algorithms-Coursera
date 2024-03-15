/* This is a naive solution of this problem which can be improved further by changing the tree from a tree that stores 
the string into a tree that stores only the begining and the length of the string in the edges */ 
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <map>

using std::map;
using std::vector;
using std::string;
using std::pair;
using namespace std;

typedef map<string , int> edges;
typedef vector<edges> trie;

trie build_trie(vector<string> & patterns) {
  trie t;
  // write your code here
  edges e;
  t.push_back(e);
  int node = 0;
  for(auto& p : patterns){
    int currNode = 0;
    for(int i = p.size()-1 ; i > -1 ; i-- ){
        string c = "";
        c = p[i];
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
  
  for(int i = 0 ; i < t.size() ; i++){
    for(auto& m : t[i]){
        int curr = m.second;
        string s_temp = m.first;
        while( t[curr].size() == 1 ){
            for(auto& j : t[curr]){
                s_temp =  s_temp + j.first ;
                t[curr].erase(j.first);
                curr = j.second;
                break;
            }
        }
        t[i].erase(m.first);
        t[i][s_temp] = curr;
    }
  }
  return t;
}

// Build a suffix tree of the string text and return a vector
// with all of the labels of its edges (the corresponding 
// substrings of the text) in any order.
vector<string> ComputeSuffixTreeEdges(const string& text) {
  vector<string> result;
  // Implement this function yourself
  vector<string> suffixes;
  string s = "";
  for(int i = text.length()-1 ; i > -1 ; i--){
    s += text[i];
    suffixes.push_back(s);
  }
  trie t = build_trie(suffixes);
  for(int i = 0 ; i < t.size() ; i++){
    for(auto m : t[i]){
        result.push_back(m.first);
    }
  }
  return result;
}

int main() {
  string text;
  cin >> text;
  vector<string> edges = ComputeSuffixTreeEdges(text);
  for (int i = 0; i < edges.size(); ++i) {
    cout << edges[i] << endl;
  }
  return 0;
}