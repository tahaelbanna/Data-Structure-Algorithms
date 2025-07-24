#include <iostream>
#include <queue>
#include <stack>
using namespace std;
using ll = long long;
template<class t>
class Binarysearchtree {
private:
    struct Node{
        t item;
        Node *left;
        Node *right;
    };
    Node *root;
public:
    Binarysearchtree() {
        root = NULL;
    }
    Node *getRoot() {
        return root;
    }
    bool empty() {
        return root == NULL;
    }
    void clear(Node *root) {
        if (root != NULL) {
            clear(root->left);
            clear(root->right);
            delete root;
            root = NULL;
        }
    }
    ll hight(Node *root) {
        if (root == NULL) {
            return 0;
        }
        else {
            return 1 + std::max(hight(root->left) , hight(root->right));
        }
    }
    ll countNode(Node *root) {
        if (root == NULL) {
            return 0;
        }
        else {
            return 1 + countNode(root->left) + countNode(root->right);
        }
    }
    ll leavesCount(Node *root) {
        if (root == NULL) {
            return 0;
        }
        else if ((root->left == NULL) && (root->right == NULL)) {
            return 1;
        }
        else {
            return leavesCount(root->left) + leavesCount(root->right);
        }
    }
    void pre_order(Node *root) {
        if (root != NULL) {
            cout << root->item << " ";
            pre_order(root->left);
            pre_order(root->right);
        }
    }
    void pre_order_iterative(Node *root) {
        if (!root) {
            return;
        }
        stack<Node*>st;
        st.push(root);
        while (!st.empty()) {
            Node *current = st.top();
            cout << current->item << " ";
            st.pop();
            if (current->right != NULL) {
                st.push(current->right);
            }
            if (current->left != NULL) {
                st.push(current->left);
            }
        }
    }
    void in_order(Node *root) {
        if (root != NULL) {
            in_order(root->left);
            cout << root->item << " ";
            in_order(root->right);
        }
    }
    void in_order_iterative(Node *root) {
        stack<Node*>st;
        Node *current = root;
        while (current != NULL || !st.empty()) {
            while (current != NULL) {
                st.push(current);
                current = current->left;
            }
            current = st.top();
            st.pop();
            cout << current->item << " ";
            current = current->right;
        } 
        
    }
    void post_order(Node *root) {
        if (root != NULL) {
            post_order(root->left);
            post_order(root->right);
            cout << root->item << " ";
        }
    }
    void Double_Stack_post_order_iterative(Node *root) {
        if (!root) {
            return;
        } 
        stack<Node*> s1 , s2;
        s1.push(root);
        while (!s1.empty()) {
            Node *current = s1.top();
            s1.pop();
            s2.push(current);
            if (current->left != NULL) {
                s1.push(current->left);
            }
            if (current->right != NULL) {
                s1.push(current->right);
            }
        }
        while (!s2.empty()) {
            cout << s2.top()->item << " ";
            s2.pop();
        }
    }
    void Single_Stack_post_order_iterative(Node *root) {
        if (!root) {
            return;
        } 
        stack<Node*> s1;
        Node *lastedge = NULL;
        Node *current = root;
        while (current != NULL || !s1.empty()) {
            if (current != NULL) {
                s1.push(current);
                current = current->left;
            }
            else {
                Node *ptr = s1.top();
                if (ptr->right != NULL && lastedge != ptr->right) {
                    current = ptr->right;
                }
                else {
                    cout << ptr->item << " ";
                    lastedge = ptr;
                    s1.pop();
                }
            }
        }
    }
    void level_order(Node *root) {
        if (root == NULL) {
            return;
        }
        queue<Node*>q;
        q.push(root);
        while (!q.empty()) {
            Node *current = q.front();
            cout << current->item << " ";
            if (current->left != NULL) {
                q.push(current->left);
            }
            if (current->right != NULL) {
                q.push(current->right);
            }
            q.pop();
        }
    }
    void insert(t key) {
        root = insert(root, key);
    }
    Node* insert(Node* node, t key) {
        if (node == NULL) {
            return new Node{key, NULL, NULL};
        }
        if (key < node->item) {
            node->left = insert(node->left, key);
        }
        else if (key > node->item) {
            node->right = insert(node->right, key);
        }
        return node;
    }
    void remove(t key) {
        root = remove(root, key);
    }
    Node *remove(Node* node, t key) {
        if (node == NULL) {
            return NULL;
        }
        if (key < node->item) {
            node->left = remove(node->left, key);
        }
        else if (key > node->item) {
            node->right = remove(node->right, key);
        }
        else {
            if (node->left == NULL) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == NULL) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* succ = minValueNode(node->right);
            node->item = succ->item;
            node->right = remove(node->right, succ->item);
        }
        return node;
    }
    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current != NULL && current->left != NULL)
            current = current->left;
        return current;
    }
    bool search(t Element) {
        Node *current = root;
        while (current != NULL) {
            if (current->item == Element) {
                return true;
            }
            else if(current->item > Element) {
                current = current->left;
            }
            else {
                current = current->right;
            }
        }
        return false;
    }
    ~Binarysearchtree() {
        clear(root);
    }
};

int main() {
    Binarysearchtree<ll>tree;
    tree.insert(40);
    tree.insert(30);
    tree.insert(60);
    tree.insert(20);
    tree.insert(50);
    tree.insert(70);

    tree.in_order(tree.getRoot());
    cout << "\n";

    tree.remove(60);
    tree.in_order(tree.getRoot());
    cout << "\n";
    
    cout << (tree.search(50)?"Founded":"Not Founded");
    cout << "\n";
    cout << (tree.search(100)?"Founded":"Not Founded");
}

