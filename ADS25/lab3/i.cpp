#include<iostream>
#include<vector>

using namespace std;

int binarySearch(vector<int> arr, int x) {
    int left = 0;
    int right = arr.size() - 1;

    while(left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == x) {
            return arr[mid];  
        }
        
        if(arr[mid] > x) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return 0;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int x;
    cin >> x;
    int s = binarySearch(arr, x);

    if(s == x) {
        cout << "Yes";
    } else {
        cout << "No";
    }
}