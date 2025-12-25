#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

bool canDivide(const vector<long long>& ghouls, long long k, long long maxSum) {
    long long blocks = 1;
    long long currentSum = 0;
    
    for (long long num : ghouls) {
        if (currentSum + num > maxSum) {
            blocks++;
            currentSum = num;
            if (blocks > k) return false;
        } else {
            currentSum += num;
        }
    }
    return blocks <= k;
}

int main() {
    long long n, k;
    cin >> n >> k;
    
    vector<long long> ghouls(n);
    long long maxElement = 0;
    long long totalSum = 0;
    
    for (long long i = 0; i < n; i++) {
        cin >> ghouls[i];
        maxElement = max(maxElement, ghouls[i]);
        totalSum += ghouls[i];
    }
    
    long long left = maxElement;
    long long right = totalSum;
    long long answer = totalSum;
    
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        
        if (canDivide(ghouls, k, mid)) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    cout << answer << endl;
    
    return 0;
}