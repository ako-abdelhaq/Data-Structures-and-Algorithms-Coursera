#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;
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
    unordered_map<int,string> contacts; // Using a Hash Table to store Contacts
    for (size_t i = 0; i < queries.size(); ++i)
        if (queries[i].type == "add") {
            // Making a map from the number to the name of the contact
            contacts[queries[i].number] = queries[i].name; 
        } else if (queries[i].type == "del") {
            // Check if this contact exists
            auto found = contacts.find(queries[i].number);
            if(found != contacts.end()){
                // Delete the contact from the Hash table
                contacts.erase(found);
            }
        } else {
            string response = "not found";
            // Check if this contact exists
            auto found = contacts.find(queries[i].number);
            if(found != contacts.end()){
                // if this contact exists then return his name
                response = contacts[queries[i].number];
            }
            result.push_back(response);
        }
    return result;
}

int main() {
    write_responses(process_queries(read_queries()));
    return 0;
}
