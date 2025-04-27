// A brave explorer is venturing through an ancient dungeon filled with treasure chests. 
// However, and the explorer cannot open two consecutive chests it will curse the dungon for being too greedy. 
// The task is to determine the maximum amount of treasure that can be collected without triggering any traps.



#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

vector<long long int> dp;

long long int Collect(vector<int> &T, size_t index) {
    if (index >= T.size())
        return 0;
    
    if (dp[index] != -1) 
        return dp[index];
    
    long long int maxCoins = INT_MIN;
    maxCoins = max(maxCoins, Collect(T, index+ 2) + T[index]);
    maxCoins = max(maxCoins, Collect(T, index+1));

    return dp[index] = maxCoins;     
}

int main() {
    int N;
    cin >> N;
    
    vector<int> T(N);
    for (int i = 0; i < N; i++) {
        cin >> T[i];
    }
    
    dp.resize(N, -1);
    
    cout << Collect(T, 0) << endl;

}
