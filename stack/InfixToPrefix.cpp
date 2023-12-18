#include<iostream>
#include<algorithm>
using namespace std;

#define n 100

class stack{
    char* arr;
    int top;
    public:
    stack(){
        arr = new char[n];
        top = -1;
    }

    void push(char x){
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

    char topElement(){
        if(top==-1){
            cout<<"Stack is empty";
        }
        return arr[top];
    }

    bool isEmpty(){
        return top==-1;
    }
};

int precedence(char c){
    if(c=='^'){
        return 3;
    }
    else if(c=='*' || c=='/'){
        return 2;
    }
    else if(c=='+' || c=='-'){
        return 1;
    }
    else{
        return -1;
    }
}

string infixToPostfix(string s){
    stack st;
    string postfix;
    for(int i=0; i<s.length(); i++){
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
            postfix += s[i];
        }
        else if(s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            while(!st.isEmpty() && st.topElement()!='('){
                postfix += st.topElement();
                st.pop();
            }
            if(!st.isEmpty()){
                st.pop();
            }
        }
        else{
            while(!st.isEmpty() && precedence(st.topElement())>precedence(s[i])){
                postfix += st.topElement();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.isEmpty()){
        postfix += st.topElement();
        st.pop();
    }
    return postfix;
}

string infixToPrefix(string infix){
    reverse(infix.begin(), infix.end());
    for(int i=0; i<infix.length(); i++){
        if(infix[i]=='('){
            infix[i]=')';
        }
        else if(infix[i]==')'){
            infix[i]='(';
        }
    }
    string postfix = infixToPostfix(infix);
    reverse(postfix.begin(), postfix.end());
    return postfix;
}

int main(){
    // string str = "a*b+c/d";
    string str = "(A-B/C)*(A/K-L)";
    cout<<infixToPrefix(str)<<endl;
    return 0;
}