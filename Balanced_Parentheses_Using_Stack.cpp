#include<iostream>
using namespace std;
using ll = long long;
const ll MAX_SIZE = 1000; // Set a reasonable maximum size
template<class t>

class stack{
    private:
        t stack_implemented[MAX_SIZE];
        ll top_;
    public:
        stack(){
            top_ = -1;
        }
        bool empty(){
            return top_<0;
        }
        void push(t Element){
            if(top_ >= MAX_SIZE-1)
                cout << "Stack Full On Push\n";
            else{
                top_++;
                stack_implemented[top_] = Element;
            }
        }
        void pop(){
            if(empty())
                cout << "Stack Empty On Pop\n";
            else
                --top_;
        }
        t top(){
            if(empty())
                cout << "Stack Empty On top\n";
            else
                return stack_implemented[top_];
            
        }
};
bool ispair(char start , char end){
    if(start=='('&&end==')')return true;
    else if(start=='['&&end==']')return true;
    else if(start=='{'&&end=='}')return true;
    return false;
}

bool check(string &exp){
    stack<char>s;
    for(ll i=0;i<exp.size();++i){
        if(exp[i]=='('||exp[i]=='{'||exp[i]=='[')
            s.push(exp[i]);
        else if(exp[i]=='}'||exp[i]==']'||exp[i]==')'){
            if(s.empty()|| !ispair(s.top(),exp[i]))
                return false;
            else
                s.pop();
        }
    }
    return s.empty();
}

int main(){
    string exp;
    cout << "Enter String\n";
    cin >> exp;
    if(check(exp))
        cout << "Good\n";
    else 
        cout << "Bad\n";
}