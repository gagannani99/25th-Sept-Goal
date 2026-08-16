#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={1,2,3,4,5};
    int sum=0;
    int maxEle=INT_MIN;
    for(int i=0;i<5;i++){
        if(arr[i]>maxEle){
            maxEle=arr[i];
        }
    }
    cout<<"Maximum element of array is "<<maxEle;
}