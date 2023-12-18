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

string postfixToPrefix(string s){
    stack st;
    string result;
    for(int i=0; i<s.length(); i++){
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
            st.push(string(1,s[i]));
        }
        else{
            string op1 = st.topElement();
            st.pop();
            string op2 = st.topElement();
            st.pop();
            string concat = s[i] + op2 + op1;
            st.push(concat);
        }
    }
    return st.topElement();
}

int main(){
    cout<<postfixToPrefix("ABC/-AK/L-*")<<endl;
    return 0;
}