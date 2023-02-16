#include <vector>
#include <iostream>

using namespace std;

bool inOrder(vector<int> &nums, int i) {
    if (i == 0) {
        return nums[i+1] > nums[i];
    }
    if (i == nums.size() - 1) {
        return nums[i-1] < nums[i];
    }

    return (nums[i] > nums[i-1]) && (nums[i] < nums[i+1]); 
}

pair<int, int> subArraySort(vector<int> &nums) {
    int largest = INT_MIN;
    int smallest = INT_MAX;

    for (int i = 0; i < nums.size(); i++) {
        if (!inOrder(nums, i)) {
            largest = max(nums[i], largest);
            smallest = min(nums[i], smallest);
        }
    }

    int first = -1;
    int last = -1;

    int i = 0;
    while (smallest > nums[i]) {
        i++;
    }
    first = i;

    i = nums.size()-1;
    while (largest < nums[i]) {
        i--;
    }
    last = i;

    if (first == -1 || last == -1) return {-1, -1};
    else return {first, last};
}

int main(void) {
    vector<int> array = {1,2,3,4,5,8,6,7,9,10,11};
    pair<int,int> subArray = subArraySort(array);

    cout << subArray.first << " " << subArray.second << endl;
}