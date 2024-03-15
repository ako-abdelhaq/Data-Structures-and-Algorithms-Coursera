#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;
bool comp(int &a, int &b)
{
	int c = a;
	int d = b;

	string x = to_string(c);
	string y = to_string(d);

	return (stoi(x+y) > stoi(y+x));
}

string LargestNumber(vector<int> &nums){
	sort(nums.begin(), nums.end(), comp);
	string result;
	for(int i = 0; i < nums.size(); i++) {
		result += to_string(nums[i]);
	}
	return result;
}

int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i = 0 ; i < n ; i++){
        cin >> nums[i];
    }
    cout<<LargestNumber(nums)<<endl;
    return 0;
}