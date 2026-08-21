#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "abcabcbb";

    unordered_map<char, int> mp;

    int left = 0;
    int maxLen = 0;
    string ans = "";

    for(int right = 0; right < s.size(); right++) {

        mp[s[right]]++;

        while(mp[s[right]] > 1) {
            mp[s[left]]--;
            left++;
        }

        if(right - left + 1 > maxLen) {
            maxLen = right - left + 1;
            ans = s.substr(left, maxLen);
        }
    }

    cout << "Max substring without repeating characters is " << ans;

    return 0;
}