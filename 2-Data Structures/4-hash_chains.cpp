#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;
using std::string;
using std::vector;
using std::cin;

struct Query {
    string type, s;
    size_t ind;
};


class QueryProcessor {
    int bucket_count;
    // store all strings in one vector
    vector< list<string> > elems;
    size_t hash_func(const string& s) const {
        static const size_t multiplier = 263;
        static const size_t prime = 1000000007;
        unsigned long long hash = 0;
        for (int i = static_cast<int> (s.size()) - 1; i > -1; --i)
            hash = (hash * multiplier + s[i]) % prime;
        return hash % bucket_count;
    }

public:
    explicit QueryProcessor(int bucket_count): bucket_count(bucket_count) , elems(bucket_count) {
    }

    Query readQuery() const {
        Query query;
        cin >> query.type;
        if (query.type != "check")
            cin >> query.s;
        else
            cin >> query.ind;
        return query;
    }

    int search_string(string s){
        int index = hash_func(s);
        for (auto it = elems[index].begin() ; it != elems[index].end(); it++){
            if(*it == s){
                return index;
            }
        }
        return -1;
    }

    void processQuery(const Query& query) {
        if (query.type == "check") {
            // use reverse order, because we append strings to the end
            if( query.ind < elems.size() && !elems[query.ind].empty() ){
                auto it_s = elems[query.ind].begin();
                auto it_f = elems[query.ind].end();
                while(it_s != it_f){
                    cout<<*it_s<<" ";
                    it_s++;
                }
            }
            cout<<endl;
        } else {
            if (query.type == "find"){
                int was_found = search_string(query.s);
                if( was_found != -1){
                    std::cout<< "yes" <<std::endl;
                }
                else{
                    std::cout<< "no" <<std::endl;
                }
            }
            else if (query.type == "add") {
                int index = hash_func(query.s);
                auto it_s = elems[index].begin();
                auto it_f = elems[index].end();
                while(it_s != it_f){
                    if(*it_s == query.s){
                        break;
                    }
                    it_s++;
                }
                if(it_s == it_f){
                    elems[index].emplace_front(query.s);
                }
            }
            else if (query.type == "del") {
                int index = search_string(query.s);
                if ( index != -1 ){
                    for (auto it = elems[index].begin() ; it != elems[index].end(); it++){
                        if( *it == query.s ){
                            elems[index].erase(it);
                            break;
                        }
                    }
                }
            }
        }
    }

    void processQueries() {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
            processQuery(readQuery());
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    int bucket_count;
    cin >> bucket_count;
    QueryProcessor proc(bucket_count);
    proc.processQueries();
    return 0;
}
