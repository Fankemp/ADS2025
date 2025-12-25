#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void buildBalancedArray(vector<int>& arr, vector<int>& result, int left, int right) {
    if (left > right) return;
    
    int mid = (left + right) / 2;
    result.push_back(arr[mid]);
    
    buildBalancedArray(arr, result, left, mid - 1);
    buildBalancedArray(arr, result, mid + 1, right);
}

int main() {
    int N;
    cin >> N;
    int size = (1 << N) - 1;

    vector<int> arr(size);
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    
    sort(arr.begin(), arr.end());

    vector<int> result;
    buildBalancedArray(arr, result, 0, size - 1);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
