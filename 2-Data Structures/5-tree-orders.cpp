#include <iostream>
#include <vector>
#include <algorithm>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

using std::vector;
using std::ios_base;
using std::cin;
using std::cout;

class TreeOrders {
  int n;
  vector <int> key;
  vector <int> left;
  vector <int> right;
  vector <int> in_order_ , pre_order_ , post_order_;
  int index ;
  void private_in_order( int r ){
    if(r == -1){
      return ;
    }
    private_in_order( left[r] );
    in_order_[index++] = key[r];
    private_in_order( right[r] );
  } 
  void private_pre_order( int r ){
    if(r == -1){
      return ;
    }
    pre_order_[index++] = key[r];
    private_pre_order( left[r] );
    private_pre_order( right[r] );
  }   
  void private_post_order( int r ){
    if(r == -1){
      return ;
    }
    private_post_order( left[r] );
    private_post_order( right[r] );
    post_order_[index++] = key[r];
  }  
public:
  void read() {
    cin >> n;
    key.resize(n);
    left.resize(n);
    right.resize(n);
    for (int i = 0; i < n; i++) {
      cin >> key[i] >> left[i] >> right[i];
    }
  }


  vector <int> in_order() {
    index = 0;
    // Finish the implementation
    // You may need to add a new recursive method to do that
    in_order_.resize(n);
    private_in_order( 0 );
    return in_order_;
  }

  vector <int> pre_order() {
    index = 0;
    // Finish the implementation
    // You may need to add a new recursive method to do that
    pre_order_.resize(n);
    private_pre_order( 0 );
    return pre_order_;
  }

  vector <int> post_order() {
    index = 0;
    // Finish the implementation
    // You may need to add a new recursive method to do that
    post_order_.resize(n);
    private_post_order( 0 );
    return post_order_;
  }
};

void print(vector <int> a) {
  for (size_t i = 0; i < a.size(); i++) {
    if (i > 0) {
      cout << ' ';
    }
    cout << a[i];
  }
  cout << '\n';
}

int main_with_large_stack_space() {
  ios_base::sync_with_stdio(0);
  TreeOrders t;
  t.read();
  print(t.in_order());
  print(t.pre_order());
  print(t.post_order());
  return 0;
}

int main (int argc, char **argv)
{
#if defined(__unix__) || defined(__APPLE__)
  // Allow larger stack space
  const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0)
  {
      if (rl.rlim_cur < kStackSize)
      {
          rl.rlim_cur = kStackSize;
          result = setrlimit(RLIMIT_STACK, &rl);
          if (result != 0)
          {
              std::cerr << "setrlimit returned result = " << result << std::endl;
          }
      }
  }
#endif

  return main_with_large_stack_space();
}

