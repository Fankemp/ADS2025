#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }


    for (int i = 0; i < q; i++) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;

        l1--; r1--; l2--; r2--;

        int count = 0;  
        for (int i = 0; i < n; i++) {
            if ((arr[i] >= l1 + 1 && arr[i] <= r1 + 1) || (arr[i] >= l2 + 1 && arr[i] <= r2 + 1)) {
                count++;
            }
        }

        cout << count << endl;
    }

    return 0;
}
