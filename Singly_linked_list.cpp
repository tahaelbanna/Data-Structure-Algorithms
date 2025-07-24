#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
template<class t>

class LinkedList {
private:
    struct Node {
        t item;
        Node *next;
    };
    ll counter;
    Node *first;
    Node *last;
public:
    LinkedList() {
        counter = 0;
        first = NULL;
        last = NULL;
    }

    bool empty() {
        return counter == 0;
    }

    void push_back(t Element) {
        
        Node *newitem = new Node;
        newitem->item = Element;

        if (counter == 0) {
            newitem->next = NULL; 
            first = last = newitem;
        } 

        else {
            last->next = newitem;
            last = newitem;
            newitem->next = NULL;
        }

        counter++;
    }

    void push_front(t Element) {

        Node *newitem = new Node;
        newitem->item = Element;
        if (counter == 0) {
            newitem->next = NULL; 
            first = last = newitem;
        } 

        else {
            newitem->next = first;
            first = newitem;
        }

        counter++;
    }

    void insert(t Element , ll position) {
        if (position < 0 || position > counter) {
            cout << "Invalid position\n";
        }

        else {

            if (position == 0) {
                push_front(Element);
            }

            else if (position == counter) {
                push_back(Element);
            }

            else {
                Node *current = first;
                Node *newitem = new Node;
                newitem->item = Element;
                for (ll i = 1 ; i < position ; ++i ) {
                    current = current->next;
                }
                newitem->next = current->next;
                current->next = newitem;
                counter++;
            }
        }
    }

    void print() {
        Node *current = first;
        cout << "[ ";
        while (current != NULL) {
            cout << current->item << " ";
            current = current->next;
        }
        cout << " ]\n";
    }

    void clear() {
        Node *current = first;
        while (current != NULL) {
            Node *temp = current;
            current = current->next;
            delete temp;
        }
        first = NULL;
        last = NULL;
        counter = 0;
    }

    void pop_front() {
        if (empty()) {
            cout << "The Linkedlist is empty on pop\n";
        }
        else {
            if (counter == 1) {
                delete first;
                last = NULL;
                first = NULL;
            }
            else {
                Node *temp = first;
                first = first->next;
                delete temp;
            }
            counter--;
        }
    }
    
    void pop_back() {
        if (empty()) {
            cout << "The Linkedlist is empty on pop\n";
        }
        else {
            if (counter == 1) {
                delete first;
                last = NULL;
                first = NULL;
            }
            else {
                Node *current = first;
                Node *previous = nullptr;
                while (current->next != NULL) {
                    previous = current;
                    current = current->next;
                }
                if (previous != nullptr) {
                    previous->next = NULL;
                    last = previous;
                }
                delete current;
            }
            counter--;
        }
    }

    void pop_it(t Element) {
        if (empty()) {
            cout << "The Linkedlist is empty on pop\n";
        }
        else {
            Node *current = first->next;
            Node *previous = first;
            if (first->item == Element) {
                current = first;
                first = first->next;
                delete current;
                counter--;
                if (counter == 0) {
                    last = NULL;
                }
                return;
            }
            
            while (current != NULL){
                if (current->item == Element) {
                    break;
                }
                previous = current;
                current = current->next;
            }
            
            if (current == NULL) {
                cout << "The Item not Exist\n";
            }
            else {
                previous->next = current->next;
                if (last == current) {
                    last = previous;
                }
                delete current;
                counter--;
            }
        }
    }

    void pop_at(ll position) {
        if (position < 0 || position >= counter) {
            cout << "Invalid position\n";
        }
        else if (empty()) {
            cout << "The Linkedlist is empty on pop\n";
        }
        else {
            Node *current = first;
            Node *previous = nullptr;
            if (position == 0) {
                first = first->next;
                delete current;
                counter--;
                if (counter == 0) {
                    last = nullptr;
                }
            }
            else {
                for (ll i = 0 ; i < position ; ++i) {
                    previous = current;
                    current = current->next;
                }
                previous->next = current->next;
                if (current == last) {
                    last = previous;
                }
                delete current;
                counter--;
            }
        }
    }

    void reverse() {
        Node *previous , *next , *current;
        previous = NULL;
        current = first;
        next = NULL;
        while (current != NULL) {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        first = previous;
    }

    ll search(t Element) {
        Node *current = first;
        ll position = 0;
        while (current != NULL) {
            if (current->item == Element) {
                return position;
            }
            position++;
            current = current->next;
        }
        return -1;
    }

    void sort() {
        if (counter <= 1) {
            return;
        }
        t* array = new t[counter];
        Node* current = first;
        for (ll i = 0 ; i < counter ; ++i) {
            array[i] = current->item;
            current = current->next;
        }
        std::sort(array , array + counter);
        current = first;
        for (ll i = 0; i < counter; ++i) {
            current->item = array[i];
            current = current->next;
        }
        delete[] array;
    }

    ~LinkedList() {
        clear();
    }
};

int main() {
    LinkedList<ll>a;
    a.push_back(10);
    a.push_back(40);
    a.push_back(30);
    a.push_back(20);
    a.print();
    a.sort();
    a.print();
}