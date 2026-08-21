#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v={1,1,1};
    int k=2;
    int sum=0,c=0,left=0;
    for(int right=0;right<v.size();right++){
        sum+=v[right];
        while(sum>k){
            sum-=v[left];
            left++;
        }
        if(sum==k){
            c++;
        }
    }
    cout<<"Total subarrays which matches the k are "<<c;
}