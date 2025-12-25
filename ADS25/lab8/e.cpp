#include<iostream>
#include<vector>
#include <cmath>

using namespace std;

char restore_char(long long diff, int power) {
    diff = diff / (long long) pow(2,power);
    return char(diff + 97);
}



string restore_string(int n, vector<long long>& hash) {
    string result(n, ' ');
    result[0] = char(hash[0] + 97);

    for(int i = 1; i < n; i++) {
        long long diff = hash[i] - hash[i - 1];
        result[i] = restore_char(diff, i);
    }
    
    return result;
}


int main() {
    int n;
    cin >> n;

    vector<long long> hash(n);
    for(int i = 0; i < n; i++) {
        cin >> hash[i];
    }

    string res = restore_string(n, hash);
    cout << res;
}