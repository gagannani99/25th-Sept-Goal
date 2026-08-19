#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v={1,1,2,2,3,4,4,5};
    int i=1,j=1;
    vector<int> v1;
    v1.push_back(v[0]);
    while(j<v.size()){
        if(v1[v1.size()-1]!=v[j]){
            v1.push_back(v[j]);
        }
        j++;
    }
    for(auto k:v1){
        cout<<k<<" ";
    }
}