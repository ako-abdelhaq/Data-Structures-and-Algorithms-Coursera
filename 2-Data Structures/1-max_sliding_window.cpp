#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using std::cin;
using std::cout;
using std::vector;
using std::max;
// MaxQueue class from geeksforgeeks
class MaxQueue {
public:
    MaxQueue() {}
    bool empty() {return elements.empty();}
    void push(int val) {
        elements.push(val);
        while(!maxElements.empty() && val > maxElements.back()) maxElements.pop_back();
        maxElements.push_back(val);
    }
    int pop() {
        int val = elements.front();
        elements.pop();
        if(val == maxElements.front()) maxElements.pop_front();
        return val;
    }
    int peekMax() {
        return maxElements.front();
    }
    int size(){
        return elements.size();
    }
private:
    queue<int> elements;
    deque<int> maxElements;
};

struct Max_Queue{
    
    Max_Queue(int w){
        size = w;
    }
    
    void push_m(int n){
        
        if( q.size() == size ){
            cout<<q.peekMax()<<" ";
            q.pop();
        }
        
        if( q.size() < size ){
            q.push(n);
        }
        
    }
    
    int last_max(){
        return q.peekMax();
    }

    MaxQueue q;
    int size ;
};
void max_sliding_window(vector<int> const & A, int w) {
    Max_Queue mq(w);
    for(int a : A){
        mq.push_m(a);
    }
    cout<<mq.last_max()<<endl;
    return;
}


int main() {
    int n = 0;
    cin >> n;

    vector<int> A(n);
    for (size_t i = 0; i < n; ++i)
        cin >> A.at(i);

    int w = 0;
    cin >> w;

    max_sliding_window(A, w);

    return 0;
}
