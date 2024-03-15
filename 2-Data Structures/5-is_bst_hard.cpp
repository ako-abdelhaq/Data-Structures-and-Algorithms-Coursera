#include <algorithm>
#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;
using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct Node {
  long long key;
  int left;
  int right;

  Node() : key(0), left(-1), right(-1) {}
  Node(long long key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};

bool IsBinarySearchTreeUtility(int r ,const vector<Node>& tree , long long min_ , long long max_){
    if(r < 0){
        return true;
    }
    
    if( r < tree.size() ){
        if( tree[r].key < min_ || tree[r].key >= max_ ){
          return false;
        }
    }
    
    
    return IsBinarySearchTreeUtility(tree[r].left , tree , min_ ,tree[r].key)
    && IsBinarySearchTreeUtility(tree[r].right , tree , tree[r].key, max_);
    
}

bool IsBinarySearchTree(const vector<Node>& tree) {
  // Implement correct algorithm here
  if(tree.empty()){
    return true;
  }
  return IsBinarySearchTreeUtility(0 , tree , LLONG_MIN , LLONG_MAX);
}

int main() {
  int nodes;
  cin >> nodes;
  vector<Node> tree;
  for (int i = 0; i < nodes; ++i) {
    long long key;
    int left, right;
    cin >> key >> left >> right;
    tree.push_back(Node(key, left, right));
  }
  if (IsBinarySearchTree(tree)) {
    cout << "CORRECT  " << endl;
  } else {
    cout << "INCORRECT" << endl;
  }
  return 0;
}
