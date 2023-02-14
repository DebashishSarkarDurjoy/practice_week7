#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int findGPTriplets(vector<int> &nums, int r) {
    unordered_map<int, int> left;
    unordered_map<int, int> right;
    for (int n: nums) {
        right[n]++;
    }

    int count = 0;
    right[nums[0]]--;
    for (int i = 1; i < nums.size()-1; i++) {
        right[nums[i]]--;
        left[nums[i-1]]++;

        if (nums[i] % r == 0) {
            int gp_mid = nums[i];
            int gp_left = nums[i] / r;
            int gp_right = nums[i] * r;

            if ( (left.find(gp_left) != left.end()) && (right.find(gp_right) != right.end()) ) {
                count += left[gp_left] * right[gp_right];
            } 
        }
    }

    return count;
}

int main(void) {
    vector<int> nums = {1, 16, 4, 16, 64, 16};

    cout << findGPTriplets(nums, 4) << endl;

    return 0;
}