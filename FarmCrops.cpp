// You are managing a farm where you track the daily prices of different crops for N days. 
// You are given a list P containing the price of the crop on each of the N days.
// Your goal is to maximize profit by strategically planting and harvesting crops. 
// However, there's a practical constraint: after harvesting a crop, you need to let the field rest for a day before planting a new crop.
// Write a function that takes the list of prices as input and returns the maximum total profit by using a dynamic programming algorithm.



#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

vector<vector<int>> dp;

int Farm(vector<int> &P, int yesterday, int index) {   // 1: rest  2: plant  3: harvest
    if (index >= P.size())
        return 0;
    
    if (dp[index][yesterday-1] != -1) 
        return dp[index][yesterday-1];
    
    int maxProfit = INT_MIN;
    if (yesterday == 1) {                                                // after rest
        maxProfit = max(maxProfit, Farm(P, 1, index+1));                 // rest
        maxProfit = max(maxProfit, Farm(P, 2, index+1) - P[index]);      // plant
    } else if (yesterday == 2) {                                         // after plant
        maxProfit = max(maxProfit, Farm(P, 2, index+1));                 // hold
        maxProfit = max(maxProfit, Farm(P, 3, index+1) + P[index]);      // harvest
    } else {                                                             // after harvest
        maxProfit = Farm(P, 1, index+1);                                 // must rest
    }
    
    return dp[index][yesterday-1] = maxProfit;     
}

int main() {
    int N;
    cin >> N;
    
    vector<int> P(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }
    
    dp.resize(N, vector<int>(3, -1));

    cout << Farm(P, 1, 0) << endl;

}
