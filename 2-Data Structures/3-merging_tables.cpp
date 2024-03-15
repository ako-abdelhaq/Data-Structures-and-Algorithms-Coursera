#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::vector;
using namespace std;

struct DisjointSetsElement {
	int size, parent, rank;
	
	DisjointSetsElement(int size = 0, int parent = -1, int rank = 0):
	    size(size), parent(parent), rank(rank) {}
};

struct DisjointSets {
	int size;
	int max_table_size;
	vector <DisjointSetsElement> sets;

	DisjointSets(int size): size(size), max_table_size(0), sets(size) {
		for (int i = 0; i < size; i++){
			sets[i].parent = i;
		}
	}

	int getParent(int table) {
	    
		// find parent and compress path
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
				
				// update max_table_size
				max_table_size = max(max_table_size,sets[realDestination].size);
            }
            else{
                
                // union by rank heuristic
                sets[realDestination].parent = realSource;
                
                // update the new root's size
				sets[realSource].size += sets[realDestination].size;
				
                // clear the old root's data
				sets[realDestination].size = 0;
				
				//update max_table_size
				max_table_size = max(max_table_size,sets[realSource].size);
				
				// update the rank of the new root
                if(sets[realDestination].rank == sets[realSource].rank){
                    sets[realSource].rank++;
                }
            }
		}		
	}
};

int main() {
	int n, m;
	cin >> n >> m;

	DisjointSets tables(n);
	for (auto &table : tables.sets) {
		cin >> table.size;
		tables.max_table_size = max(tables.max_table_size, table.size);
	}

	for (int i = 0; i < m; i++) {
		int destination, source;
		cin >> destination >> source;
        --destination;
        --source;
		
		tables.merge(destination, source);
        cout << tables.max_table_size << endl;
	}

	return 0;
}
