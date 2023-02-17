#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int findLongestBand(vector<int> &nums) {
    unordered_set<int> s;
    for (auto n: nums) s.insert(n);

    // for (auto p: s) {
    //     cout << p << endl;
    // }

    int max_band = INT_MIN;
    for (int n: nums) {
        int prev = n - 1;
        if ( s.find(prev) != s.end() ) {
            continue;
        }

        int next = n + 1;
        if ( s.find(next) != s.end() ) {
            int band = 2;
            next++;
            while ( s.find(next) != s.end() ) {
                band++;
                next++;
            }
            max_band = max(band, max_band);
        }
    }

    return max_band;
}

int main(void) {
    vector<int> numbers = {1,9,3,0,18,5,2,4,10,7,12,6};
    cout << findLongestBand(numbers) << endl;


    return 0;
}