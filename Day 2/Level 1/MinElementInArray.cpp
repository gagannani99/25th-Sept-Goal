#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={1,2,3,4,5};
    int sum=0;
    int minEle=INT_MAX;
    for(int i=0;i<5;i++){
        if(arr[i]<minEle){
            minEle=arr[i];
        }
    }
    cout<<"Minimum element of array is "<<minEle;
}