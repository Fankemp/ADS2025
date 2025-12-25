#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canDeliver(int capacity, const vector<int>& children, int maxFlights) {
    int flights = 0;
    for (int childrenCount : children) {
        flights += (childrenCount + capacity - 1) / capacity;
    }
    return flights <= maxFlights;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> children(n);
    for (int i = 0; i < n; i++) {
        cin >> children[i];
    }

    int left = 1, right = *max_element(children.begin(), children.end());
    int answer = right;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (canDeliver(mid, children, k)) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << answer << endl;

    return 0;
}
