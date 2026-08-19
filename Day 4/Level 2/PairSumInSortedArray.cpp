#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v={1,2,4,6,8,9};
    int i=0,j=v.size()-1,target;
    cout<<"Enter the target:";
    cin>>target;
    
    vector<pair<int,int>> ans;
    while(i<=j){
        if(v[i]+v[j]==target){
            ans.push_back({v[i],v[j]});
            i++;
            j--;
        }
        else if(v[i]+v[j]>target){
            j--;
        }
        else{
            i++;
        }
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i].first<<" and "<<ans[i].second<<"\n";
    }
}