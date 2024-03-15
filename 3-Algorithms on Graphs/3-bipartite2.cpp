#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

bool bipartite(vector<vector<int>>& adj , int s , vector<bool>& reached){
    std::vector<int> color(adj.size() , -1);
    color[s] = 0;
    reached[s] = true;
    std::queue<int> q;
    q.push(s);
    
    while ( !q.empty()) {
        auto curr = q.front();
        reached[curr] = true;
        q.pop();
        for (auto n : adj[curr]) {
            if (color[n] == -1) {
                q.push(n);
                reached[n] = true;
                color[n] = !color[curr];
            } else if (color[n] == color[curr]) {
                return false;
            }
        }
    }
    
    for(int i = 0 ; i < reached.size() ; i++){
        if( !reached[i] ){
            reached[i] = true;
            return bipartite(adj , i , reached);
        }
    }
    return true;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<bool> reached(n , false);
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  
  bool flag =  bipartite(adj , 0 , reached);
  
  if(flag){
    std::cout<<"1";
  }else{
    std::cout<<"0";
  }
  return 0;
}
