#include <iostream>
#include <string>
#include <vector>

using namespace std;
using std::string;
typedef unsigned long long ull;

struct Data {
    string pattern, text;
};

Data read_input() {
    Data data;
    std::cin >> data.pattern >> data.text;
    return data;
}

void print_occurrences(const std::vector<int>& output) {
    for (size_t i = 0; i < output.size(); ++i)
        std::cout << output[i] << " ";
    std::cout << "\n";
}


// Rabin-Karp's Algorithm ( Hashing Algorithm Edited by Ako )
// Source : https://cp-algorithms.com/string/rabin-karp.html
vector<int> rabin_karp(string const& s, string const& t) {
    const int p = 2; 
    const int m = 1e9 + 9;
    int S = s.size(), T = t.size();

    vector<long long> p_pow(max(S, T)); 
    p_pow[0] = 1; 
    for (int i = 1; i < (int)p_pow.size(); i++) 
        p_pow[i] = ( (p_pow[i-1] * p) + m ) % m;

    vector<long long> h(T + 1, 0); 
    for (int i = 0; i < T; i++)
        h[i+1] = ( ( h[i] + (t[i] - 'a' + 1) * p_pow[i] ) % m + m ) % m; 
    long long h_s = 0; 
    for (int i = 0; i < S; i++) 
        h_s = ( ( h_s + (s[i] - 'a' + 1) * p_pow[i] ) % m + m ) % m; 

    vector<int> occurences;
    for (int i = 0; i + S - 1 < T; i++) { 
        long long cur_h = ( (h[i+S] - h[i] + m) % m + m ) % m; 
        if (cur_h == ( (h_s * p_pow[i] % m) + m ) % m )
            occurences.push_back(i);
    }
    return occurences;
}
std::vector<int> get_occurrences(const Data& input) {
    const string& s = input.pattern, t = input.text;
    std::vector<int> ans = rabin_karp( s , t );
    return ans;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    print_occurrences(get_occurrences(read_input()));
    return 0;
}
