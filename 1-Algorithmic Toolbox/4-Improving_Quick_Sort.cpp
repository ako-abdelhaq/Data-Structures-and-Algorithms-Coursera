#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using std::vector;
using std::swap;
using namespace std;

pair<int,int> partition3(vector<int> &a, int l, int r) {
    int x = a[l];
    int m2 = l;
    for (int i = l + 1; i <= r; i++) {
        if (a[i] < x) {
            m2++;
            swap(a[i], a[m2]);
        }
    }
    swap(a[l], a[m2]);
    for(int i = m2+1 ; i <= r ; i++){
        if(a[i] == x){
            m2++;
            swap(a[i] , a[m2]);
        }
    }
    int m1;
    for(int i = 0 ; i <= r ; i++){
        if( a[i] == x){
            m1 = i;
            break;
        }
    }
    return {m1 , m2};
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
    if (l >= r) {
        return;
    }

    int k = l + rand() % (r - l + 1);
    swap(a[l], a[k]);
    pair<int,int> p = partition3(a, l, r);
    
    randomized_quick_sort(a, l, p.first - 1);
    randomized_quick_sort(a, p.second + 1, r);
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); ++i) {
        cin >> a[i];
    }
    randomized_quick_sort(a , 0 , a.size()-1);
    for (size_t i = 0; i < a.size(); ++i) {
        cout << a[i] << ' ';
    }
    return 0;
}
