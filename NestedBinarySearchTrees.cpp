// A binary search tree consists of nodes having the following data: a department key and a pointer to another binary search tree.
// The secondary binary search tree nodes contain ids of type integer.
// The nested binary search tree allows duplicate department keys, but does not allow duplicate pairs of department key and id.
// This means that there are no two elements containing the same department key and the same id. Given N pairs (department key and id) create the nested BST without balancing. 
// You will then be given Q queries. For each query, print the number of nodes visited, and whether you found the query.



#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

struct node {
    int data;
    struct node* right;
    struct node* left;
    struct node* parent;
    struct node* tree;
};


struct node* newNode(int data) {
    struct node* Node = new struct node;
    
    Node->data = data;
    Node->right = nullptr;
    Node->left = nullptr;
    Node->parent = nullptr;
    Node->tree = nullptr;
    
    return Node;
}

void print(node* root) {
    if (root == nullptr)
        return;
    
    cout << root->data << " ";
    
    print(root->left);
    print(root->right);
}

void build(node*& root, node* Z) {
    node* Y = nullptr;
    node* X = root;
    
    while (X != nullptr) {
        Y = X;
        if (Z->data < X->data) {
            X = X->left;
        } else {
            X = X->right;
        }    
    }
    Z->parent = Y;
    
    if (Y == nullptr) {
        root = Z;
    } else if (Z->data < Y->data) {
        Y->left = Z;
    } else {
        Y->right = Z;    
    } 
}

pair<int, bool> searchTrees(node* root, pair<int, int> query) {
    int visited = 0;
    while (root != nullptr) {
        visited++;
        if (root->data == query.first) 
            break;
        if (query.first < root->data)
            root = root->left;
        else
            root = root->right;
    }
    
    if (root == nullptr) {
        return {visited, false};
    } else {
        root = root->tree;    
    }

    if (root == nullptr) {
        return {visited, false};
    }
    
    while (root != nullptr) {
        visited++;
        if (root->data == query.second) 
            return {visited, true};
        if (query.second < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return {visited, false};
}

int main() {
    int N;
    int Q;
    int departmentKey;
    int id;
    node* root = nullptr;
    
    map<int, vector<int>> data;
    map<int, node*> nodes;
    vector<pair<int, int>> queries;
    

    cin >> N;
    cin >> Q;

    for (int i = 0; i < N; i++) {
        cin >> departmentKey;
        cin >> id;

        if (data.find(departmentKey) == data.end()) {
            vector<int> ids;
            ids.push_back(id);
            data.insert({departmentKey, ids});
        } else {
            data[departmentKey].push_back(id);
        }
    }
    
    for (int i = 0; i < Q; i++) {
        cin >> departmentKey;        
        cin >> id;
        queries.push_back(make_pair(departmentKey, id));
    }

    for (auto i = data.begin(); i != data.end(); i++) { 
        node* node1 = newNode(i->first);
        build(root, node1);
        nodes[i->first] = node1;

        node* root2 = nullptr;

        for (size_t j = 0; j < i->second.size(); j++) {
            node* node2 = newNode(i->second[j]);
            build(root2, node2);
        }

        nodes[i->first]->tree = root2;
    }
    
    
    for (int i = 0; i < Q; i++) {
        pair<int, bool> result = searchTrees(root, queries[i]);
        cout << result.first << " " << result.second << endl;
    }
    
    
    return 0;
}
