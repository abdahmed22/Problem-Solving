// You find yourself in a mystical forest, where you find N enchanted stepping stones scattered along the path.
// You are given a list S representing the maximum length of a forward jump that can be made from each of the enchanted stepping stones.
// Your goal is to navigate through the forest and reach the end by stepping on these magical stones. 
// The challenge is to determine the minimum number of jumps needed to reach the last enchanted stepping stone. 
// Each jump can take you to any stone within the range specified by its magical length.
// Write a function that takes the list of maximum jump values as input and returns the minimum number of jumps needed by using a greedy algorithm.


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;


int Navigate(vector<int> S, int N) {
    int result = 0;
    int i = 0;
    
    if (N == 1) {
        return result;
    }
    
    while (i < N) {
        int maxIndex = i + 1;
        int maxLocation = i + S[i];
        
        if (maxLocation >= N - 1) {
            result++;
            break;
        }

        int bestJump = -1;
        for (int j = i + 1; j <= i + S[i]; j++) {
            if (j >= N)
                break;
            if (j + S[j] > bestJump) {
                bestJump = j + S[j];
                maxIndex = j;
            }

        }
        result ++;
        i = maxIndex;
    }
    
    return result;
}

int main() {
    int N;
    cin >> N;
    
    vector<int> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }
    
    cout << Navigate(S, N) << endl;
    
    
    return 0;
}

