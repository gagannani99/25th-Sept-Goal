#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    for(auto i:v){
        cout<<i<<" ";
    }
    cout<<"\n";
    v.pop_back();
    for(auto i:v){
        cout<<i<<" ";
    }
    cout<<"\n";
    v.insert(v.begin()+1,5);
    for(auto i:v){
        cout<<i<<" ";
    }
    cout<<"\n";
    cout<<v.front()<<" "<<v.back();
    // v.empty();
    // for(auto i:v){
    //     cout<<i<<" ";
    // }
    cout<<"\n";
    sort(v.begin(),v.end());
    for(auto i:v){
        cout<<i<<" ";
    }
    cout<<"\n";
    sort(v.begin(),v.end(),greater<int>());
    for(auto i:v){
        cout<<i<<" ";
    }
    cout<<"\n";
    reverse(v.begin(),v.end());
    for(auto i:v){
        cout<<i<<" ";
    }
    cout<<"\n";
}