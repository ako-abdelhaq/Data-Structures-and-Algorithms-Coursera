#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int start_bin(vector <int> arr , int key) {
    int n = arr.size();
    int l = 0 , r = n;
    int mid; 
    while(l < r) {
        int mid = (l + r) / 2; 
        if(arr[mid] > key) {
            while(mid > 0 && arr[mid - 1] > key)
                mid--;
            return mid;
        }
        else {
            l = mid+1;
        }
    }
    return -1;
}

int end_bin(vector <int> arr , int key) {
    int n = arr.size();
    int l = 0 , r = n;
    int mid; 
    while(l < r) {
        int mid = (l + r) / 2; 
        if(arr[mid] < key) {
            while(mid + 1 < n && arr[mid + 1] < key)
                mid++;
            return mid;
        }
        else {
            r = mid;
        }
    }
    return -1;
}

int main() { 
    int s, p;
    cin >> s >> p;
    vector <int> start(s);
    vector <int> end(s);
    for(int i = 0 ; i < s; i++) 
        cin >> start[i] >> end[i];
    
    sort(start.begin(),start.end());
    sort(end.begin(), end.end());

    for(int i = 0; i < p; i++) {
        int p;
        cin >> p;
        int l = start_bin(start,p);
        int count1;
        if(l == -1) {
            count1 = 0;
        }
        else {
            count1 = s - l;
        }
        
        int r = end_bin(end,p);
        int count2;
        if( r == -1) {
            count2 = 0;
        }
        else {
            count2 = r + 1;
        }
        cout << s - (count1 + count2) << " ";
    }
}