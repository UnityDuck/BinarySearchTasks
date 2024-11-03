#include <iostream>
#include <vector>

using namespace std;

bool canFindSegment(vector<int> &heights, int length, long long x) {
    int count = 0;
    for (int height : heights) {
        if (height <= x) {
            count++;
            if (count >= length) {
                return true;
            }
        }
        else {
            count = 0;
        }
    }
    return false;
}

int main() {
    int n;
    long long x;
    cin >> n >> x;

    vector<int> heights(n);
    for (int i = 0; i < n; ++i) {
        cin >> heights[i];
    }

    int left = 0, right = n, bestLength = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (canFindSegment(heights, mid, x)) {
            bestLength = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    cout << bestLength << endl;

    return 0;
}
