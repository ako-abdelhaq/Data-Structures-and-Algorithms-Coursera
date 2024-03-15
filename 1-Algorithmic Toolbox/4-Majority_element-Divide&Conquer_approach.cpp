#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
using namespace std;

/* This the Divide & Conquer approach for solving this problem :
	 if a sequence of length n contains a majority element , then the same element is also
	 a majority element for one of its halves. Thus, to solve this problem we first split a given sequence into
	 halves and make two recursive calls. Then we have three cases :
	  1* base case : the only element in an array of size 1 is the majority. 
	  2* after recuring on the left and right ,  if the two halves agree on the majority element, return it.
	  3* otherwise, count the occurrences of each element and return the most frequented element ( which has most occurrences ).
*/


int countInRange(vector<int>& a, int num, int lo, int hi) {
    //This is the count function which count the occurrences of a given element ( num argument ).
    int count = 0;
    for (int i = lo; i <= hi; i++) {
        if ( a[i] == num ) {
            count++;
        }
    }
    return count;
}

// This function only finds the majority element but doesn't check if it has n/2 occurences
int get_majority_element(vector<int> &a, int left, int right) {
    
    // base case ( or case #1) : the only element in an array of size 1 is the majority. 
    if (left == right) return a[left];

    //Divide : Split the array in the middle so that we have two halves ( two arrays ). 
    int mid = left + ((right-left)/2) ;


    //Conquer : Recursively solve the subproblems and combining the results.

    int R = get_majority_element(a , left , mid );
    int L = get_majority_element(a , mid + 1 , right);

    //case #2 : after recuring on the left and right ,  if the two halves agree on the majority element ( Right major == Left major), return it.
    if (L == R) {
        return R;
    } 

    //case #3 : count the occurrences of each element and return the most frequented element ( which has most occurences ).
    int leftCount = countInRange(a , L , left , right );
    int rightCount = countInRange(a , R , left , right );

    return leftCount > rightCount ? L : R;
} 

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); ++i) {
        cin >> a[i];
    }
    int major = get_majority_element(a, 0, a.size()) ;
    if( countInRange( a , major , 0 , a.size() ) > n/2 ){
        cout<<"1"<<endl;
    }
    else{
        cout<<"0"<<endl;
    }
    return 0;
}
