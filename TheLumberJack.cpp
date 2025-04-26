// Elias, a skilled lumberjack, has a long log divided into N sections connected seamlessly. 
// Certain positions on the log, listed in a sorted array L, are marked for cuts. 
// The challenge is to determine the most efficient order of cuts to minimize the total effort.
// Each cut divides the log into two smaller sections, and the cost of making a cut is equal to the length of the section being cut. 
// Elias must decide the sequence of cuts that minimizes the overall effort.
// Your answer should be the minimum effort required to cut the log.
// Assume: position 1 is between the first and second sections.
// You are required to solve this problem using dynamic programming


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
#include <map>
using namespace std;

vector<vector<int>> dp;

int Lumber(const vector<int>& L, int M, int N) {
    if (N - M <= 1)
        return 0;
    
    if (dp[M][N] != -1)
        return dp[M][N];

    int left;
    int right;
    int minEffort = INT_MAX;
    for (int i = M + 1; i < N; i++) {
        left = Lumber(L, M, i);
        right = Lumber(L, i, N);
        minEffort = min(minEffort, left + right + L[N] - L[M]);
    }
    return dp[M][N] = minEffort;
}

int main() {
    int N;
    int M;
    cin >> N;
    cin >> M;
    
    vector<int> L(M);
    L.push_back(0);
    for (int i = 1; i < M + 1; i++) {
        cin >> L[i];
    }
    L.push_back(N);
    
    dp.resize(L.size());
    for (size_t i = 0; i < L.size(); i++) {
        dp[i].resize(L.size(), -1);
    }
    
    
    cout << Lumber(L, 0, L.size() - 1) << endl;
    
    
    return 0;
}
