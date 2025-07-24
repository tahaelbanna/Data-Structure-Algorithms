#include <iostream>
using namespace std;
using ll = long long;
template<class t>
class ArrayList {
private:
    t *lst;
    ll counter;
    ll MaxSize;
public:
    ArrayList(ll size) {
        if (size <= 0) {
            cout << "Wrong Size\nDefult Size Is 100\n";
            MaxSize = 100;
        }
        else {            
            MaxSize = size;
        }
        counter = 0;
        lst = new t[MaxSize];
    }

    bool empty() {
        return counter == 0;
    }

    bool full() {
        return counter == MaxSize;
    }

    ll size() {
        return counter;
    }

    ll MAX_SIZE() {
        return MaxSize;
    }

    void print() {
        cout << "[ ";
        for (ll i = 0 ; i < counter ; ++i ) {
            cout << lst[i] << " ";
        }
        cout << " ]";
        cout << '\n';
    }

    bool equality(ll location , t Element) {
        if (location < 0 || location >= counter) {
            cout << "Out Of Range!\n";
        }
        else {
            return lst[location] == Element;
        }
    }

    void insert(ll location , t Element) {
        if (full()) {
            cout << "The array is Full on insert\n";
        } 
        else if (location < 0 || location > counter) {
            cout << "Out Of Range!\n";
        }
        else {
            for (ll i = counter ; i > location ; --i ) {
                lst[i] = lst[i-1];
            }   
            lst[location] = Element;
            counter++;
        }
    }
    
    void push_back(t Element) {
        if (full()) {
            cout << "The array is Full on insert\n";
        } 
        else {
            lst[counter++] = Element; 
        }
    }

    void replace(ll location , t Element) {
        if (location < 0 || location >= counter) {
            cout << "Out Of Range!\n";
        }
        else {
            lst[location] = Element;
        }
    }

    void retrive(ll location , t &Element) {
        if (location < 0 || location >= counter) {
            cout << "Out Of Range!\n";
        }
        else {
            Element = lst[location];
        }
    }

    void clear() {
        counter = 0;
    }

    ll search(t Element) {
        for (ll i = 0 ; i < counter ; ++i ) {
            if (lst[i] == Element) {
                return i;
            }
        }
        return -1;
    }

    void distinct_insert(ll location , t Element) {
        if (full()) {
            cout << "The array is Full on insert\n";
        } 
        else if (location < 0 || location > counter) {
            cout << "Out Of Range!\n";
        }
        else {
            if (search(Element) != -1) {
                cout << "Exist\n";
            }
            else {
                insert(location, Element);
            }
        }
    }

    void remove_at(ll location) {
        if (empty()) {
            cout << "The array is empty on remove\n";
        } 
        else if (location < 0 || location >= counter) {
            cout << "Out Of Range!\n";
        }
        else {
            for(ll i = location ; i < counter - 1; ++i ) {
                lst[i] = lst[i + 1];
            }
            counter--;
        }
    }

    void remove_by_search(t Element) {
        if (search(Element) == -1) {
            cout << "Element Not Exist\n";
        }
        else {
            remove_at(search(Element));
        }
    }
    ~ArrayList() {
        delete[] lst;
    }
};

int main() {
    ArrayList<ll> a(5);
    a.push_back(10);
    a.push_back(20);
    a.push_back(30);
    a.push_back(40);
    a.push_back(50);
    cout << a.search(30) << endl;
    a.remove_by_search(10);
    a.distinct_insert(1,15);
    a.print();
}