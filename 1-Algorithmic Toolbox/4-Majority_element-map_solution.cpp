#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

using std::vector;
using namespace std;

int get_majority_element(vector<int> &a, int left, int right) {
    //write your code here
    map<int,int> frequencies;
    for(int i = 0 ; i < a.size() ; i++){
        if (frequencies.find(a[i]) == frequencies.end()) { 
            frequencies[a[i]] = 1; 
        } 
        
        else { 
            frequencies[a[i]]++;
        } 
    }
    for(auto frequency : frequencies){
        if(frequency.second > right/2){
            return frequency.first;
        }
    }
    return -1;
}

int main() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
    }
    std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
    return 0;
}
