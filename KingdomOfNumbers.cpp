// In the Kingdom of Numbers, a wise mathematician wanted to form the largest possible group of numbers where every pair respected each other—meaning one had to be a multiple of the other.

// such that every pair (A, B) of numbers in this group satisfies:

// A % B == 0, or B % A == 0

// If there are multiple solutions, return any of them.

// Given a set of numbers, can you help him find the longest valid group?


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int validGroup(vector<int> group) {
    for (size_t i = 0; i < group.size(); i++) {
        for (size_t j = 0; j < group.size(); j++) {
            if (group[i] % group[j] != 0 && group[j] % group[i] != 0)
                return 0;
        }        
    }
    return 1;
}

int main() {
    int N;
    vector<int> nums;
    vector<int> result;
    vector<int> currentGroup;
    vector<int> tempGroup;
    
    cin >> N;
    
    int num;
    for (int i = 0; i < N; i++){
        cin >> num;
        nums.push_back(num);
    }

    for (int i = 0; i < N; i++) {
        currentGroup.clear();
        for (int j = i; j < N; j++) {
            tempGroup = currentGroup;
            tempGroup.push_back(nums[j]);

            if (validGroup(tempGroup) == 1) {
                currentGroup.push_back(nums[j]);
            }
        }
        
        if (currentGroup.size() >= result.size()) {
            result = currentGroup;
        }
    }

    for (size_t i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }


    
    return 0;
}

