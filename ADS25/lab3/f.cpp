#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> competitors(n);
    for (int i = 0; i < n; i++) {
        cin >> competitors[i];
    }
    int rounds;
    cin >> rounds;
    
    for (int i = 0; i < rounds; i++) {
        int mark_power;
        cin >> mark_power;
        int count = 0;
        int power_sum = 0;
        
        for (int j = 0; j < n; j++) {
            if (competitors[j] <= mark_power) {
                count++;
                power_sum += competitors[j];
            }
        }
        
        cout << count << " " << power_sum << endl;
    }
    
    return 0;
}