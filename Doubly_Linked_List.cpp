#include <iostream>
using namespace std;
using ll = long long;
template<class t>

class DoublyLinkedList {
private:
    struct Node{
        t item;
        Node *next;
        Node *previous;
    };
    ll counter;
    Node *first;
    Node *last;
public:
    DoublyLinkedList() {
        counter = 0;
        first = NULL;
        last = NULL;
    }

    bool empty() {
        return counter == 0;
    }

    void push_front(t Element) {
        Node *newitem = new Node;
        newitem->item = Element;
        if(empty()) {
            newitem->next = NULL;
            newitem->previous = NULL;
            first = newitem;
            last = newitem;
        }
        else {
            newitem->previous = NULL;
            newitem->next = first;
            first->previous = newitem;
            first = newitem;
        }
        counter++;
    }

    void push_back(t Element) {
        Node *newitem = new Node;
        newitem->item = Element;
        if(empty()) {
            newitem->next = NULL;
            newitem->previous = NULL;
            first = newitem;
            last = newitem;
        }
        else {
            newitem->next = NULL;
            newitem->previous = last;
            last->next = newitem;
            last = newitem;
        }
        counter++;
    }

    void insert(ll position , t Element) {
        if (position < 0 || position > counter) {
            cout << "OUT OF RANGE!\n";
        }
        else if (position == 0) {
            push_front(Element);
        }
        else if (position == counter) {
            push_back(Element);
        }
        else {
            Node *current = first;
            for (ll i = 1 ; i < position ; ++i) {
                current = current->next;
            }
            Node *newitem = new Node;
            newitem->item = Element;
            newitem->next = current->next;
            newitem->previous = current;
            current->next->previous = newitem;
            current->next = newitem;
            counter++;
        }
    }

    void pop_back() {
        if (empty()) {
            cout << "IS EMPTY ON POP\n";
        }
        else if (counter == 1) {
            delete first;
            first = NULL;
            last = NULL;
            counter--;
        }
        else {
            Node *current = last;
            last = last->previous;
            current->previous = NULL;
            delete current;
            last->next = NULL;
            counter--;
        }
    }

    void pop_front() {
        if (empty()) {
            cout << "IS EMPTY ON POP\n";
        }
        else if (counter == 1) {
            delete first;
            first = NULL;
            last = NULL;
            counter--;
        }
        else {
            Node *current = first;
            first = first->next;
            current->next = NULL;
            first->previous = NULL;
            delete current;
            counter--;
        }
    }

    void erase(ll position) {
        if (position < 0 || position >= counter) {
            cout << "OUT OF RANFE!\n";
        }
        else if (position == 0) {
            pop_front();
        }
        else if (position == counter-1) {
            pop_back();
        }
        else {
            Node *current = first->next;
            for (ll i = 1 ; i < position ; ++i) {
                current = current->next;
            }
            current->previous->next = current->next;
			current->next->previous = current->previous;
			delete current;
            counter--;
        }
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
    
    bool find(t Element) {
        Node *current = first;
        ll position = 0;
        while (current != NULL) {
            if (current->item == Element) {
                return true;
            }
            position++;
            current = current->next;
        }
        return false;
    }

    void remove(t Element) {
        if (empty()) {
            cout << "EMPTY ON REMOVE\n";
        }
        else if (!find(Element)) {
            cout << "ITEM NOT FOUND\n";
        }
        else {
            Node *current = first->next;
            if (first->item == Element) {
                pop_front();
            }
            else {
                while (current != NULL) {
                    if (current->item == Element) {
                        break;
                    }
                    current = current->next;
                }
                if (current == NULL) {
                    cout << "ITEM NOT FOUND\n";
                }
                else if (current->next == NULL) {
                    pop_back();
                }
                else {
                    current->previous->next = current->next;
                    current->next->previous = current->previous;
                    delete current;
                    counter--;
                }
            }
        }
    }

    ~DoublyLinkedList() {
        Node *temp ;
        while (first != NULL) {
            temp = first;
            first = first->next;
            delete temp;
        }
        counter = 0;
        last = NULL;
    }
};