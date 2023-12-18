#include<iostream>
using namespace std;

#define n 100

class stack{
    string* arr;
    int top;
    public:
    stack(){
        arr = new string[n];
        top = -1;
    }

    void push(string x){
        if(top==n-1){
            cout<<"Stack overflow";
        }
        top++;
        arr[top] = x;
    }

    void pop(){
        if(top==-1){
            cout<<"No element to pop";
        }
        top--;
    }

    string topElement(){
        if(top==-1){
            cout<<"Stack is empty";
        }
        return arr[top];
    }

    bool isEmpty(){
        return top==-1;
    }
};

string prefixToPostfix(string s){
    stack st;
    string result;
    for(int i=(s.length())-1; i>=0; i--){
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
            st.push(string(1,s[i]));
        }
        else{
            string op1 = st.topElement();
            st.pop();
            string op2 = st.topElement();
            st.pop();
            string concat = op1 + op2 + s[i];
            st.push(concat);
        }
    }
    return st.topElement();
}

int main(){
    cout<<prefixToPostfix("*-A/BC-/AKL")<<endl;
    return 0;
}