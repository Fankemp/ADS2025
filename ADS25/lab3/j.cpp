#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool canRob( vector<ll>& arr, int c, ll f){
    ll sum = 0;
    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i]/c;
        if (arr[i] % c != 0){
            sum++;
        }
        if (sum > f){
            return false;
        }
    }
    return true;
}

int main(){
    int n;
    ll h;
    cin >> n >> h;
    vector<ll> arr(n);

    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int max = arr[0];
    for (int i = 1; i < n; i++){
        if (max < arr[i]){
            max = arr[i];
        }
    }

    int l = 1, r = max, ans = max;
    while (l <= r){
        int mid = l + (r-l)/2;
        if (canRob(arr, mid, h)){
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ans << "\n";
    return 0;
}