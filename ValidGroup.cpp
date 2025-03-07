#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool validGroup(vector<int> group) {
    for (size_t i = 0; i < group.size(); i++) {
        for (size_t j = 0; j < group.size(); j++) {
            if (group[i] % group[j] != 0 && group[j] % group[i] != 0)
                return false;
        }        
    }
    return true;
}

int main() {
    int N;
    vector<int> nums;
    vector<int> result;
    vector<int> currentGroup;
    
    cin >> N;
    
    int num;
    for (int i = 0; i < N; i++){
        cin >> num;
        nums.push_back(num);
    }
    
 
    for (int i = 0; i < N; i++) {
        currentGroup.push_back(nums[i]);
        for (int j = 0; j < N; j++) {
            if (i == j) {
                continue;
            }
            currentGroup.push_back(nums[j]);
        }
        if (currentGroup.size() > result.size() && validGroup(currentGroup)) {
            result = currentGroup;
        }
        currentGroup.clear();
    }
    
    for (size_t i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }


    
    return 0;
}
