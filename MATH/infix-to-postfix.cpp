#include<iostream>
#include<stack>
#include <string>
using namespace std;

int precedence(char op){
     if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0; // For brackets and operands
}

string infixTopostfix(string infix){
        stack<char>s;
        string postfix="";
        for(int i=0;i<infix.size();i++){
            char ch=infix[i];

            if(isalnum(ch)){
                postfix+=ch;
            }
            else if(ch=='('){
                s.push(ch);
            }
            else if(ch == ')'){
                while(!s.empty() && s.top()!='('){
                    postfix+=s.top();
                    s.pop();
                }
                if (!s.empty()) s.pop();
            }
            else{
                while(!s.empty() && precedence(s.top()) >= precedence(ch)){
                    postfix+=s.top();
                    s.pop();
                }
                s.push(ch);
            }
        }

        while (!s.empty()){
            postfix += s.top();
            s.pop();
        }
       
        return postfix;
}

int main() {
    string infix = "(a+b/c*(d+e)-f)";
    
    cout << "Infix:   " << infix << endl;
    cout << "Postfix: " << infixTopostfix(infix) << endl;
    
    return 0;
}