#include <iostream>
#include <vector>

using namespace std;

int findMountainLength(vector<int> &nums) {
    int length = 0;

    int n = nums.size();
    for (int i = 1; i <= n - 2; i++) {
        int count = 0;
        if ( (nums[i] > nums[i-1]) && (nums[i] > nums[i+1]) ) {
            int j = i;
            count = 1;
            while (j >= 1 && nums[j] > nums[j-1] ) {
                j--;
                count++;
            }
            int k = i;
            while (k < n-1 && nums[k] > nums[k+1]) {
                count++;
                k++;
            }
        }
        length = max(length, count);
    }

    return length;
}


int main(void) {
    vector<int> numbers = {5,6,1,2,3,4,5,4,3,2,0,1,2,3,-2,4};
    cout << findMountainLength(numbers) << endl;

    return 0;
}