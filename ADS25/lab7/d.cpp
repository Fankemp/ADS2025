#include <iostream>
#include <vector>
#include <map>
#include <iomanip>
using namespace std;

// ====== глобальная таблица оценок ======
map<string, double> gpaScale = {
    {"A+", 4.00}, {"A", 3.75}, {"B+", 3.50}, {"B", 3.00},
    {"C+", 2.50}, {"C", 2.00}, {"D+", 1.50}, {"D", 1.00}, {"F", 0.00}
};

// ====== функция вычисления GPA ======
double calcGPA(int k) {
    double total = 0, credits = 0;
    for (int i = 0; i < k; i++) {
        string mark;
        int c;
        cin >> mark >> c;
        total += gpaScale[mark] * c;
        credits += c;
    }
    return total / credits;
}

// ====== merge-функции для сортировки ======
void merge(vector<string>& last, vector<string>& first, vector<double>& gpa, int left, int mid, int right) {
    int i = left, j = mid + 1;
    vector<string> tempLast, tempFirst;
    vector<double> tempGPA;

    while (i <= mid && j <= right) {
        bool takeLeft = false;
        if (gpa[i] < gpa[j]) takeLeft = true;
        else if (gpa[i] == gpa[j]) {
            if (last[i] < last[j]) takeLeft = true;
            else if (last[i] == last[j] && first[i] < first[j]) takeLeft = true;
        }

        if (takeLeft) {
            tempLast.push_back(last[i]);
            tempFirst.push_back(first[i]);
            tempGPA.push_back(gpa[i]);
            i++;
        } else {
            tempLast.push_back(last[j]);
            tempFirst.push_back(first[j]);
            tempGPA.push_back(gpa[j]);
            j++;
        }
    }

    while (i <= mid) {
        tempLast.push_back(last[i]);
        tempFirst.push_back(first[i]);
        tempGPA.push_back(gpa[i]);
        i++;
    }
    while (j <= right) {
        tempLast.push_back(last[j]);
        tempFirst.push_back(first[j]);
        tempGPA.push_back(gpa[j]);
        j++;
    }

    for (int k = 0; k < tempGPA.size(); k++) {
        last[left + k] = tempLast[k];
        first[left + k] = tempFirst[k];
        gpa[left + k] = tempGPA[k];
    }
}

void mergeSort(vector<string>& last, vector<string>& first, vector<double>& gpa, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(last, first, gpa, left, mid);
    mergeSort(last, first, gpa, mid + 1, right);
    merge(last, first, gpa, left, mid, right);
}

// ====== main ======
int main() {
    int n;
    cin >> n;

    vector<string> last(n), first(n);
    vector<double> gpa(n);

    for (int i = 0; i < n; i++) {
        int k;
        cin >> last[i] >> first[i] >> k;
        gpa[i] = calcGPA(k);
    }

    if (n > 0)
        mergeSort(last, first, gpa, 0, n - 1);

    cout << fixed << setprecision(3);
    for (int i = 0; i < n; i++) {
        cout << last[i] << " " << first[i] << " " << gpa[i] << "\n";
    }

    return 0;
}
