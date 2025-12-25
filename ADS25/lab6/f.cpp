#include <bits/stdc++.h>
using namespace std;

// Словарь для перевода буквенной оценки в число
map<string, double> gradeValue = {
    {"A+", 4.00}, {"A", 3.75}, {"B+", 3.50}, {"B", 3.00},
    {"C+", 2.50}, {"C", 2.00}, {"D+", 1.50}, {"D", 1.00}, {"F", 0.00}
};

// Структура для хранения данных о студенте
struct Student {
    string lastName;
    string firstName;
    double gpa;
};

// Функция для разделения массива (часть быстрой сортировки)
int partition(vector<Student> &arr, int low, int high) {
    double pivot = arr[high].gpa; // Опорный элемент (GPA)
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j].gpa < pivot || 
           (fabs(arr[j].gpa - pivot) < 1e-9 && arr[j].lastName < arr[high].lastName) ||
           (fabs(arr[j].gpa - pivot) < 1e-9 && arr[j].lastName == arr[high].lastName && arr[j].firstName < arr[high].firstName)) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Реализация Quick Sort
void quickSort(vector<Student> &arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    cin >> n;
    vector<Student> students;

    for (int i = 0; i < n; i++) {
        string last, first;
        int subjCount;
        cin >> last >> first >> subjCount;

        double totalPoints = 0, totalCredits = 0;
        for (int j = 0; j < subjCount; j++) {
            string grade;
            int credits;
            cin >> grade >> credits;

            totalPoints += gradeValue[grade] * credits;
            totalCredits += credits;
        }

        double gpa = totalPoints / totalCredits;
        students.push_back({last, first, gpa});
    }

    quickSort(students, 0, n - 1);

    for (auto &s : students)
        cout << s.lastName << " " << s.firstName << " " << fixed << setprecision(3) << s.gpa << "\n";

    return 0;
}
