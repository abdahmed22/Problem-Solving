/*An encryption key is hidden in a binary tree. The key is the concatenation of sums of selected levels of the tree.
The selected levels start at level 0 (root level) and continues down the tree by K steps every time.
For a tree with 9 levels, if K=3, the selected levels will be 0, 3, 6. K is the minimum value of the Lth level % the tree height.
L is the value of the root % the tree height. You are allowed to use unordered_map and unordered_set if needed. If K is 0, set to 1 instead. */


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

struct node {
    int data;
    struct node* parent;
    struct node* right;
    struct node* left;
};

int height(struct node* root, int H) {
    if (root == nullptr) {
        return H;
    }

    H++;

    int left = height(root->left, H);
    int right = height(root->right, H);
    
    return max(left, right);
}

struct node* newNode(int data) {
    struct node* Node = new struct node;
    
    Node->data = data;
    Node->right = nullptr;
    Node->left = nullptr;
    Node->parent = nullptr;
    
    return Node;
}

void build(vector<node*> nodes, int E) {
    string S;
    int P;
    int C;

    for (int i = 0; i < E; i++) {
        cin >> S >> P >> C;
        
        if (S == "L") {
            nodes[P]->left = nodes[C];
            nodes[C]->parent = nodes[P];
        } else {
            nodes[P]->right = nodes[C];
            nodes[C]->parent = nodes[P];
        }
    }
    return;
}

void print(node* root) {
    if (root == nullptr)
        return;
    
    cout << root->data << " ";
    
    print(root->left);
    print(root->right);
}

int main() {
    int N;
    int data;
    int E;
    int H;
    vector<node*> nodes;
    queue<node*> queue;
    node* root;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> data;
        nodes.push_back(newNode(data));
    }
    
    cin >> E;
    
    build(nodes, E);
    
    H = height(nodes[0], 0); 
    
    queue.push(nodes[0]);

    int level = 0;
    int L = nodes[0]->data % H;
    int minimum = INT32_MAX;
    
    while (!queue.empty()) {
        int size = queue.size();
        for (int i = 0; i < size; i++) {
            root = queue.front();
            queue.pop();
            

            if (root != nullptr) {
                if (root->left) 
                    queue.push(root->left);
                if (root->right) 
                    queue.push(root->right);
            }
            
            if (level == L) {
                minimum = min(minimum, root->data);
            }
        }
        level++;
    }
    
    int K = minimum % H;
    K = max(K, 1);
    string key = "";
    level = 0;
    queue.push(nodes[0]);

    while (!queue.empty()) {
        int size = queue.size();
        int subKey = 0;
        for (int i = 0; i < size; i++) {
            root = queue.front();
            queue.pop();
            

            if (root != nullptr) {
                if (root->left) 
                    queue.push(root->left);
                if (root->right) 
                    queue.push(root->right);
                if (level % K == 0) 
                   subKey += root->data;
            }
        }
        if ((level % K == 0) && (subKey != 0)) {
            key += to_string(subKey);
        }
        level++;
    }

    cout << key;
   
    return 0;
}
