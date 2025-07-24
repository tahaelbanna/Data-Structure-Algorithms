#include<iostream>
using namespace std;
using ll = long long;
template<class t>
class Stack{
    private:
        struct node{
            t item;
            node *next;
        };
        node *top;
        node *current;
    public:
        
        Stack(){
            top = NULL;
        }
        
        bool IsEmpty(){
            return top == NULL;
        }

        void push(t newitem){
            node *newitemptr = new node;
            if(newitemptr == NULL){
                cout << "Stack push cannot allocate memory\n";
            }
            else{
                newitemptr->item = newitem;
                newitemptr->next = top;
                top = newitemptr;
            }
        }

        void pop(){
            if(IsEmpty()){
                cout << "Stack empty on pop\n";
            }
            else{
                node *temp = top;
                top = top->next;
                temp->next = NULL;
                delete temp;
            }
        }

        t Top(){
            if(IsEmpty()){
                cout << "Stack empty on top\n";
            }
            else{
                t topitem = top->item;
                return topitem;
            }
        }

        void display(){
            current = top;
            cout << "Items in the stack : \n";
            cout << "[ ";
            while(current!=NULL){
                cout << current->item << " ";
                current = current->next;
            }
            cout << " ]\n";
        }
};

int main(){
    Stack<ll>s;
    s.push(19);
    s.push(29);
    s.push(39);
    s.display();
    cout << s.Top() << endl;
    s.pop();
    cout << s.Top() << endl;
}