#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;

int minDistance(vector<long long> dist, vector<bool> sptSet)
{
    long long min = LLONG_MAX, min_index;
  
    for (int v = 0; v < sptSet.size() ; v++){
        if (sptSet[v] == false && dist[v] <= min){
            min = dist[v], min_index = v;
        }
    }
  
    return min_index;
}

long long distance(vector<vector<int>> &adj, vector<vector<int>> &cost, int s, int t) {
  //write your code her
  vector<long long> distances( adj.size() , LLONG_MAX);
  distances[s] = 0;
  vector<bool> sptSet(adj.size() , false); 

  for( int i = 0 ; i < adj.size()-1 ; i++ ){
    int u = minDistance(distances, sptSet);
    sptSet[u] = true;
    for(int j = 0 ; j < adj[u].size() ; j++){
        if(!sptSet[adj[u][j]] && distances[u] != LLONG_MAX && distances[adj[u][j]] > distances[u] + (long long)cost[u][j] ){
            distances[adj[u][j]] = distances[u] + (long long)cost[u][j];
        }
    }
  }
  
  return distances[t] < LLONG_MAX ? distances[t] : -1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int>> adj(n, vector<int>());
  vector<vector<int>> cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, cost, s, t);
}
