#include <algorithm>
#include <iostream>
#include <map>
#include <iomanip>
#include <vector>
#include <cmath>
#include <climits>
#include <cfloat>

using std::vector;
using namespace std;

struct point{
    int x;
    int y;
    point(int x_ , int y_){
        x = x_;
        y = y_;
    }
    point(){}
    void operator = (point p){
        this->x = p.x;
        this->y = p.y;
    }
    bool operator == (point p){
        return this->x == p.x && this->y == p.y ;
    }
};

struct edge{
    point from;
    point to;
    double weight;
    edge(){}
    edge(point f , point t , double w ){
        from.x = f.x;
        from.y = f.y;
        to.x = t.x;
        to.y = t.y;
        weight = w;
    }
    
    void operator = (edge e){
        from = e.from;
        to = e.to;
        weight = e.weight;
    }
    
    bool operator < (const edge& e ) {
        return (this->weight < e.weight);
    }
    
};


struct DisjointSetsElement {
	int size, parent, rank;
	
	DisjointSetsElement(int size = 0, int parent = -1, int rank = 0):
	    size(size), parent(parent), rank(rank) {}
};

struct DisjointSets {
	int size;
	vector <DisjointSetsElement> sets;
	int dis;

	DisjointSets(int size): size(size) , sets(size) , dis(size) {
		for (int i = 0; i < size; i++){
			sets[i].parent = i;
		}
	}
    // find parent and compress path
	int getParent(int table) {
	    
		if(table == sets[table].parent){
		    
		    // root is reached
		    return table;
		}
		else{
		    
		    // reattach each node on the path to the root directly to the root
		    sets[table].parent = getParent(sets[table].parent);
		}
		
		// return the absolute root of the corresponding tree
		return sets[table].parent;
	}

	void merge(int destination, int source) {
		int realDestination = getParent(destination);
		int realSource = getParent(source);
		if (realDestination != realSource) {
			// merge two components
            if(sets[realDestination].rank > sets[realSource].rank){
                
                // union by rank heuristic
                sets[realSource].parent = realDestination;
                
                // update the new root's size
                sets[realDestination].size += sets[realSource].size;
                
                // clear the old root's data
				sets[realSource].size = 0;
				
            }
            else{
                
                // union by rank heuristic
                sets[realDestination].parent = realSource;
                
                // update the new root's size
				sets[realSource].size += sets[realDestination].size;
				
                // clear the old root's data
				sets[realDestination].size = 0;
				
				// update the rank of the new root
                if(sets[realDestination].rank == sets[realSource].rank){
                    sets[realSource].rank++;
                }
            }
            if(dis > 0){
                dis--;
            }
		}		
	}
};

double minimum_distance(vector<point> points , vector<edge> edges , int k){
  //write your code here
  int n = points.size();
  //mapping between points and indices in the disjoint set data structure
  map<pair<int,int> , int> m;
  pair<int,int> p;
  for(int i = 0 ; i < n ; i++){
    p.first = points[i].x;
    p.second = points[i].y;
    m[p] = i;
  }
  //creating the disjoint sets
  DisjointSets set( n );
  pair<int,int> p1 , p2;
  //processing the edges by order of edge's weight
  int i = 0;
  while ( i < edges.size() && set.dis > k){
    edge e = edges[i];
    p1.first = e.from.x;
    p1.second = e.from.y;
    p2.first = e.to.x;
    p2.second = e.to.y;
    int u = m[p1] , v = m[p2] ;
    if( set.getParent( u ) != set.getParent( v ) ){
        set.merge( u , v );
    }
    i++;
  }
  i = 0;
  double min_d = DBL_MAX;
  for(int i = 0 ; i < edges.size() ; i++){
    edge e = edges[i];
    p1.first = e.from.x;
    p1.second = e.from.y;
    p2.first = e.to.x;
    p2.second = e.to.y;
    int u = m[p1] , v = m[p2] ;
    if( set.getParent( u ) != set.getParent( v ) ){
        min_d = min(min_d , e.weight);
    }
  }
  
  return min_d;
} 

int main() {
  int n;
  std::cin >> n;
  vector<point> points(n);
  for (int i = 0; i < n; i++) {
    std::cin >> points[i].x >> points[i].y;
  }
  int k;
  std::cin >> k;
  vector<edge> edges;
  double d = 0;
  for(int i = 0 ; i < n-1 ; i++ ){
    point p1 = points[i];
    for(int j = i+1 ; j < n ; j++){
        point p2 = points[j];
        d = sqrt(((p1.x-p2.x)*(p1.x-p2.x))+((p1.y-p2.y)*(p1.y-p2.y)));
        edge e(p1 , p2 , d);
        edges.push_back(e);
    }
  }
  
  edges.shrink_to_fit();
  
  std::sort( edges.begin() , edges.end() );
  
  
  
  cout << std::setprecision(10) << minimum_distance(points, edges,k ) ;
  
  return 0;
}