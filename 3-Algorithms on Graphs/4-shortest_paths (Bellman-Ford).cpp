#include <iostream>
#include <vector>
#include <stack>
#include <climits>

using std::vector;
using std::stack;
using std::pair;
using namespace std;

void explore(vector<vector<int>> adj, int x , vector<int>& cycle , vector<bool>& state , vector<long long> distance){
    if(state[x]){
        return;
    }
    cycle.push_back(x);
    state[x] = true;
    for(int i = 0 ; i < adj[x].size() ; i++){
        if( !state[ adj[x][i] ] && distance[x] != LLONG_MAX){
            explore(adj , adj[x][i] , cycle , state , distance);
        }
    }
}

struct edge{
    int from;
    int to;
    int weight;
    edge(){}
    edge(int f , int t , int w ){
        from = f;
        to = t;
        weight = w;
    }
    edge operator = (edge e){
        edge r(e.from , e.to , e.weight);
        return r;
    }
};

pair<vector<long long>,stack<int>> negative_cycle( int V , vector<edge> edges , int s) {
  //write your code here
  int E = edges.size();
  vector<long long> distances( V , LLONG_MAX);
  distances[s] = 0;
  stack<int> negative_indexes;
  for(int i = 0 ;  i < V-1 ; i++){
    for(int j = 0 ; j < E ; j++){
        edge e = edges[j];
        if(distances[e.from] != LLONG_MAX && distances[e.to] > distances[e.from] + (long long)e.weight ){
            distances[e.to] = distances[e.from] + (long long)e.weight;
        }
    }
  }
  for(int j = 0 ; j < E ; j++){
    edge e = edges[j];
    if((distances[e.from] != LLONG_MAX && distances[e.to] > distances[e.from] + (long long)e.weight) || (distances[e.from] == LLONG_MAX && distances[e.to] > distances[e.from] + (long long)e.weight) ){
    	negative_indexes.push(e.from);
    }
  }
  
  return {distances,negative_indexes};
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector< edge > edges(m);
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x-1].push_back(y-1);
    edge e(x-1 ,y-1 ,w);
    edges.push_back(e);
  }
  int s;
  std::cin >> s;
  s--;
  vector<long long> distance = negative_cycle( n , edges , s ).first ;
  stack<int> negative_indexes = negative_cycle( n , edges , s ).second ;
  vector<int> negative;
  vector<bool> state(n , false);
  while( !negative_indexes.empty() ){
    int curr = negative_indexes.top();
    negative_indexes.pop();
    explore(adj , curr , negative , state , distance);
  }
  /*for(int i = 0 ; i < distance.size() ; i++){
    cout<<distance[i]<<" ";
  }
  cout<<"\n\n";*/
  for(int i = 0 ; i < negative.size() ; i++){
    if( distance[negative[i]] != LLONG_MAX ){
        distance[negative[i]] = LLONG_MIN;
    }
  }

  for(int i = 0 ; i < distance.size() ; i++){
    if( distance[i] == LLONG_MIN ){
        std::cout<<"-"<<std::endl;
    }
    else if( distance[i] == LLONG_MAX ){
        std::cout<<"*"<<std::endl;
    }
    else{
        std::cout<<distance[i]<<std::endl;
    }
  }
}
