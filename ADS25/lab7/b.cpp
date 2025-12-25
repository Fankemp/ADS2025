#include<iostream>
#include<vector>

using namespace std;



void mergeSort(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp;
    int i = left;
    int j = mid + 1;

    while(i <= mid && j <= right) {
        if(arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
        }
    }

    while(i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }

    while(j <= right) {
        temp.push_back(arr[j]);
        j++;
    }

    for(int k = 0; k < temp.size(); k++) {
        arr[k + left] = temp[k];
    }

}


void merge(vector<int>& arr, int left, int right) {
    if(left >= right) return;

    int mid = left + (right - left) / 2;
    merge(arr, left, mid);
    merge(arr, mid + 1, right);
    mergeSort(arr, left, mid, right);

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

    int num;
    cin >> num;

    for(int i = 0; i < num; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    merge(arr, 0, arr.size() - 1);

    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
}