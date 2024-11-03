#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool binary_search(const vector<int> &array, int n) {
    int left = 0;
    int right = array.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (array[mid] == n) {
            return true;
        }

        else if (array[mid] < n) {
            left = mid + 1;
        }

        else {
            right = mid - 1;
        }
    }

    return false;
}

int main() {
    int m, k;

    cin >> m >> k;

    vector<int> first_array(m);
    vector<int> second_array(k);

    for (int i = 0; i < m; ++i) {
        cin >> first_array[i];
    }

    for (int i = 0; i < k; ++i) {
        cin >> second_array[i];
    }

    sort(first_array.begin(), first_array.end());

    for (int i = 0; i < k; ++i) {
        if (binary_search(first_array, second_array[i])) {
            cout << "YES" << endl;
        }
        
        else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}
