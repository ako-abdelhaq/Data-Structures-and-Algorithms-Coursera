#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

using namespace std;

void explore(vector<vector<int>> adj, int x , vector<bool>& state){
    state[x] = true;
    for(int i = 0 ; i < adj[x].size() ; i++){
        if( !state[ adj[x][i] ] ){
            explore(adj , adj[x][i] , state);
        }
    }
}

vector<int> components( vector<vector<int>>& adj ){
    vector<bool> state(adj.size() , false);
    vector<int> connected ;
    for(int i = 0 ; i < adj.size() ; i++){
        if(!state[i]){
            connected.push_back(i);
            explore(adj , i , state);
        }
    }
    connected.shrink_to_fit();
    state.clear();
    state.shrink_to_fit();
    return connected;
}


int BFS( vector<vector<int>> adj , int s ){
    queue<int> q;
    vector<int> color(adj.size() , -1);
    color[s] = 1;
    q.push(s);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i = 0 ; i < adj[u].size() ; i++){
            if(color[adj[u][i]] == -1){
                q.push( adj[u][i] );
                color[ adj[u][i] ] = 1 - color[u];
            }
            else if( color[ adj[u][i] ] == color[u] || u == adj[u][i] ){
                return 0;
            }
        }
    }
    color.clear();
    color.shrink_to_fit();
    return 1;
}

int bipartite(vector<vector<int> > &adj) {
  //write your code here
  vector<int> connected = components(adj);
  connected.shrink_to_fit();
  int decision;
  for(int i = 0 ; i < connected.size() ; i++){
    decision = BFS( adj , connected[i] );
    if( decision == 0 ){
      return 0;
    }
  }
  connected.clear();
  connected.shrink_to_fit();
  return 1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << bipartite(adj);
}
