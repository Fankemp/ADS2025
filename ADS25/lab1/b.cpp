#include<iostream>
#include<algorithm>
#include<stack>

using namespace std;


int main() {
    int n;
    cin >> n;
    
    stack<int> st;
    for (int i = 0; i < n; ++i) {
        int x; 
        cin >> x;

        while (!st.empty() && st.top() > x)  {
            st.pop();
        }

        if (i) cout << ' ';  
        if (st.empty()) cout << -1;
        else            cout << st.top();

        st.push(x);
    }
    cout << '\n';
    return 0;
}