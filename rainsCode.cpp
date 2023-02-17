#include <iostream>
#include <vector>

using namespace std;

int findUnitsOfWater(vector<int> &blocks) {
    int n = blocks.size();

    vector<int> left_max (n, 0);
    vector<int> right_max (n, 0);

    left_max[0] = blocks[0];
    right_max[n-1] = blocks[n-1];
    for (int i = 1; i < n; i++) {
        left_max[i] = max(left_max[i-1], blocks[i]);
        right_max[n-1 -i] = max(right_max[n-i], blocks[n-1 -i]);
    }

    for (int i = 0; i < n; i++) {
        cout << left_max[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << right_max[i] << " ";
    }

    int water = 0;
    for (int i = 0; i < n; i++) {
        water += min(left_max[i], right_max[i]) - blocks[i];
    }
    cout << endl;
    
    return water;
}

int main(void) {
    vector<int> rains = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << findUnitsOfWater(rains) << endl;

    return 0;
}