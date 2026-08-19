#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& v, int k) {
        int n = v.size();
        k = k % n;

        reverse(v.begin(), v.end());
        reverse(v.begin(), v.begin() + k);
        reverse(v.begin() + k, v.end());
    }
};

int main() {
    vector<int> v = {1, 2, 3, 4, 5, 6, 7};

    int k;
    cout << "Enter K: ";
    cin >> k;

    Solution obj;
    obj.rotate(v, k);

    for (auto x : v) {
        cout << x << " ";
    }

    return 0;
}