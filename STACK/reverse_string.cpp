#include<iostream>
#include<stack>
using namespace std;

int main(){
    string str = "rishov";
    stack<char>s;

    for(int i=0;i<str.length();i++){
        char ch=str[i];
        s.push(ch);
    }

    string res="";

    while (!s.empty())
    {
        char ch=s.top();
        res.push_back(ch);
        s.pop();
    }

    cout<<"your desird reversed string is "<<res<<endl;
    

}