#include <iostream>
#include <assert.h>
using namespace std;
using ll = long long;

// DAYNAMIC QUEUE

template<class t>
class Daunamic_queue{
private:
    ll Front;
    ll Rear;
    ll counter;
    t *arr;
    ll MaxSize;
public:
    Daunamic_queue(ll size){
        if (size <= 0){
            MaxSize = 100;
        }
        else {
            MaxSize = size;
        }
        Front = 0;
        arr = new t[MaxSize];
        Rear = MaxSize-1;
        counter = 0;
    }
    bool empty(){
        return counter == 0;
    }
    bool full(){
        return counter == MaxSize;
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
        Rear = (Rear + 1) % MaxSize; // proven in circual queue
        counter++;
        arr[Rear] = Element;
    }
    void pop(){
        assert(!empty());
        Front = (Front + 1) % MaxSize; // proven in circual queue
        counter--;
    }
    void display(){
        if (!empty()){
            cout << "The Elements In Queue: \n";
            cout << " [ ";
            for(ll i = Front ; i != Rear ; i = (i + 1) % MaxSize){
                cout << arr[i] << " <- ";
            }
            cout << arr[Rear];
            cout << " ] \n";
        }
        else {
            cout << "An Empty Queue\n";
        }
    }
    ll Search(ll Element){
        ll position = -1;
        if (!empty()){
            for(ll i = Front ; i != Rear ; i = (i + 1) % MaxSize){
                if(arr[i] == Element) {
                    position = i;
                    break;
                }
            }
            if (position == -1){
                if (arr[Rear] == Element)
					position = Rear;
                else{
                    cout << "An Item Not In Queue\n";
                    return 0;
                }
            }
        }
        else {
            cout << "An Empty Queue\n";
            return 0;
        }
        return position;
    }
    ~Daunamic_queue(){
        delete[]arr;
    }
};
int main(){
    Daunamic_queue<ll>q(5);
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    cout << q.Search(40) << endl;
    q.display();
    q.pop();
    cout << q.front() << endl;
    cout << q.back() << endl;
    q.pop();
    q.pop();
    cout << (q.empty() ? "Queue is empty\n" : "Queue is not empty\n");
    cout << (q.full() ? "Queue is full\n" : "Queue is not full\n");
}