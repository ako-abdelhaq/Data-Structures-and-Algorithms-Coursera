#include <iostream>
#include <stack>
#include <string>

using namespace std;

struct Bracket {
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }
    
    void operator = (Bracket b){
        type = b.type;
        position = b.position;
    }
    
    char type;
    int position;
};

void CheckBrackets(string text){
    stack <Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); position++) {
        char next = text[position];
        if (next == '(' || next == '[' || next == '{') {
            // Process opening bracket, write your code here
            opening_brackets_stack.push(Bracket(next,position));
        }
        
        if (next == ')' || next == ']' || next == '}') {
            // Process closing bracket, write your code here
            if(opening_brackets_stack.size()==0 || !opening_brackets_stack.top().Matchc(next)){
                cout << 1 + position << endl;
                return ;
            }
            else{
                opening_brackets_stack.pop();
            }
        }
        
    }

    // Printing answer, write your code here
    
    if( opening_brackets_stack.empty() ){
        cout << "Success" << endl;
    }
    else{
        cout << 1 + opening_brackets_stack.top().position << endl;
    }
}
int main() {
    string text;
    getline(cin, text);
    CheckBrackets(text);
    return 0;
}
