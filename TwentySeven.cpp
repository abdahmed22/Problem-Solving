// Given 5 numbers, find out if you can place the arithmetic operators {+, −, ∗} between them to create an arithmetic expression yielding to the value 27.
// Note that you can arrange the number in any arrangement(Hint: use next_permutation) so if the numbers given are 1 2 3 4 5 you can place the operators 1 + 2 + 3 * 4 - 5 or 5 * 2 + 3 - 1 * 4 also consider the +, -, * 
// have the same precedence so just consider the calculation in a sequential way.
// For example here 1 + 2 + 3 * 4 - 5 --> ((((1 + 2) + 3) * 4) - 5) so you will do the first addition and then the second, then the multiplication then the subtraction so don't consider the * to have higher precedence.
// Solve this problem using a recursive brute force solution.

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


string calculate(vector<int> nums, int index, int result, string expression) {
    if ((index == 4) && (result == 27)) {
        return "Possible";
        
    } else if (index == 4) {
        return "Impossible";
    }
    
    index++; 
    string s1 = calculate(nums, index, result + nums[index], expression + "+" + to_string(nums[index]));
    string s2 = calculate(nums, index, result - nums[index], expression + "-" + to_string(nums[index]));
    string s3 = calculate(nums, index, result * nums[index], expression + "*" + to_string(nums[index]));
    
    if (s1 != "Impossible")
        return s1;
    else if (s2 != "Impossible")
        return s2;
    else
        return s3;
}

int main() {
    vector<int> nums;
    int num;
    string output;
    
    for(int i = 0; i < 5; i++) {
        cin >> num;
        nums.push_back(num);
    }
    
    sort(nums.begin(), nums.end());
    
    do {
        output = calculate(nums, 0, nums[0], to_string(nums[0]));
        if (output == "Possible") {
            break;
        }
    } while (next_permutation(nums.begin(), nums.end()));
    
    
    cout << output;
    return 0;
}
