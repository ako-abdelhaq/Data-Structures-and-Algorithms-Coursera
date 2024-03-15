#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;
using namespace std;

class HeapBuilder {
 private:
  vector<int> data_;
  vector< pair<int, int> > swaps_;

  void WriteResponse() const {
    cout << swaps_.size() << "\n";
    for (int i = 0; i < swaps_.size(); ++i) {
      cout << swaps_[i].first << " " << swaps_[i].second << "\n";
    }
  }

  void ReadData() {
    int n;
    cin >> n;
    data_.resize(n);
    for(int i = 0; i < n; ++i)
      cin >> data_[i];
  }
  
  
  int leftChild(int i){
    return 2*i + 1;
  }

  int rightChild(int i){
    return 2*i + 2;
  }
  
  void Heapify(int i){
    int minIndex = i;
    int leftChildIndex = leftChild(i);
    if(leftChildIndex < data_.size() && data_[leftChildIndex] < data_[minIndex]){
      minIndex = leftChildIndex;
    }
    int rightChildIndex = rightChild(i);
    if(rightChildIndex < data_.size() && data_[rightChildIndex] < data_[minIndex]){
      minIndex = rightChildIndex;
    }
    if(i != minIndex){
      swap(data_[i], data_[minIndex]);
      swaps_.push_back(make_pair(i, minIndex));
      Heapify(minIndex);
    }
  }

  void GenerateSwaps() {
    swaps_.clear();
    int n = data_.size();
    for(int i = (n-1)/2 ; i > -1 ; i--){
      Heapify(i);
    }
  }

 public:
  void Solve() {
    ReadData();
    GenerateSwaps();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}
