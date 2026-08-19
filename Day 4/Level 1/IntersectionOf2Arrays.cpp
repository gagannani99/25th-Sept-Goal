#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v1={1,2,2,4};
    vector<int> v2={1,2,2,4,5};
    vector<int> ans;
    int i=0,j=0;
    while(i<v1.size()&&j<v2.size()){
        if(v1[i]==v2[j]&& ans.size()==0){
            ans.push_back(v1[i]);
            i++;
            j++;
            continue;
        }
        if(v1[i]==v2[j]&& ans[ans.size()-1]!=v1[i]){
            ans.push_back(v1[i]);
            i++;
            j++;
        }
        else if(v1[i]>=v2[j]){
            j++;
        }
        else if(v1[i]<v2[j]){
            i++;
        }
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}