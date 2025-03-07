// You are required to output all the binary strings with length N and have excatly H ones in a lexicographical order.

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void printStrings(int N,int H,string binaryString, int ones) {
    if ((static_cast<int>(binaryString.size()) == N) && (ones == H)) {
        cout << binaryString << endl;
        return;
    } else if (static_cast<int>(binaryString.size()) == N) {
        return;
    }
    
    printStrings(N, H, binaryString + "0", ones);
    printStrings(N, H, binaryString + "1", ones + 1);
}

int main() {
    int N;
    int H;
    cin >> N >> H;

    printStrings(N, H, "", 0);
    
    return 0;
}
