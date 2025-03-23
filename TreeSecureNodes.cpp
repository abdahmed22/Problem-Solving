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

bool isSecure(node* node) {
    int max = node->data;
    
    if (node->parent == nullptr)
        return true;

    while (node->parent != nullptr) {
        if (node->parent->data > max) {
            return false;
        }
        node = node->parent;
    }
    return true;
}

int main() {
    int N;
    int data;
    int E;
    int result = 0;
    vector<node*> nodes;
    node* root;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> data;
        nodes.push_back(newNode(data));
    }
    
    cin >> E;
    
    root = nodes[0];
    build(nodes, E);
        
    for (int i = 0; i < N; i++) {
        if(isSecure(nodes[i])) {
            result++;
        }        
    }
    
    cout << result;
    
    return 0;
}
