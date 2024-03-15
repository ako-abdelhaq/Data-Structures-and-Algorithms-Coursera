#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>

using std::vector;
using std::pair;
using std::stack;



void dfs(vector<vector<int> > &adj, vector<int> &used, int x){
  used[x] = 1;
  for (int i = 0; i < adj[x].size(); i++) {
	if(!used[adj[x][i]]){
	  dfs(adj, used, adj[x][i]);
	}
  }
}

void dfs_sort(vector<vector<int> > &adj, vector<int> &used, stack<int> &order, int x) {
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
  for (int i = 1; i < adj.size(); i++) {
	if (!used[i]) {
	  dfs_sort(adj, used, order, i);
	}
  }
  //std::reverse(order.begin(),order.end());
  return order;
}

vector<vector<int>> get_reverse_graph(vector<vector<int>> &adj){
	vector<vector<int>> r(adj.size(), vector<int>());
    for(int i = 1; i < adj.size(); i++){
	  for(int j = 0; j < adj[i].size(); j++){
		r[adj[i][j]].push_back(i);
	  }
	}
	return r;
}

int number_of_strongly_connected_components(vector<vector<int> > adj) {
  int result = 0;
  //write your code here
  stack<int> order = toposort(adj);
  vector<vector<int> > reversed = get_reverse_graph(adj);
  vector<int> used(adj.size() , 0) ;
  while (! order.empty()) {
    int x = order.top();
    order.pop();
    if (!used[x]) {
	  stack<int> SCC;
	  dfs_sort(reversed, used, SCC , x);
	  result++;
	}
  }
  return result;
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
  
  std::cout << number_of_strongly_connected_components(adj);
}
