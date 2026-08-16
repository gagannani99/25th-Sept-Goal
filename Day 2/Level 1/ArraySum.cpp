#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={1,2,3,4,5};
    int sum=0;
    for(int i=0;i<(sizeof(arr)/sizeof(int));i++){
        sum+=arr[i];
    }
    cout<<"Sum of array is:"<<sum;
}