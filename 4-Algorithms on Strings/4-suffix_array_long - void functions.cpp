#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <utility>

using std::cin;
using std::cout;
using std::endl;
using std::make_pair;
using std::pair;
using std::string;
using std::vector;

#define alphabet 5

// Build suffix array of the string text and
// return a vector result of the same length as the text
// such that the value result[i] is the index (0-based)
// in text where the i-th lexicographically smallest
// suffix of text starts.

int char_to_int(char c){
    switch (c) {
        case '$' : return 0; break;
        case 'A' : return 1; break;
        case 'C' : return 2; break;
        case 'G' : return 3; break;
        case 'T' : return 4; break;
    }
}

void sort_characters(string text , vector<int>& order){
    order.resize(text.size());
    vector<int> count(alphabet , 0);
    for(int i = 0 ; i < text.size() ; i++){
        int cur = char_to_int(text[i]);
        count[cur]++;
    }
    for(int i = 1 ; i < alphabet ; i++){
        count[i] += count[i-1];
    }
    for(int i = text.size()-1 ; i > -1 ; i-- ){
        int cur = char_to_int(text[i]);
        count[cur]--;
        order[count[cur]] = i;
    }
}

void compute_classes(string text ,vector<int> order ,vector<int>& classes){
    classes.resize(text.size());
    classes[order[0]] = 0;
    for(int i = 1 ; i < text.size() ; i++){
        if(text[order[i]] != text[order[i-1]]){
            classes[order[i]] = classes[order[i-1]] + 1;
        }
        else{
            classes[order[i]] = classes[order[i-1]];
        }
    }
}

void sortDoubled(string text , int l , vector<int>& order , vector<int> classes){
    vector<int> count(text.size() , 0) , newOrder(text.size());
    for(int i = 0 ; i < text.size() ; i++){
        count[classes[i]]++;
    }
    for(int i = 1 ; i < count.size() ; i++){
        count[i] += count[i-1];
    }
    for(int i = text.size()-1 ; i > -1 ; i--){
        int start = (order[i] - l + (int)text.size()) % ((int)text.size());
        int class_ = classes[start];
        count[class_]--;
        newOrder[count[class_]] = start;
    }
    order = newOrder;
}

void updateClasses(vector<int> order , vector<int>& classes , int l){
    int n = order.size();
    vector<int> new_classes(n);
    new_classes[order[0]] = 0;
    for(int i = 1 ; i < n ; i++){
        int cur = order[i];
        int prev = order[i-1];
        int mid = cur + l;
        int mid_prev = (prev + l)%(n);
        if( classes[cur] != classes[prev] || 
            classes[mid] != classes[mid_prev] ){
            new_classes[cur] = new_classes[prev] + 1;
        }
        else{
            new_classes[cur] = new_classes[prev];
        }
    }
    classes = new_classes;
}

vector<int> BuildSuffixArray(const string& text) {
  vector<int> result;
  // Implement this function yourself
  int n = text.size();
  vector<int> order , classes;
  sort_characters(text , order);
  compute_classes(text , order , classes);
  
  for(int l = 1 ; l < n ; l*=2 ){
    sortDoubled(text , l , order , classes);
    updateClasses(order , classes , l);
  }
  result = order;
  return result;
}

int main() {
  string text;
  cin >> text;
  vector<int> suffix_array = BuildSuffixArray(text);
  for (int i = 0; i < suffix_array.size(); ++i) {
    cout << suffix_array[i] << ' ';
  }
  cout << endl;
  return 0;
}
