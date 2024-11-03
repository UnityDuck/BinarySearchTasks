#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long N;
    cin >> N;

    vector<int> array = {100, 20, 10, 5, 1};
    long long counter = 0;

    for (long long count : array) {
        if (N == 0) {
            break;
        }
        counter += N / count;
        N %= count;
    }

    cout << counter << endl;
    return 0;
}
