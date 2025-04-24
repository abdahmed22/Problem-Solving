// You are given an integer n representing the number of steps to reach the top of a staircase. 
// You can climb with either 1 or 2 steps at a time.
// Return the number of distinct ways to climb to the top of the staircase.


#include <iostream>
#include <vector>

using namespace std;

vector<int> dp;

int climbStairsRecursion(int n) {
    if (n == 0) 
        return 1;
    if (n < 0)
        return 0;
    
    if (dp[n] != -1)
        return dp[n];

    return dp[n] = climbStairsRecursion(n - 1) + climbStairsRecursion(n - 2);
}

int climbStairs(int n) {
    dp.resize(n + 1, -1);
    return climbStairsRecursion(n);
}

int main() {
    int n;
    cin >> n;

    int ways = climbStairs(n);
    cout << ways << endl;

    return 0;
}
