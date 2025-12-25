#include <bits/stdc++.h>
#define ll long long
using namespace std;

int binSearch(const vector<ll>& pref, ll num){
    int l = 0;
    int r = pref.size()-1;
    int ans = r;
    while (l <= r){
        int mid = l + (r - l)/2;
        if (pref[mid] >= num){
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return ans + 1;
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<ll> pref(n);
    for (int i = 0; i < n; i++){
        ll num;
        cin >> num;
        if (i == 0){
            pref[i] = num;
        } else {
            pref[i] = pref[i-1] + num;
        }
    }

    for (int i = 0; i < m; i++){
        ll k;
        cin >> k;
        cout << binSearch(pref, k) << "\n";
    }
    return 0;
}