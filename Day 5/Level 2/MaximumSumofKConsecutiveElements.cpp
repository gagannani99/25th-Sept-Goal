#include<bits/stdc++.h>
using namespace std;
int main(){
    int k=3;
    vector<int> v={2,1,5,1,3,2};
    int sum=0,maxSum=0;
    int left=0,c=0;
    for(int i=0;i<v.size();i++){
        sum+=v[i];
        c++;
        if(c>=k){
            maxSum=max(maxSum,sum);
            sum-=v[left];
            left++;
            c--;
        }

    }
    cout<<"Max Sum of K elements is "<<maxSum;
}