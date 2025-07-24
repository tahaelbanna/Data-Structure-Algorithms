#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void selection_sort(vector<ll> &a , ll &n) {
    ll minimam_index = 0;
    for (ll i = 0 ; i < n-1 ; ++i) {
        minimam_index = i;
        for (ll j = i+1 ; j < n ; ++j) {
            if (a[j] < a[minimam_index]) {
                minimam_index = j;
            } 
        }
        swap(a[minimam_index] , a[i]);
    }
}

void bubble_sort(vector<ll> &a , ll &n) {
    for (ll i = 0 ; i < n - 1 ; ++i) {
        bool flag = false;
        for (ll j = 0 ; j < n - i - 1 ; ++j) {
            if (a[j] > a[j + 1]) {
                swap(a[j] , a[j + 1]);
                flag = true;
            }
        }
        if (!flag) {
            break;
        }
    }
}

void insertion_sort(vector<ll> &a , ll &n) {
    ll key = 0;
    ll j = 0;
    for (ll i = 1 ; i < n ; ++i) {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void merge(ll arr[] , ll left , ll mid , ll right) {
    ll i , j , k;
    ll n1 = mid - left + 1;
    ll n2 = right - mid;
    ll *subleft = new ll[n1];
    ll *subright = new ll[n2];
    for (ll i = 0 ; i < n1 ; ++i) {
        subleft[i] = arr[left + i];
    }
    for (ll j = 0 ; j < n2 ; ++j) {
        subright[j] = arr[mid + 1 + j];
    }
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (subleft[i] <= subright[j]) {
            arr[k] = subleft[i];
            i++;
        }
        else {
            arr[k] = subright[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = subleft[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = subright[j];
        j++;
        k++;
    }
}

void merge_sort(ll arr[] , ll left , ll right) {
    ll mid = left + (right - left) / 2;
    merge_sort(arr , left , mid);
	merge_sort(arr , mid + 1 , right);
	merge(arr , left , mid , right);
}

ll partition(ll arr[] , ll left , ll right) {
    ll pivot = arr[left];
    ll i = left;
    ll j = right;
    while (i < j) {
        do {
            i++;
        }
        while (arr[i] <= pivot);
        do {
            j--;
        }
        while (arr[j] > pivot);
        if (i < j) {
            swap(arr[i] , arr[j]);
        } 
    }
    swap(arr[j] , arr[left]);
    return j;
}
void quick_sort(ll arr[] , ll left , ll right) {
    if (left < right) {
        ll pivot = partition(arr , left , right);
        quick_sort(arr , left , pivot);
        quick_sort(arr , pivot + 1 , right);
    }
}

void heapify(ll arr[] , ll n , ll i) {
    ll left = i*2 + 1;
    ll right = i*2 + 2;
    ll mx = i;
    if (left < n && arr[left] > arr[mx]) {
        mx = left;
    }
    if (right < n && arr[right] > arr[mx]) {
        mx = right; 
    }
    if (mx != i) {
        swap(arr[mx],arr[i]);
        heapify(arr , n , mx);
    }
}
void buildheap(ll arr[] , ll n) {
    for (ll i = n/2 - 1 ; i >= 0 ; --i){
        heapify(arr , n , i);
    }
}
void heap_sort(ll arr[] , ll n) {
    buildheap(arr , n);
    for (ll i = n - 1 ; i > -1 ; --i) {
        swap(arr[0] , arr[i]);
        heapify(arr , i , 0);
    }
}


int main() {
    vector<ll> a = {3,2,6,1,5,9};
    vector<ll> b = {1,2,3,6,5,9,0};
    vector<ll> l = {80,90,60,30,100,70};
    ll l_[] = {100,40,60,90,20,1000,10};
    ll n = size(a);
    ll m = size(b);
    ll k = size(l);
    ll k_ = size(l_);
    selection_sort(a , n);
    bubble_sort(b , m);
    insertion_sort(l , k);
    merge_sort(l_ , 0 , k_ - 1);
    for (ll i = 0 ; i < n ; ++i) cout << a[i] << " ";
    cout << endl;
    for (ll i = 0 ; i < m ; ++i) cout << b[i] << " ";
    cout << endl;
    for (ll i = 0 ; i < k ; ++i) cout << l[i] << " ";
    cout << endl;
    for (ll i = 0 ; i < k_ ; ++i) cout << l_[i] << " ";
    cout << endl;
}