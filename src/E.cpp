#include <iostream>
#include <vector>

using namespace std;

int binarySearchSqrt(long long n) {
    if (n < 2) return n;
    long long left = 0, right = n;

    while (left < right) {
        long long mid = (left + right + 1) / 2;

        if (mid * mid == n) {
            left = mid;
            break;
        }
        else if (mid * mid < n) {
            left = mid;
        }
        else {
            right = mid - 1;
        }
    }

    return left;
}


int main() {
    vector<int> results;
    long long n;

    while (cin >> n) {
        results.push_back(binarySearchSqrt(n));
    }

    for (long long result : results) {
        cout << result << endl;
    }

    return 0;
}
