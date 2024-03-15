#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::pair;
using namespace std;

void previsit(int x , vector<vector<int>> adj , vector<int>& pre , int& c){
    pre[x] = c;
    c++;
}

void postvisit(int x , vector<vector<int>> adj , vector<int>& post , int& c){
    
    post[x] = c;
    c++;
}

void explore(vector<vector<int>> adj, int x , vector<bool>& used , vector<int>& pre, vector<int>& post , int& c){
    used[x] = true;
    //previsit(x , adj , pre , c );
    for(int i = 0 ; i < adj[x].size() ; i++){
        if(!used[ adj[x][i] ]){
            explore(adj , adj[x][i] , used , pre , post , c );
        }
    }
    postvisit(x , adj , post , c);
}


vector<int> toposort(vector<vector<int>> adj) {
  //write your code here
  vector<bool> used(adj.size() , false);
  vector<int> post(adj.size() , 0) , pre(adj.size() , 0);
  int c = 1;
  for(int i = 1 ; i < adj.size() ; i++){
    if( !used[i] ){
      explore(adj , i , used , pre , post , c);
    }
  }
  
  return post;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n+1, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x].push_back(y);
  }
  
  vector<int> order_ = toposort(adj);
  vector<int> order(order_.size());
  for(int i = 1 ; i < order.size() ; i++){
    order[n+1-order_[i]] = i;
  }
  for(int i = 1 ; i < order.size() ; i++){
    cout<<order[i]<<" ";
  }
  cout<<endl;
}