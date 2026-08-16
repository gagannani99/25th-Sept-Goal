#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={1,2,3,4,5};
    int sum=0;
    int i=0,j=4;
    while(i<=j){
        int temp=arr[j];
        arr[j]=arr[i];
        arr[i]=temp;
        i++;
        j--;
    }
    for(int k=0;k<5;k++){
        cout<<arr[k]<<"\n";
    }
}