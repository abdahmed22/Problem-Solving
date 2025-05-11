// Imagine you're on a treasure hunt where you've found a line of treasure chests.
// Each chest contains a certain amount of gold coins. 
// However, there's a rule: if you open one chest, 
// you cannot open the chest immediately next to it because they are magically linked and will disappear if their neighbors are touched. 
// Your goal is to collect the maximum amount of gold coins, choosing wisely which chests to open.



#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

vector<int> dp;

int maximumCoins(vector<int>& chests, int N, int index) {
    if (index >= N) 
        return 0;
    
    if (dp[index] != -1) {
        return dp[index];
    }
    
    return dp[index] = max(maximumCoins(chests, N, index + 1), maximumCoins(chests, N, index + 2) + chests[index]);
}

int main() {
    int N;
    vector<int> chests;
        
    cin >> N;
    
    int chest;
    for (int i = 0; i < N; i++) {
        cin >> chest;
        chests.push_back(chest);
    }
    
    dp.resize(N,-1);
    
    cout << maximumCoins(chests, N, 0);
    return 0;
}
