// You are playing a game and you are given a collection of coins of size N where each coin has a value in pounds as an array of positive integers A[0...N-1].
// You find a mission that requires you to collect exactly a total value of T pounds.
// Is it possible to take coins from A that sums to exactly T? You are required to answer the question above using non-optimized brute force solution.

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


void collectCoins(vector<int> nums, vector<bool> isUsed,int N,int T, int sum, int& result, int index) {
    if (T == sum) {
        result = 1;
    }

    if (result == 1 || N == index || sum > T) {
        return;
    }
        
    for(int i = 0; i < N; i++) {
        if (isUsed[i] == false) {
            isUsed[i] = true;
            collectCoins(nums, isUsed, N, T, sum + nums[i], result, index + 1);
            isUsed[i] = false;
        }
    }
    
}

int main() {
    int T;
    int result = 0;
    int N;
    
    cin >> T;
    cin >> N;
    
    vector<int> A(N);
    vector<bool> isUsed (N, false);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    collectCoins(A, isUsed, N, T, 0, result, 0);
    
    cout << result;
    return 0;
}


