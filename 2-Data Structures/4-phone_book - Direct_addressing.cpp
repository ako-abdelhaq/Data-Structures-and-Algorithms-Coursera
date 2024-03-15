#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;
using std::cin;

struct Query {
    string type, name;
    int number;
};

vector<Query> read_queries() {
    int n;
    cin >> n;
    vector<Query> queries(n);
    for (int i = 0; i < n; ++i) {
        cin >> queries[i].type;
        if (queries[i].type == "add")
            cin >> queries[i].number >> queries[i].name;
        else
            cin >> queries[i].number;
    }
    return queries;
}

void write_responses(const vector<string>& result) {
    for (size_t i = 0; i < result.size(); ++i)
        std::cout << result[i] << "\n";
}

vector<string> process_queries(const vector<Query>& queries) {
    vector<string> result;
    // Creating a Table that can cover all of the possible numbers 
    // So each index in the array represents a phone number
    vector<string> contacts(10000000 , "Null"); 
    
    // Processing the queries
    for (size_t i = 0; i < queries.size(); ++i){
        if (queries[i].type == "add") {
            // Change the name of the contact
            contacts[queries[i].number] = queries[i].name;
        } else if (queries[i].type == "del") {
            // Change this phone number's value so it doesn't map to any name
            if(contacts[queries[i].number] != "Null"){
                contacts[queries[i].number] = "Null";
            }
        } else {
            string response = "not found";
            // if the index representing this phone number maps to any name
            // then return it (return this name)
            if(contacts[queries[i].number] != "Null"){
                response = contacts[queries[i].number];
            }
            result.push_back(response);
        }
    }
    return result;
}

int main() {
    write_responses(process_queries(read_queries()));
    return 0;
    
}
