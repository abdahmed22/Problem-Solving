// You have a staircase of N steps, each bearing an integer weight.
// You start just befoe step 1, with total score of 0, and much reach just beyond step N.
// At each move you may:
// Climb 1 step: gaining wi+1
// Climb 2 step: gaining wi+2
// Jump 3 step: gaining wi+3, but you can use at most K jumps in total.
// Compute the maximum total score upon reaching beyond step N.


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

vector<vector<long long int>> dp;

long long int maximumScore(vector<long long int>& staircase, int N, int index, int K) {
    if (index >= N) 
        return 0;
    
    if (dp[index][K] != INT_MIN)
        return dp[index][K];
    
    long long int maxScore = INT_MIN;

    maxScore = max(maxScore, maximumScore(staircase, N, index + 1, K) + staircase[index + 1]);
    
    maxScore = max(maxScore, maximumScore(staircase, N, index + 2, K) + staircase[index + 2]);
    
    if (K > 0)
        maxScore = max(maxScore, maximumScore(staircase, N, index + 3, K - 1) + staircase[index + 3]);

    return dp[index][K] = maxScore;
}

int main() {
    int N;
    int K;
    cin >> N >> K;
    
    vector<long long int> staircase;
    staircase.push_back(0);
    long long int step;
    for (int i = 0; i < N; i++) {
        cin >> step;
        staircase.push_back(step);
    }
    staircase.push_back(0);

    dp.resize(N + 2, vector<long long int>(10, INT_MIN));
    
    cout << maximumScore(staircase, N, 0, K);
    
    return 0;
}
