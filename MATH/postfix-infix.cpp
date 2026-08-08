#include<iostream>
#include<stack>
#include<string>

using namespace std;

int precedence(char ch){
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

string postfixToinfix(string postfix){
    stack<string>s;
    string infix="";

    for(int i=0;i<postfix.size();i++){
        char ch = postfix[i];

        if(isalnum(ch)){
            string operand(1,ch);
            s.push(operand);
        }

        else if(precedence(ch)){
            string operand2 = s.top(); s.pop();
            string operand1 = s.top(); s.pop();

            string combined = "(" + operand1 + ch + operand2 + ")";
            s.push(combined);
        }
    }

    return s.top();
}

int main() {
    string postfix = "abc/de+*+f-";
    
    cout << "Postfix: " << postfix << endl;
    cout << "Infix:   " << postfixToinfix(postfix) << endl;
    
    return 0;
}