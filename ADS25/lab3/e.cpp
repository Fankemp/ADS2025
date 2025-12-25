#include <iostream>
#include <algorithm>

int main() {
    int n;
    int k;
    std::cin >> n >> k;

    int arr[n];
    for(int i = 0; i < n; i++) {
        int p[4];
        for(int j = 0; j < 4; j++)    
            std::cin >> p[j];

        arr[i] = std::max(p[2], p[3]);
    }

    std::sort(arr, arr + n);
    std::cout << arr[k - 1];
}