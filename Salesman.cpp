// We want to send a salesman to all nearby cities. cities are connected using one way roads.
// If the salesman arrives at a city, 
// he can move to all nearby cities he can reach through the roads under the condition that he can return to the initial city he arrived in. 
// You want to send the salesman to the minimum number of cities possible so that every other city gets visited by the salesman. 
// Given N citiess and M roads, find the minimum number of cities you need to send the salesman to. Use an adjacency list to represent the graph.


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int timeStep = 0;

void dfsOriginal(vector<vector<int>>& graph, vector<int>& visited, stack<int>& completed, int index) {
    timeStep++;
    visited[index] = timeStep;
    for (size_t i = 0; i < graph[index].size(); i++) {
        if (visited[graph[index][i]] == 0) {
            dfsOriginal(graph, visited, completed, graph[index][i]);
        }
    }
    completed.push(index);
}

void dfsReversed(vector<vector<int>>& graph, vector<int>& visited, int index) {
    timeStep++;
    visited[index] = timeStep;
    for (size_t i = 0; i < graph[index].size(); i++) {
        if (visited[graph[index][i]] == 0) {
            dfsReversed(graph, visited, graph[index][i]);
        }
    }
}

int main() {
    int N;
    int M;  
    int result = 0;
    
    cin >> N >> M;
    
    int data1;
    int data2;
    vector<vector<int>> graph(N);
    for (int i = 0; i < M; i++) {
        cin >> data1 >> data2;
        graph[data1].push_back(data2);
    }

    vector<int> visited(N, 0);
    stack<int> completed;

    for (int i = 0; i < N; i++) {
        if (visited[i] == 0) {
            dfsOriginal(graph, visited, completed, i);
        }
    }
    
    vector<vector<int>> reversedGraph(N);
    for (int i = 0; i < N; i++) {
        for (size_t j = 0; j < graph[i].size(); j++) {
            reversedGraph[graph[i][j]].push_back(i);
        }
    }
    
    vector<int> visitedReversed(N, 0);
    while (!completed.empty()) {
        int node = completed.top();
        completed.pop();
        if (visitedReversed[node] == 0) {
            dfsReversed(reversedGraph, visitedReversed, node);
            result++;
        }
    }

    cout << result << endl;
    return 0;
}
