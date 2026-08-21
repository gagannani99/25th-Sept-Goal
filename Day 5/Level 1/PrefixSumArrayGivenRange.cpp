#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v={2,4,1,5,3};
    int lb,ub;
    cout<<"Enter the lower bond:";
    cin>>lb;
    cout<<"Enter the upper bond:";
    cin>>ub;

    map<int,int> prefix_sum;
    int sum=0;
    for(int i=0;i<v.size();i++){
        sum+=v[i];
        prefix_sum[i]=sum;
    }
    if(lb==0){
        cout<<"Sum is "<<prefix_sum[ub];
    }
    else{
        cout<<"Sum is "<<prefix_sum[ub]-prefix_sum[lb-1];
    }

}