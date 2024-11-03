#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canCutRopes(const vector<int> &lengths, int targetLength, int K) {
    int count = 0;
    for (int length : lengths) {
        count += length / targetLength;
    }
    return count >= K;
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> lengths(N);
    for (int i = 0; i < N; ++i) {
        cin >> lengths[i];
    }

    int low = 1;
    int high = *max_element(lengths.begin(), lengths.end());

    int maxLength = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canCutRopes(lengths, mid, K)) {
            maxLength = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << maxLength << endl;

    return 0;
}
