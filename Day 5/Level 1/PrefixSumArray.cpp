#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v={2,4,1,5,3};
    vector<int> ans;
    int prefix_sum=v[0];
    ans.push_back(prefix_sum);
    for(int i=1;i<v.size();i++){
        prefix_sum+=v[i];
        ans.push_back(prefix_sum);
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

}