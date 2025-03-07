// You are given an array A of N integers and an integer K. 
// Your task is to find the maximum sum of any contiguous subarray of length K using a brute force approach.

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N;
    int K;
    int currentSum;
    int currentValues;
    int result = INT32_MIN;
    vector<int> nums;
    
    cin >> N;
    cin >> K;
    
    int num;
    for (int i = 0; i < N; i++){
        cin >> num;
        nums.push_back(num);
    }
    
 
    for (int i = 0; i < N; i++) {
        currentValues = 0;
        currentSum = 0;
        for (int j = i; j < N; j++) {
            currentValues ++;
            currentSum += nums[j];  
            
            if (currentValues == K) {
                if (currentSum > result) {
                    result = currentSum;
                }
                break;
            }
        }    
    }
    
    cout << result;
    
    return 0;
}

