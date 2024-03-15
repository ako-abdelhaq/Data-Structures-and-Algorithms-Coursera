#include <iostream>
#include <vector>

using std::vector;
using std::pair;
using namespace std;

bool isCyclic(vector<vector<int>> adj, int v, vector<bool>& visited, vector<bool>& recStack){
	if(!visited[v]){
		visited[v] = true;
		recStack[v] = true;
		
		for(int i = 0 ; i < adj[v].size(); ++i){
			if ( (recStack[adj[v][i]]) || ( !visited[adj[v][i]] &&
			      isCyclic(adj, adj[v][i], visited, recStack)) ){
				return true;
			}
		}
		
	}
	recStack[v] = false;
	return false;
}


int acyclic(vector<vector<int>> adj) {
  //write your code here
    vector<bool> visited(adj.size() , false) , recStack(adj.size() , false);

	for(int i = 1 ; i < adj.size(); i++)
		if (isCyclicUtil(adj , i, visited, recStack))
			return true;

	return false;
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
  
  std::cout << acyclic(adj);
  return 0;
}