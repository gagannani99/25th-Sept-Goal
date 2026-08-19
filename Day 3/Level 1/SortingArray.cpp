#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v={21,43,11,54,33,22,54,66,75,32,1,45};
    cout<<"Sorting in ascending order:\n";
    sort(v.begin(),v.end());
    for(auto i:v){
        cout<<i<<" ";
    }
    cout<<"\n";
    cout<<"Sorting in decendding order:\n";
    sort(v.begin(),v.end(),greater<int>());
    for(auto i:v){
        cout<<i<<" ";
    }
    cout<<"\n";
}