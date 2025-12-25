#include<iostream>
#include<vector>

using namespace std;


void quickSort(vector<int>& arr, int low, int high) {
    if(low < high) {
        int pivot = arr[high];
        int ind = low - 1;

        for(int j = low; j < high; j++) {
            if(arr[j] >= pivot) {
                ind++;
                swap(arr[ind], arr[j]);
            }
        }

        swap(arr[ind + 1], arr[high]);

        int pivotIndex = ind + 1;

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}


int main() {
    int n1, n2;
    cin >> n1 >> n2;

    vector<vector<int>> arr(n1, vector<int>(n2));

    for(int i = 0; i < n1; i++) {
        for(int j = 0; j < n2; j++) {
            int x;
            cin >> x;
            arr[i][j] = x;
        }
    }

    int low = 0;
    int high = arr.size() - 1;

    
    for(int i = 0; i < n2; i++) {
        vector<int> temp(n1);

        for(int j = 0; j < n1; j++) {
            temp[j] = arr[j][i];
        }
        quickSort(temp, low, high);

        for(int k = 0; k < n1; k++) {
            arr[k][i] = temp[k];
        }
    }

    for(int i = 0; i < n1; i++) {
        for(int j = 0; j < n2; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

}