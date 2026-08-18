#include<bits/stdc++.h>
using namespace std;
int main(){
    pair<int,int> p={1,2};
    cout<<p.first<<" "<<p.second<<"\n";
    pair<int,pair<int,int>> p1={1,{2,3}};
    cout<<p1.first<<" "<<p1.second.first<<" "<<p1.second.second<<"\n";
    pair<int,int> arr[]={{1,2},{2,3},{3,4}};
    cout<<arr[2].first;
}