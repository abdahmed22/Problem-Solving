#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
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
        } else {
            nodes[P]->right = nodes[C];
        }
    }
    return;
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
    
    root = nodes[0];
    build(nodes, E);
    
    H = height(root, 0); 
    
    nodes.clear();
    
    queue.push(root);

    while (!queue.empty()) {
        root = queue.front();
        queue.pop();

        if (root->left != nullptr) {
            nodes.push(root->left);
        }
        
        if (root->right != nullptr) {
            nodes.push(root->right);
        }
    }
  
    return 0;
}
