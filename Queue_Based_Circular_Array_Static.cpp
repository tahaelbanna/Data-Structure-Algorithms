#include <iostream>
#include <assert.h>
using namespace std;
using ll = long long;
// A FIXED SIZE QUEUE ||
const ll MAX_SIZE = 100;
template<class t>
class queue{
private:
    ll Front;
    ll Rear;
    ll counter;
    t arr[MAX_SIZE];
public:
    queue(){
        Front = 0;
        Rear = MAX_SIZE-1;
        counter = 0;
    }
    bool empty(){
        return counter == 0;
    }
    bool full(){
        return counter == MAX_SIZE;
    }
    t front(){
        assert(!empty());
        return arr[Front];
    }
    t back(){
        assert(!empty());
        return arr[Rear];
    }
    void push(t Element){
        assert(!full());
        Rear = (Rear + 1) % MAX_SIZE; // proven in circual queue
        counter++;
        arr[Rear] = Element;
    }
    void pop(){
        assert(!empty());
        Front = (Front + 1) % MAX_SIZE; // proven in circual queue
        counter--;
    }
    void display(){
        if (!empty()){
            cout << "The Elements In Queue: \n";
            cout << " [ ";
            for(ll i = Front ; i != Rear + 1 ; i = (i + 1) % MAX_SIZE){
                cout << arr[i] << " <- ";
            }
            cout << " ] \n";
        }
        else {
            cout << "An Empty Queue\n";
        }
    }
};
int main(){
    queue<ll>q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.display();
    q.pop();
    cout << q.front() << endl;
    cout << q.back() << endl;
    q.pop();
    q.pop();
    cout << (q.empty() ? "Queue is empty\n" : "Queue is not empty\n");
    cout << (q.full() ? "Queue is full\n" : "Queue is not full\n");
}
