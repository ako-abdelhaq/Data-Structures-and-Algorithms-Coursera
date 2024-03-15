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

int number_of_components( vector<vector<int>> adj ){
    vector<bool> state(adj.size() , false);
    int count = 0;
    for(int i = 1 ; i < adj.size() ; i++){
        if(!state[i]){
            explore(adj , i , state);
            count++;
        }
    }
    return count;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n+1, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  std::cout << number_of_components(adj);
}