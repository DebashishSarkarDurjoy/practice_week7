#include <iostream>
#include <vector>

using namespace std;

int minSwaps(vector<int> &inputs) {
    vector<pair<int,int>> nums;
    for (int i = 0; i < inputs.size(); i++) {
        nums.push_back({inputs[i], i});
    }

    sort(nums.begin(), nums.end());
   
    vector<bool> visited (inputs.size(), false);

    int ans = 0;
    for (int i = 0; i < inputs.size(); i++) {
        if (visited[i] || i == nums[i].second) {
            continue;
        }

        int cycles = 0;
        int node = i;
        while (!visited[node]) {
            visited[node] = true;
            cycles++;
            node = nums[node].second;
        }
        if (cycles > 0) ans += (cycles - 1);
    }

    return ans;
}

int main(void) {
    vector<int> nums = {2,4,5,1,3};
    cout << minSwaps(nums) << endl;

    return 0;
}