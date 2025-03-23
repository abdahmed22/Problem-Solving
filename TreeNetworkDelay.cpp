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

int longestPath(node* node, int depth) {
    if (node == nullptr)
        return depth;
    
    depth ++;
    int left = longestPath(node->left, depth);
    int right = longestPath(node->right, depth);

    return max(left, right);
}

void print(node* root) {
    if (root == nullptr)
        return;
    
    cout << root->data << endl;
    
    print(root->left);
    print(root->right);
}


int main() {
    int N;
    int data;
    int E;
    int result = 0;
    vector<node*> nodes;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> data;
        nodes.push_back(newNode(data));
    }
    
    cin >> E;
    
    build(nodes, E);
        
    for (int i = 0; i < N; i++) {
        int left = 0;
        int right = 0;
        
        if (nodes[i]-> left != nullptr) {
            left = longestPath(nodes[i]->left, 0);
        }
       
        if (nodes[i]-> right != nullptr) {
            right = longestPath(nodes[i]->right, 0);
        }
        
        result = max(right + left, result);
    }
    
    cout << result;
        
    return 0;
}
