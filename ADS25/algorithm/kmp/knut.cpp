#include<iostream>
#include<vector>
#include<string>
using namespace std;



vector<int> prefixFunction(string& pattern) {
    int m = pattern.size();
    vector<int> pi(m, 0);
    int j = 0;

    for(int i = 1; i < m; i++) {
        while(j > 0 && pattern[i] != pattern[j]) {
            j = pi[j - 1];
        }

        if(pattern[i] == pattern[j]) {
            j++;
        }

        pi[i] = j;
    }

    return pi;
}


int KMP_Search(string& text, string& pattern) {
    int n = text.size();
    int m = pattern.size();
    vector<int> pi = prefixFunction(pattern);

    int j = 0;
    for(int i = 0; i < n; i++) {
        while(j > 0 && text[i] != pattern[j]) {
            j = pi[j - 1];
        }

        if(text[i] == pattern[j]) {
            j++;
        }

        if(j == m) {
            return i - m + 1;
        }
    }

    return -1;
}










