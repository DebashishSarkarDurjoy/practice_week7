#include <iostream>
#include <vector>

using namespace std;

void findTriplets(vector<int> &nums, int target) {
    sort(nums.begin(), nums.end());

    vector<vector<int>> results;
    int n = nums.size() - 1;
    for (int i = 0; i <= n-2; i++) {
        int pointer1 = i+1;
        int pointer2 = n;
        int rest_sum = target - nums[i];
        int temp_sum = 0;
        while ( pointer1 < pointer2 ) {
            temp_sum = nums[pointer1] + nums[pointer2];
            if (rest_sum == temp_sum) {
                results.push_back({nums[i], nums[pointer1], nums[pointer2]});
                pointer1++;
            }
            else if (rest_sum < temp_sum) {
                pointer2--;
                
            }
            else {  
                pointer1++;
            }
        }
    }

    for (auto row: results) {
        for (auto c: row) {
            cout << c << " ";
        }
        cout << endl;
    }
}

int main(void) {
    vector<int> nums = {1,2,3,4,5,6,7,8,9,15};

    int target = 18;
    findTriplets(nums, target);

    return 0;
}