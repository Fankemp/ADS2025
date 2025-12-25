#include<iostream>
#include<stack>
#include<queue>
#include<algorithm>

using namespace std;

bool Zero(int b, int n) {
    if(b == 0 && n == 9) return true;
    else if(b == 9 && n == 0) return false;
    return b > n;

}



int main() {
    queue<int> boris, nursik;

    for(int i = 0; i < 10; i++) {
        int n;
        if(i < 5) {
            cin >> n;
            boris.push(n);
        } else {
            cin >> n;
            nursik.push(n);
        }
    }

    int move = 0;
    while(!boris.empty() && !nursik.empty()) {
        move++;
        if(Zero(boris.front(), nursik.front())) {
            boris.push(boris.front()); boris.push(nursik.front());
            boris.pop(); nursik.pop();
        } else {
            nursik.push(boris.front()); nursik.push(nursik.front());
            boris.pop(); nursik.pop();
        }
    }

    if(boris.empty()) {
        cout << "Nursik " << move;
    } else if(nursik.empty()) {
        cout << "Boris " << move;
    }


}