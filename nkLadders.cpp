#include <iostream>

using namespace std;

int countWays(int n, int k) {
    if (n == 0) return 1;
    if (n < 0) return 0;

    int ans = 0;
    for (int jump = 1; jump <= k; jump++) {
        ans += countWays(n-jump, k);
    }

    return ans;
}

int main(void) {
    int n, k;
    cin >> n >> k;
    cout << countWays(n, k) << endl;

    return 0;
}