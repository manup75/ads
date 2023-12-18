#include<iostream>
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
    if(c == '^'){
        return 3;
    }
    else if(c == '*' || c == '/'){
        return 2;
    }
    else if(c == '+' || c == '-'){
        return 1;
    }
    else{
        return -1;
    }
}

string infixToPostfix(string s){
    stack st;
    string result;
    for(int i=0; i<s.length(); i++){
        //if the char is an operand
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
            result += s[i];
        }

        //if the char is an opening parentheses
        else if(s[i]==')'){
            st.push(s[i]);
        }

        //if the char is a closing parantheses
        else if(s[i]==')'){
            while(!st.isEmpty() && st.topElement()!='('){
                result += st.topElement();
                st.pop();
            }
            if(!st.isEmpty()){
                st.pop();
            }
        }

        //if the char is a operator
        else{
            while(!st.isEmpty() && precedence(st.topElement())>=precedence(s[i])){
                result += st.topElement();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while(!st.isEmpty()){
        result += st.topElement();
        st.pop();
    }
    return result;
}

int main(){
    cout<<infixToPostfix("a+b*c+d")<<endl;
    return 0;
}