#include <iostream> 
#include <algorithm>
#include <vector>
#include <cmath>
#include <map> 
#include <set> 
#include <unordered_set> 
#include <queue>
#include <deque>
#include <stack>
#include <climits> 
#define pb push_back
#define pf push_front 
#define p_b pop_back
#define p_f pop_front 
#define vec vector
#define ll long long
using namespace std;

const ll mod = 1e9 + 7; 

string hashFunc(const string &s){ 
    ll h=0, p=1; 
    for(char ch : s){ 
        h = (h+((ch-47)*p)%mod) % mod; 
        p = (p*11)%mod; 
    }
    return to_string(h);
}

int main(){ 
    vec<string> arr; 
    unordered_set<string> ust; 
    int n; cin>>n; 
    for(int i=0; i<n*2; i++){ 
        string s; cin>>s; 
        arr.pb(s); 
        ust.insert(s); 
    }
    int cnt = 0; 
    for(int i=0; i<arr.size(); i++){ 
        if(cnt==n) break; 
        string hs = hashFunc(arr[i]); 
        if(ust.find(hs)!= ust.end()){ 
            cout << "Hash of string \"" << arr[i] << "\"" << " is " << hs << endl;
            cnt++;
        }
    }
}