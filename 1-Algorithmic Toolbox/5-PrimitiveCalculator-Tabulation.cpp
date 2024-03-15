#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> genSeq(int n) {
    vector<int> res(n+1);
    res[0] = 0;
    res[1] = 0;
    for (int i = 2; i <= n; i++) {
        if (i % 3 == 0) {
            res[i] = min(res[i / 3], res[i - 1]) + 1;
        } else if (i % 2 == 0) {
            res[i] = min(res[i / 2], res[i - 1]) + 1;
        } else {
            res[i] = res[i - 1] + 1;
        }
    }
    return res;
}

vector<int> getSequence(vector<int> seq){
    vector<int> ans ;
    int i  = seq.size() - 1;
    while (i > 0) {
        ans.push_back(i);
        if (i % 3 == 0) {
            if (seq[i / 3] == seq[i] - 1) {
                i /= 3;
            } else {
                i -= 1;
            }
        } else if (i % 2 == 0) {
            if (seq[i / 2] == seq[i] - 1) {
                i /= 2;
            } else {
                i -= 1;
            }
        } else {
            i -= 1;
        }
    }
    ans.shrink_to_fit();
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int> v = getSequence(genSeq(n));
    int s = v.size();
    cout<<s-1<<endl;
    for(int i = s-1 ; i > -1 ; i-- ){
        cout<<v[i]<<" ";
    }    
    return 0;
}