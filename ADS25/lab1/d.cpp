#include<iostream>
#include<stack>
#include<algorithm>

using namespace std;

int main() {
    string str;
    cin >> str;

    stack<char> st;
    for(char c : str) {
        if(!st.empty() && st.top() == c) {
            st.pop();
        } else {
            st.push(c);
        }   
    }

    if(st.empty()) cout << "YES";
    else cout << "NO"; 

}