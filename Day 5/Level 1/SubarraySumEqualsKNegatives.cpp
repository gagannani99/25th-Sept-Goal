#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v={1,1,1};
    int k=2;
    int sum=0,c=0,left=0;
    unordered_map<int,int> prefix_sum;
    prefix_sum[0]=1;
    for(int i=0;i<v.size();i++){
        sum+=v[i];
        if(prefix_sum.find(sum-k)!=prefix_sum.end()){
            c+=prefix_sum[sum-k];
        }
        prefix_sum[sum]++;
    }
    cout<<"Total subarrays which matches the k are "<<c;

}