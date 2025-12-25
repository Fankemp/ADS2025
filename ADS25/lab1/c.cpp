#include<iostream>
#include <stack>
#include <string>
#include<queue>
#include<algorithm>

using namespace std;

string biuld(string& s) {
    stack<char> st;
    for( char c : s) {
        if( c == '#') {
            st.pop();
        }
        else {
            st.push(c);
        }
    }

    string res;

    while(!st.empty()) {
        res.push_back(st.top());
        st.pop();
    }

    reverse(res.begin(), res.end());

    return res;


}




int main() {
    string s1, s2;
    cin >> s1 >> s2;

    if(biuld(s1) == biuld(s2)) {
        cout << "Yes";
    } else {
        cout << "No";
    }

}