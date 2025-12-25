#include<iostream>
#include<algorithm>
using namespace std;




bool Prime(int n) {
    if(n < 2) return false;
    if(n % 2 == 0) return n==2;

    for(int d = 3; d * d <= n; d+=2) {
        if(n % d == 0) return false;
    }

    return true;

    

}

int main() {
    int n;
    cin >> n;

    if(Prime(n)) {
        cout << "YES";
    } else {
        cout << "NO";
    }

}