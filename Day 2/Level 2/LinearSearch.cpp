#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={1,2,3,4,5};
    int key,s=0;
    cout<<"Enter the element you want to search:";
    cin>>key;
    for(int i=0;i<5;i++){
        if(arr[i]==key){
            s=1;
            cout<<"Element found at index "<<i;
            break;
        }
    }
    if(s==0){
        cout<<"Element not found";
    }
}