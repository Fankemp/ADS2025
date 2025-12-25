#include<iostream>
#include<deque>
#include<algorithm>

using namespace std;



int main() {
    deque<int> deq;
    while(true) {
        char ch;
        cin >> ch;

        if(ch == '+') {
            int n;
            cin >> n;
            deq.push_front(n);
        }

        if(ch == '-') {
            int n2;
            cin >> n2;
            deq.push_back(n2);
        }

        if(ch == '*') {
            int sum;

            if(deq.empty()) {
                cout << "error" << endl;
                continue;
            }

            if(deq.size() != 1) {
                 sum = deq.front() + deq.back();
                 cout << sum << endl;

                deq.pop_back();
                deq.pop_front();
            } else {
                cout << deq.front() + deq.back() << endl;
                deq.pop_back();
            }
        }

        if(ch == '!') {
            return 0;
        }

        
    }
}