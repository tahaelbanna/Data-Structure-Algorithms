#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <sstream>
#include <map>
using namespace std;

// الأولوية
int precedence(char op) {
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    return 0;
}

// تنفيذ عملية حسابية
int applyOp(int a, int b, char op) {
    if(op == '+') return a + b;
    if(op == '-') return a - b;
    if(op == '*') return a * b;
    if(op == '/') return a / b;
    return 0;
}

// تحويل infix إلى postfix
string infixToPostfix(const string& infix) {
    stack<char> ops;
    string postfix;
    for(int i = 0; i < infix.size(); ++i) {
        char ch = infix[i];

        if(ch == ' ') continue;

        // رقم
        if(isdigit(ch)) {
            while(i < infix.size() && isdigit(infix[i])) {
                postfix += infix[i];
                i++;
            }
            postfix += ' ';
            --i;
        }
        else if(ch == '(') {
            ops.push(ch);
        }
        else if(ch == ')') {
            while(!ops.empty() && ops.top() != '(') {
                postfix += ops.top(); postfix += ' ';
                ops.pop();
            }
            ops.pop(); // نشيل القوس المفتوح
        }
        else { // عامل حسابي
            while(!ops.empty() && precedence(ops.top()) >= precedence(ch)) {
                postfix += ops.top(); postfix += ' ';
                ops.pop();
            }
            ops.push(ch);
        }
    }
    // نضيف الباقي
    while(!ops.empty()) {
        postfix += ops.top(); postfix += ' ';
        ops.pop();
    }

    return postfix;
}

// حساب postfix
int evaluatePostfix(const string& postfix) {
    stack<int> st;
    istringstream iss(postfix);
    string token;
    while(iss >> token) {
        if(isdigit(token[0])) {
            st.push(stoi(token));
        } else if(token.size() == 1 && string("+-*/").find(token[0]) != string::npos) {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            st.push(applyOp(a, b, token[0]));
        }
    }
    return st.top();
}

int main() {
    string exp;
    cout << "Enter infix expression (e.g. 3 + 4 * (2 - 1)):\n";
    getline(cin, exp);

    string postfix = infixToPostfix(exp);
    cout << "Postfix: " << postfix << "\n";

    int result = evaluatePostfix(postfix);
    cout << "Result: " << result << "\n";
}
