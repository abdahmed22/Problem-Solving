// You are given an array of integers cost where cost[i] is the cost of taking a step from the ith floor of a staircase.
// After paying the cost, you can step to either the (i + 1)th floor or the (i + 2)th floor.
// You may choose to start at the index 0 or the index 1 floor.
// Return the minimum cost to reach the top of the staircase, i.e. just past the last index in cost.



#include <iostream>
#include <vector>

using namespace std;

vector<int> dp;

int minCostClimbingStairsRecursion(vector<int>& cost, int top, int index) {
    if (index >= top)
        return 0;

    if (dp[index] != -1)
        return dp[index];

    return dp[index] = cost[index] + min(
        minCostClimbingStairsRecursion(cost, top, index + 1),
        minCostClimbingStairsRecursion(cost, top, index + 2)
    );
}

int minCostClimbingStairs(vector<int>& cost) {
    dp.resize(cost.size() + 1, -1);
    return min(
        minCostClimbingStairsRecursion(cost, cost.size(), 0),
        minCostClimbingStairsRecursion(cost, cost.size(), 1)
    );
}

int main() {
    int n;
    cin >> n;

    vector<int> cost(n);
    for (int i = 0; i < n; ++i) {
        cin >> cost[i];
    }

    int result = minCostClimbingStairs(cost);
    cout << result << endl;

    return 0;
}
