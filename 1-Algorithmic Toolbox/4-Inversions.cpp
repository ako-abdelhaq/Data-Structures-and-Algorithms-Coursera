#include <iostream>
#include <vector>

using namespace std;
using std::vector;

long long merge(vector<int>& arr, int l, int r){
    int m = (l + r) / 2;
    vector<int> v(r - l + 1);
    int k = 0;
    int i = l;
    int j = m + 1;
    long long count = 0;
    while(i <= m && j <= r) {
        if(arr[i] > arr[j]) {
            v[k] = arr[j];
            j++ ;
            count += m - i + 1;
        }
        else{
            v[k] = arr[i];
            i++;
        }
        k++;          
    }
    while(i <= m) {
        v[k] = arr[i];
        i++ ; k++;    
    }
    
    while(j <= r) {
        v[k] = arr[j];
        j++ ; k++;
    }

    k=0;

    for(int x=l ; x<=r ; x++){
        arr[x] = v[k];
        k++;
    }

    return count;
}


long long minimum_inversions(vector<int>& arr , int l ,int r){
    if(l >= r)
        return 0;
    int m = (l + r) / 2;
    long count = 0;
    count += minimum_inversions(arr, l , m); 
    count += minimum_inversions(arr, m + 1, r);
    count += merge(arr, l, r); 
    return count;
}


int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); i++) {
        cin >> a[i];
    }
    cout << minimum_inversions(a , 0 , a.size()-1) << '\n';
    return 0;
}
