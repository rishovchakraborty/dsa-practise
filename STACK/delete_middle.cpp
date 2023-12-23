#include<iostream>
#include<stack>
using namespace std;
void solve( stack<int>&input,int size,int count){
    //base case
    if(count==(size/2)){
        input.pop();
        return;
    }

    int num=input.top();
    input.pop();

    //reccursive call
    solve(input,size,count+1);
    input.push(num);
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
    // cout<<st.top();
    solve(st,st.size(),0);
    display(st);

}