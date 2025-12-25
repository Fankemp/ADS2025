#include<iostream>
#include<vector>

using namespace std;


void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        int pivotIndex = i + 1;

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}


int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr[i] = x;
    }

    int s = arr.size();
    quickSort(arr, 0, s - 1);

    int mindif = 1000000;

    for(int i = 1; i < n; i++) {
        int diff = arr[i] - arr[ i - 1];

        if(mindif > diff) {
            mindif = diff;
        }
    }

     for (int i = 1; i < n; i++) {
        if (arr[i] - arr[i - 1] == mindif) {
            cout << arr[i - 1] << " " << arr[i] << " ";
        }
    }

}