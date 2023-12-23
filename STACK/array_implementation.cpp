#include <iostream>
using namespace std;

class stack
{
    int capacity;
    int *arr;
    int top;

public:
    stack(int c)
    {
        this->capacity = c;
        arr = new int[c];
        this->top = -1;
    }

    void push(int data)
    {
        if (this->top == this->capacity - 1)
        {
            cout << "overflow" << endl;
            return;
        }
        this->top++;
        this->arr[this->top] = data;
    }

    int pop()
    {
        if (this->top == -1)
        {
            cout << "underflow" << endl;
            return INT32_MIN;
        }
        this->top--;
    }

    int gettop()
    {
        if (this->top == -1)
        {
            cout << "underflow" << endl;
            return INT32_MIN;
        }
        return this->arr[this->top];
    }

    bool isEmpty()
    {
        return this->top == -1;
    }
    bool isFull()
    {
        return this->top == this->capacity - 1;
    }
};

int main(){
    stack st(5);
    st.push(1);
    st.push(3);
    cout<<st.gettop();
}