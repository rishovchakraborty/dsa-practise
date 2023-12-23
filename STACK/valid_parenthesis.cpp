#include<iostream>
#include<stack>
using namespace std;

bool isValidParentheses(string &s){
    stack<char>st;

    for(char ch :s){
        if(ch=='(' || ch=='{' || ch=='['){
            st.push(ch);
        }else{
            if(st.empty()){
                return false;
            }
            char top=st.top();
            st.pop();

            if((ch==')'&&top!='(') ||
                (ch==']'&&top!='[') ||
                (ch=='}'&&top!='{')){
                    return false;
                }
        }
    }
    return st.empty();
}

int main() {
    string input;
    cout << "Enter a string with parentheses: ";
    cin >> input;

    if (isValidParentheses(input)) {
        cout << "The parentheses are valid and balanced." << endl;
    } else {
        cout << "The parentheses are not valid and balanced." << endl;
    }

    return 0;
}