#include<bits/stdc++.h>
using namespace std;
void printingArray2(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int arr1[]={1,2,3,4};
    cout<<"Elements present in the array1 are:"<<"\n";
    for(int i=0;i<(sizeof(arr1)/sizeof(int));i++){
        cout<<arr1[i]<<" ";
    }
    cout<<"\n";
    int arr2[5];
    cout<<"Enter the elements of array2:";
    for(int i=0;i<5;i++){
        cin>>arr2[i];
    }
    cout<<"Elements present in the array2 are:"<<"\n";
   printingArray2(arr2,5);
}