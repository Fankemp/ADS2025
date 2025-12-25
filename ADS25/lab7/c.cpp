#include<iostream>
#include<vector>
#include<map>

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

    merge(arr,left, mid);
    merge(arr, mid + 1, right);
    mergeSort(arr, left, mid, right);

}


int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n), arr2(m);
    
    for(int i = 0; i < n; i++) {
       cin >> arr[i];
    }

    for(int i = 0; i < m; i++) {
       cin >> arr2[i];
    }

    map<int, int> comm;
    for(int x: arr) {
        comm[x]++;
    }   

    vector<int> res;
    for(int x: arr2) {
        if(comm[x] > 0) {
            comm[x]--;
            res.push_back(x);
        }
    }

    merge(res, 0, res.size() - 1);


    for(int i = 0; i < res.size();i++) {
        cout << res[i] << " ";
    }


}