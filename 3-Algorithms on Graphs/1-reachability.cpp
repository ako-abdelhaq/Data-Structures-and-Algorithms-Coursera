#include <iostream>
#include <vector>

using std::vector;
using std::pair;

void explore(vector<vector<int>> adj, int x , vector<bool>& state){
    state[x] = true;
    for(int i = 0 ; i < adj[x].size() ; i++){
        if( !state[ adj[x][i] ] ){
            explore(adj , adj[x][i] , state);
        }
    }
}


bool reach(vector<vector<int>> adj, int x, int y) {
  //write your code here
  vector<bool> state(adj.size() , false);
  explore(adj , x , state);
  return state[y];
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n+1, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x].push_back(y );
    adj[y].push_back(x);
  }
  int x, y;
  std::cin >> x >> y;
  std::cout << reach(adj, x , y );
}