#include<iostream>
#include<vector>

using namespace std;

int sumOfArr(vector<int> arr) {
    int sum = 0;
    for(int x: arr) sum+=x;
    return sum;
}

bool isGreater(vector<int> a, vector<int> b) {
    int sumA = sumOfArr(a);
    int sumB = sumOfArr(b);

    if(sumA > sumB) return true;
    if(sumA < sumB) return false;

    for(int i = 0; i < a.size(); i++) {
        if(a[i] < b[i]) return true;
        if(a[i] > b[i]) return false;
    }
    return false;
}


void mergeSort(vector<vector<int>>& arr, int left, int mid, int right) {
    vector<vector<int>> temp;
    int i = left;
    int j = mid + 1;

    while(i <= mid && j <= right) {
        if(isGreater(arr[i], arr[j])) {
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



void merge(vector<vector<int>>& arr, int left, int right) {
    if(left >= right) return;
    int mid = left + (right - left) / 2;
    
    merge(arr, left, mid);
    merge(arr, mid + 1, right);
    mergeSort(arr, left, mid, right);
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(m));
    
    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
         }
    }

    merge(arr, 0, arr.size() - 1);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}