#include <iostream>

using namespace std;

float root(int N, int p) {
    int left = 0;
    int right = N;
    int mid = 0;

    float ans = 0.0;
    while (left <= right) {
        mid = (left + right) / 2;

        if (mid*mid == N) {
            return (float) mid;
        }
        else if (mid*mid < N) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
        ans = mid;
    }

    float inc = 0.1;
    for (int i = 1; i <= p; i++) {
        ans += inc;
        while (ans*ans <= N) {
            ans += inc;
        }
        ans -= inc;
        inc = inc / 10;
    }
    return ans;
}

int main(void) {
    int N, p;
    cin >> N >> p;

    cout << root(N, p) << endl;

    return 0;
}