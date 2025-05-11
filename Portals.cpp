// You are playing a game as a wizard, who is currently staying in your home city.
// You have the ability to teleport to other cities using hidden portals. 
// Each portal consumes a certain amount of health. There can be multiple portals between two cities in the same direction. 
// Your goal is to find the minimum amount of health needed to reach the furthest city and the number of reachable cities. 
// Given N cities and M portals, find the number of reachable cities and the minimum amount of health required to visit the furthest city.
// You are starting in city with index S. Use an adjacency list to represent the graph.



#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
#include <queue>
using namespace std;


int main() {
    int N;
    int M; 
    int S;
    
    cin >> N >> M >> S;
    
    int data1;
    int data2;
    int data3;
    vector<vector<pair<int, int>>> graph(N);
    for (int i = 0; i < M; i++) {
        cin >> data1 >> data2 >> data3;
        graph[data1].push_back({data2, data3});
    }

    vector<int> distances(N, INT_MAX);    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> queue;
    
    distances[S] = 0;
    queue.push({distances[S], S});
    
    while (!queue.empty()) {
        int u = queue.top().second;
        int uDistance = queue.top().first;
        queue.pop();
        
        for (size_t i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i].first;
            int w = graph[u][i].second;
            if (distances[v] > uDistance + w) {
                distances[v] = uDistance + w;
                queue.push({distances[v], v});
            }
        }
    }
    
    int count = 0;
    int maxDistance = INT_MIN;
    for (int i = 0; i < N; i++) {
        if (distances[i] != INT_MAX) {
            maxDistance = max(maxDistance, distances[i]);
            count++;
        }
    }
    
    cout << count << " " << maxDistance;
    return 0;
}
