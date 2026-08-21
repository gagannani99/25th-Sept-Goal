#include<bits/stdc++.h>
using namespace std;
int Occurance(vector<int> &v,int target,int c,int n){
    if(n==v.size()){
        return c;
    }
    if(v[n]==target){
        c++;
    }
    return Occurance(v,target,c,n+1);
}
int main(){
    vector<int> v={1,2,3,2,2,5,5};
    int target=5,index=0;
    int ans=Occurance(v,target,index,0);
    cout<<"Target is repeated "<<ans<<" times";
}