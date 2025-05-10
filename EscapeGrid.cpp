// A player is required to escape the grid by going from the top row to the bottom row through a minimum path.
// A path can start from any cell on the top row, going down until any cell on the bottom row,
// on the condition that no two cells chosen in adjacent rows are in the same column.



#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

vector<vector<int>> dp;

int minimumEscapePath(vector<vector<int>> grid, int n, int index, int lastRow) {
    if (index >= n)
        return 0;
    
    int minCost = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (i != lastRow) {
            if (dp[index][i] == -1) 
                dp[index][i] = minimumEscapePath(grid, n, index+1, i) + grid[index][i];
            minCost = min(minCost, dp[index][i]);
        }
    }
    return minCost;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n,0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j ++) {
            cin >> grid[i][j];
        }
    }
    
    dp.resize(n, vector<int>(n, -1));
    
    cout << minimumEscapePath(grid, n, 0, -1);
    
    return 0;
}
