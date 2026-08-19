#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        unordered_map<int,int> um;

        for(int i = 0; i < nums.size(); i++) {
            um[nums[i]] = i;
        }

        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++) {

                int target = -(nums[i] + nums[j]);

                if(um.find(target) != um.end() &&
                   um[target] != i &&
                   um[target] != j) {

                    vector<int> v = {nums[i], nums[j], target};

                    sort(v.begin(), v.end());

                    if(find(ans.begin(), ans.end(), v) == ans.end()) {
                        ans.push_back(v);
                    }
                }
            }
        }

        return ans;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;

    vector<vector<int>> ans = obj.threeSum(nums);

    for(auto v : ans) {
        for(auto x : v) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}