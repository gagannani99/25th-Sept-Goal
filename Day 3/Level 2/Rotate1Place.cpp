#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v={1,2,3,4,5};
    int temp=v[v.size()-1];
    for(int i=v.size()-1;i>0;i--){
        v[i]=v[i-1];
    }
    v[0]=temp;
    for(auto i:v){
        cout<<i<<" ";
    }
}