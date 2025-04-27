// You are an adventurer exploring a long corridor filled with treasure chests. Each chest has two attributes:
// Gold Value: The amount of gold you can collect if you open this chest.
// Trap Radius: If you open this chest, a trap is triggered that destroys a number of chests to its right, making them inaccessible.
// For each chest, you must decide whether to open it or skip it.
// Goal:
// Maximize the total gold you can collect by strategically opening chests, considering that opening a chest will also destroy several chests to its right.

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

vector<long long int> dp;

long long int Collect(vector<int> &T, vector<int> &G, size_t index) {
    if (index >= T.size())
        return 0;
    
    if (dp[index] != -1) 
        return dp[index];
    
    long long int maxCoins = INT_MIN;
    maxCoins = max(maxCoins, Collect(T, G, index+ 1 + G[index]) + T[index]);
    maxCoins = max(maxCoins, Collect(T, G, index+1));

    return dp[index] = maxCoins;     
}

int main() {
    int N;
    cin >> N;
    
    vector<int> G(N);
    vector<int> T(N);
    for (int i = 0; i < N; i++) {
        cin >> G[i] >> T[i];
    }
    
    dp.resize(N, -1);
    
    cout << Collect(G, T, 0) << endl;

}
