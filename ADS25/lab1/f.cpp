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

    int count = 0;
    int num = 1;

    while(count < n) {
        ++num;

        if(Prime(num)) {
            ++count;
        }
    }

    cout << num;

}