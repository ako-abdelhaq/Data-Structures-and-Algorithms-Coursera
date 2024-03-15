#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;
using namespace std;

vector<int> BFS(vector<vector<int>> adj , int s){
    queue<int> q;
    vector<int> d(adj.size() , adj.size()+1);
    d[s] = 0;
    q.push(s);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i = 0 ; i < adj[x].size() ; i++){
            if(d[adj[x][i]] == adj.size()+1){
                q.push(adj[x][i]);
                d[adj[x][i]] = d[x] + 1;
            }
        }
    }
    return d;
}

int distance(vector<vector<int> > &adj, int s, int t) {
  //write your code here
  vector<int> distance = BFS(adj , s);
  return distance[t] < adj.size()+1 ? distance[t] : -1;
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
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  /*vector<int> distances = BFS(adj , t);
  for(int i = 0 ; i < distances.size() ; i++){
    cout<<distances[i]<<"   "<<i+1<<endl;
  }*/
  std::cout << distance(adj, s, t);
}
