#include<iostream>
using namespace std;
using ll = long long;
const ll MAX_SIZE = 1000; // Set a reasonable maximum size
template<class t>
class Stack{
    private:
        t stack_implemented[MAX_SIZE];
        ll top;
    public:
        Stack(){
            top = -1; 
        }
        
        void push(t Element){
            if(top>=MAX_SIZE-1)// zero pased
                cout << "Stack Full On Push\n";
            else{
                ++top;
                stack_implemented[top] = Element;
            }
        }

        bool IsEmpty(){
            return top<0;
        }

        t Top(){
            if(IsEmpty()){
                cout << "stack empty on Top\n";
            }
            else{
                t stacktop = stack_implemented[top];
                return stacktop;
            }
        }
        
        void pop(){
            if(IsEmpty()){
                cout << "stack empty on pop\n";
            }
            else{
                top--;
            }
        }

        void print(){
            cout << "[ ";
            for(ll i = top; i >= 0; i--){
                cout << stack_implemented[i] << " ";
            }
            cout << "]";
            cout << endl;
        }
};


int main(){
    Stack<ll>s;
    s.push(5);
    s.push(15);
    s.push(20);
    s.push(10);
    cout << s.Top() << endl;
    s.pop();
    cout << s.Top() << endl;
    s.print();
}