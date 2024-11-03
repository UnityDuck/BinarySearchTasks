#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void countingSort(vector<int> &A) {
    if (A.empty()) {
        return;
    }

    int maxValue = *max_element(A.begin(), A.end());

    vector<int> count(maxValue + 1, 0);

    for (int num : A) {
        count[num]++;
    }

    int index = 0;
    for (int i = 0; i <= maxValue; ++i) {
        while (count[i] > 0) {
            A[index++] = i;
            count[i]--;
        }
    }
}


int main() {
    int n;
    cin >> n;

    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    countingSort(A);

    for (int i = 0; i < n; ++i) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}
