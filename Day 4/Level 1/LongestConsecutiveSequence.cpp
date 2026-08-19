#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v={1,4,200,1,3,2};
    stable_sort(v.begin(),v.end());
    int c=1,maxC=1;
    for(int i=1;i<v.size();i++){
        if(v[i]-v[i-1]==1){
            c++;
            maxC=max(maxC,c);
        }
        else{
            c=1;
        }
    }
    cout<<"Longest consecutive sequence is "<<maxC;
}