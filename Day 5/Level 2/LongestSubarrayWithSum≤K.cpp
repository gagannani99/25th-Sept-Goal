#include<bits/stdc++.h>
using namespace std;
int main(){
    int k=7;
    vector<int> v={2,1,5,2,3,2};
    int sum=0;
    int left=0,c=0,maxLen=0;
    for(int i=0;i<v.size();i++){
        sum+=v[i];
        while(sum>k){
            sum-=v[left];
            left++;
        }
        if(sum<=k){
            maxLen=max(maxLen,i-left+1);
        }

    }
    cout<<"Max lenfth of K sum is "<<maxLen;
}