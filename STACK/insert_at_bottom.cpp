#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int>&s,int x){
    //base case
    if(s.empty()){
        s.push(x);
        return;
    }
    int num=s.top();
    s.pop();
    solve(s,x);
    s.push(num);
}


void display(stack<int>input){
    while(!input.empty()){
        cout<<input.top()<<" ";
        input.pop();
    }
    cout<<endl;
}

int main(){
    stack<int>st;
    st.push(9);
    st.push(4);
    st.push(6);
    st.push(23);
    st.push(45);
    st.push(1);
    display(st);
    solve(st,100);
    display(st);
}