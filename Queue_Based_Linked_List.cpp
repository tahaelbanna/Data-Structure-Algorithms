#include <iostream>
#include <assert.h>
using namespace std;
using ll = long long;

template<class t>
class Linked_Queue {
private:
    struct Node {
        t item;
        Node *next;
    };
    Node *Front ;
    Node *Rear;
    ll counter = 0; 
public:
    Linked_Queue () {
        Front = NULL;
        Rear = NULL;
        counter = 0;
    }

    bool empty() {
        return counter == 0;
    }

    ll size() {
        return counter;
    }

    t back() {
        assert (!empty());
        return Rear->item;
    }

    t front() {
        assert (!empty());
        return Front->item;
    }

    void push (t Element){
        if (empty()) {
            Node *newitem = new Node;
            newitem->item = Element;
            newitem->next = NULL;
            Rear = Front = newitem;
        }
        else {
            Node *newptr = new Node;
            newptr->item = Element;
            newptr->next = NULL;
            Rear->next = newptr;
            Rear = newptr;
        }
        counter++;
    }

    void pop(){
        if (empty()) {
            cout << "Queue is empty on pop\n";
        }
        else {
            Node *temp = Front;
            if (Front == Rear) {
                Front = NULL;
                Rear = NULL;
            }
            else {
                Front = Front->next;
                temp->next = NULL;
            }
            delete temp;
            counter--;
        }
    }

    void clear() {
        if (empty()) {
            cout << "Queue is empty on clear\n";
        }
        else {
            Node *current = Front;
            while (current!=NULL) {
                Node *temp = current;
                current = current->next;
                delete temp;
            }
            Rear = NULL;
            Front = NULL;
            counter = 0;
        }
    }
    void display() {
        if (empty()) {
            cout << "Queue is empty on display\n";
        }
        else {
            Node *current = Front;
            cout << "Linked_Queue Displayment: \n";
            cout << "[ ";
            while (current!=NULL) {
                cout << current->item << " ";
                current = current->next;
            }
            cout << " ]\n";
        }
    }

    void search(t Element) {
        Node *current = Front;
        bool found = false;
        ll Position = 0;
        while (current != NULL) {
            if (current->item == Element) {
                cout << Element << " Located in: " << Position << endl;
                found = true;
                break;
            }
            current = current->next;
            Position++;
        } 
        if (!found) {
            cout << "The Element Is Not Locted In Queue\n";
        }
    }
    void reverse() {
        if (empty() || Front == Rear) {
            cout << "This Queue Can not be revrsed\n";
        }

        Node* prev = NULL;
        Node* current = Front;
        Node* next = NULL;
        Rear = Front;

        while (current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;         
            current = next;
        }

        Front = prev;
    }
};

int main() {
    Linked_Queue<ll>q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    cout << q.front() << endl;
    cout << q.back() << endl;
    cout << q.size() << endl;
    q.display();
    q.search(30);
    q.pop();
    q.pop();
    q.reverse();
    q.display();
}