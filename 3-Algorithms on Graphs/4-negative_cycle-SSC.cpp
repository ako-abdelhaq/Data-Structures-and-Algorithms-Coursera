#include <iostream>
#include <vector>
#include <stack>
#include <climits>

using std::vector;
using std::stack;



void dfs(vector<vector<int>> &adj, vector<int> &used, int x){
  used[x] = 1;
  for (int i = 0; i < adj[x].size(); i++) {
	if(!used[adj[x][i]]){
	  dfs(adj, used, adj[x][i]);
	}
  }
}

void dfs_sort(vector<vector<int>> &adj, vector<int> &used, stack<int> &order, int x) {
  used[x] = 1;
  for (int i = 0; i < adj[x].size(); i++) {
	if(!used[adj[x][i]]){
	  dfs_sort(adj, used, order, adj[x][i]);
    }
  }
  order.push(x);
}     

stack<int> toposort(vector<vector<int> > adj) {
  vector<int> used(adj.size(), 0);
  stack<int> order;
  for (int i = 0; i < adj.size(); i++) {
	if (!used[i]) {
	  dfs_sort(adj, used, order, i);
	}
  }
  return order;
}

vector<vector<int>> get_reverse_graph(vector<vector<int>> &adj){
	vector<vector<int>> r(adj.size(), vector<int>());
    for(int i = 0; i < adj.size(); i++){
	  for(int j = 0; j < adj[i].size(); j++){
		r[adj[i][j]].push_back(i);
	  }
	}
	return r;
}

vector<int> strongly_connected_components(vector<vector<int>> adj){
  vector<int> result;
  //write your code here
  stack<int> order = toposort(adj);
  vector<vector<int> > reversed = get_reverse_graph(adj);
  vector<int> used(adj.size() , 0) ;
  while (! order.empty()) {
    int x = order.top();
    order.pop();
    if (!used[x]) {
	  stack<int> componentStack;
	  result.push_back(x);
	  dfs_sort(reversed, used, componentStack, x);
	}
  }
  return result;
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

long long negative_cycle( int V , vector<edge> edges , int s , vector<bool>& reached) {
  //write your code here
  int E = edges.size();
  vector<long long> distances( V , LLONG_MAX);
  distances[s] = 0;
  reached[s] = true;
  for(int i = 0 ;  i < V ; i++){
    for(int j = 0 ; j < E ; j++){
        edge e = edges[j];
        if(distances[e.from] != LLONG_MAX && distances[e.to] > distances[e.from] + (long long)e.weight ){
            distances[e.to] = distances[e.from] + (long long)e.weight;
            reached[e.to] = true;
    	    if( i == V-1 ){
    		    return 1;
    	    }
        }
    }
  }
  
  
  return 0;
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
  vector<int> components = strongly_connected_components(adj);
  vector<bool> reached(adj.size() , false);
  components.shrink_to_fit();
  bool flag = false;
  for(auto& s : components){
    if( !reached[s] && negative_cycle( n , edges , s , reached) ){
        flag = true;
        break;
    }
  }
  std::cout << flag;
}
