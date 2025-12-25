#include <iostream>
#include <vector>

using namespace std;

void quickSort(vector<char>& v, int low, int high) {
    if (low < high) {
        int pivot = v[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (v[j] < pivot) {
                i++;
                swap(v[i], v[j]);
            }
        }
        swap(v[i + 1], v[high]);

        int pivotIndex = i + 1;

        quickSort(v, low, pivotIndex - 1);
        quickSort(v, pivotIndex + 1, high);
    }
}

int main() {
    int n;
    cin >> n;
    
    string s;
    cin >> s;

    string vowels = "aeiou";
    vector<char> vowel_ch;
    vector<char> cons;

    for (char c : s) {
        if (vowels.find(c) != string::npos) {
            vowel_ch.push_back(c);
        } else {
            cons.push_back(c);
        }
    }

    quickSort(vowel_ch, 0, vowel_ch.size() - 1);
    quickSort(cons, 0, cons.size() - 1);

    for (char c : vowel_ch) {
        cout << c;
    }
    for (char c : cons) {
        cout << c;
    }

    cout << endl;
    return 0;
}

