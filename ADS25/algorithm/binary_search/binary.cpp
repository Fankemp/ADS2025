#include<iostream>
#include<vector>
using namespace std;


int binSearch(vector<int> arr, int n, int x) {
    int left = 0;
    int right = n - 1;

    while(left <= right) {
        int mid = left + (right - left) / 2;

        if(arr[mid] == x) {
            return mid;
        } else if(arr[mid] < x) {
            left = mid + 1;
        } else if(arr[mid] > x) {
            right = mid - 1;
        }
    }
    return -1;
}




int main() {
    int n;
    cin >> n;
    vector<int> arr;


    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }

}