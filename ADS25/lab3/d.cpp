#include <iostream>
#include <algorithm>

int lowerBound(int* arr, int n, int x) {
    int l = 0;
    int r = n;

    while(l < r) {
        int mid = l + (r - l) / 2;
        if(arr[mid] >= x)
            r = mid;     
        else
            l = mid + 1;
    }
    return l;
}

int upperBound(int* arr, int n, int x) {
    int l = 0;
    int r = n;

    while(l < r) {
        int mid = l + (r - l) / 2;
        if(arr[mid] <= x)
            l = mid + 1; 
        else
            r = mid;    
    }
    return l - 1; 
}

int getAnswer(int* arr, int n, int l, int r) {
    return upperBound(arr, n, r) - lowerBound(arr, n, l) + 1;
}

int main() {
    int n;
    int q;
    std::cin >> n >> q;

    int arr[n];
    for(int i = 0; i < n; i++)
        std::cin >> arr[i];
    std::sort(arr, arr + n);

    int l1, r1;
    int l2, r2;
    while(q--) {
        std::cin >> l1 >> r1 >> l2 >> r2;
        int ans = 0;

        if(l1 >= l2 && l1 <= r2) 
            ans = getAnswer(arr, n, std::min(l1, l2), std::max(r1, r2));
        else if(l2 >= l1 && l2 <= r1) 
            ans = getAnswer(arr, n, std::min(l1, l2), std::max(r1, r2));
        else 
            ans = getAnswer(arr, n, l1, r1) + getAnswer(arr, n, l2, r2);
        std::cout << ans << '\n';
    }
}