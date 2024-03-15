#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
using namespace std;

long long max_dot_product(vector<int>& a, vector<int>& b) {
    long long result = 0;
    int n = min(a.size() , b.size());
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    for (int i = 0 ; i < n ; i++) {
        result += (long long)((long long)a[i] * (long long)b[i]);
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n) , b(n) ;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    cout << max_dot_product(a, b) << endl;
    return 0;
}
