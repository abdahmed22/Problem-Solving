// Imagine a hero who is stuck in a big maze that looks like a huge square. 
// This maze is divided into smaller squares, making a grid of N by N squares. 
// The hero starts in one square at a point (x, y). 
// The hero needs to find his way out using no more than K moves. 
// There are R different ways he can move (like stepping forward, backward, left, or right).
// The edges of the maze have exits. If the hero steps on any of these exits,
// he escapes from the maze and cannot go back inside. 
// Your task is to figure out how many different ways the hero can escape using his moves.


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<vector<int>> dp;

int escapeMatrix(int N, vector<pair<int, int>> moves, int R, int K, int x, int y) {
    if (x >= N || y >= N || x < 0 || y < 0)
        return 1;
    
    if (K == 0)
        return 0;
    
    if (dp[x][y] != -1)
        return dp[x][y];
    
    int result = 0;
    for (int i = 0; i < R; i++) {
        result += escapeMatrix(N, moves, R, K - 1, x + moves[i].first, y + moves[i].second);
    }
    
    return result;
}

int main() {
    int N;
    int K;
    int R;
    int x;
    int y;
    
    cin >> N >> K >> R >> x >> y;
    
    int X;
    int Y;
    vector<pair<int, int>> moves;
    for (int i = 0; i < R; i++) {
        cin >> X >> Y;
        moves.push_back({X, Y});
    }
    
    dp.resize(N, vector<int>(N, -1));    
    
    cout << escapeMatrix(N, moves, R, K, x, y);
    
    return 0;
}
