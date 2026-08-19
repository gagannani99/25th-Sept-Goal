#include<bits/stdc++.h>
using namespace std;
int main(){
    unordered_map<int,int> um;
    vector<int> v={1,2,2,3,1,4,2};
    for(int i=0;i<v.size();i++){
        um[v[i]]++;
    }
    for(auto i:um){
        cout<<i.first<<"->"<<i.second<<"\n";
    }
    

}