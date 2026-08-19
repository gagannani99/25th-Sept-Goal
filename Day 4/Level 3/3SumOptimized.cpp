#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        

        for(int i = 0; i < nums.size()-2; i++) {
            if(i > 0 && nums[i] == nums[i - 1]){

                continue;
            }
            int left=i+1,right=nums.size()-1;
            while(left<right){
                int sum=nums[i]+nums[left]+nums[right];
                if(sum>0){
                    right--;
                }
                else if(sum<0){
                    left++;
                }
                else{
                    ans.push_back({nums[i],nums[left],nums[right]});
                    while(right>left && nums[left]==nums[left+1]){
                        left++;
                    }
                    while(right>left && nums[right]==nums[right-1]){
                        right--;
                    }
                    left++;
                    right--;
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