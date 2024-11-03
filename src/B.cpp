#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lower_bound(const vector<int>& arr, int target) {
    int left = 0, right = arr.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

int upper_bound(const vector<int>& arr, int target) {
    int left = 0, right = arr.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] <= target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

int main() {
    int N;
    cin >> N;

    vector<int> numbers(N);
    for (int i = 0; i < N; ++i) {
        cin >> numbers[i];
    }

    sort(numbers.begin(), numbers.end());

    int K;
    cin >> K;

    for (int i = 0; i < K; ++i) {
        int L, R;
        cin >> L >> R;

        int left_index = lower_bound(numbers, L);
        int right_index = upper_bound(numbers, R);

        int count = right_index - left_index;

        cout << count << endl;
    }

    return 0;
}