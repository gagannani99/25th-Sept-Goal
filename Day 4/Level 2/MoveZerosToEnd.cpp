#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[]={0,2,0,3,4,0,0,0,5,0,6};
    int i=0,j=0,n=(sizeof(arr)/sizeof(int));
    while(i<n && j<n){
        if(arr[i]!=0 && arr[j]!=0){
            i++;
            j++;
        }
        else if(arr[i]==0 && arr[j]!=0){
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            i++;
          
        }
        else if(arr[i]==0 && arr[j]==0){
            j++;
        }

    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}