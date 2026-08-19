#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;

        // Store each element and its index
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]] = i;
        }

        // Find the required pair
        for (int i = 0; i < nums.size(); i++) {
            int ele = target - nums[i];

            if (m.find(ele) != m.end() && m[ele] != i) {
                return {i, m[ele]};
            }
        }

        return {0, 0};
    }
};

int main() {
    int n, target;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter target: ";
    cin >> target;

    Solution obj;

    vector<int> ans = obj.twoSum(nums, target);

    cout << "Indices: " << ans[0] << " " << ans[1] << endl;

    return 0;
}