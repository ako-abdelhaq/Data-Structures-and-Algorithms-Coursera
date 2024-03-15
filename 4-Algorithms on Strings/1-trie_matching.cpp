#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int const Letters =    4;
int const NA      =   -1;

struct Node
{
	int next [Letters];

	Node ()
	{
		fill (next, next + Letters, NA);
	}

	bool isLeaf () const
	{
	    return (next[0] == NA && next[1] == NA && next[2] == NA && next[3] == NA);
	}
};

int letterToIndex (char letter)
{
	switch (letter)
	{
		case 'A': return 0; break;
		case 'C': return 1; break;
		case 'G': return 2; break;
		case 'T': return 3; break;
		default: assert (false); return -1;
	}
}

vector<Node> build_trie (const vector <string>& patterns){
    vector<Node> t;
    Node root;
    t.push_back(root);
	for (auto& pattern : patterns){
	    
		int x = 0;
		
		for (auto& c : pattern){
		    
			int index = letterToIndex(c);
			
			if (t[x].next[index] != -1){
				x = t[x].next[index];
			}
			
			else{
				t[x].next[index] = t.size();
				x = t[x].next[index];
				t.resize(x + 1);
			}
		}
	}
    return t;
}

vector <int> solve (const string& text, const vector <string>& patterns)
{
    
	vector <int> result;

	// write your code here
	
	vector<Node> trie = build_trie(patterns);
	
	for (int i = 0; i < text.size(); i++){
	    
		int index = letterToIndex( text[i] );
		int x = 0;
		if (trie[x].next[index] != -1){
		    
			bool found = true;
			for (int j = i ; !trie[x].isLeaf() ; j++){
			    
				if (j >= text.size()){
					found = false;
					break;
				}
				
				index = letterToIndex(text[j]);
				
				if (trie[x].next[index] != -1){
					x = trie[x].next[index];
				}
				else{
					found = false;
					break;
				}
			}
			if (found)
			{
				result.push_back(i);
			}
		}
	}

	return result;
}


int main (void)
{
	string text;
	cin >> text;

	int n;
	cin >> n;

	vector <string> patterns (n);
	for (int i = 0; i < n; i++)
	{
		cin >> patterns[i];
	}

	vector <int> ans;
	ans = solve (text , patterns);

	for (int i = 0; i < (int) ans.size (); i++)
	{
		cout << ans[i];
		if (i + 1 < (int) ans.size ())
		{
			cout << " ";
		}
		else
		{
			cout << endl;
		}
	}

	return 0;
}
