#include<iostream>
#include<vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int l = 0, ans = n, sum = 0;
    for (int r = 0; r < n; r++){
        sum += arr[r];
        while (sum >= k){
            ans = min(ans, r - l + 1);
            sum -= arr[l];
            l++;
        }
    }
    cout << ans << "\n";
    return 0;
}