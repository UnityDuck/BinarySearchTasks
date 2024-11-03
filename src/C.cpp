#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canPlaceCows(const vector<int> &places, int K, int d) {
    int count = 1;
    int last_position = places[0];

    for (size_t i = 1; i < places.size(); ++i) {
        if (places[i] - last_position >= d) {
            count++;
            last_position = places[i];

            if (count == K)
                return true;
        }
    }
    return false;
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> stalls(N);

    for (int i = 0; i < N; ++i) {
        cin >> stalls[i];
    }

    int left = 1;
    int right = stalls[N - 1] - stalls[0];
    int best_distance = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (canPlaceCows(stalls, K, mid)) {
            best_distance = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << best_distance << endl;
    return 0;
}
