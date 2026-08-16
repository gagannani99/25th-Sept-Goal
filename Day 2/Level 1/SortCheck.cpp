#include<bits/stdc++.h>
using namespace std;
bool traversingLeft(int arr[],int lb,int ub){
    while(lb<ub){
        int mid=(ub+lb)/2;
        if(arr[mid]>=arr[lb]&&arr[mid]<=arr[ub]){
            ub=mid-1;
        }
        else{
            return false;
        }
    }
    return true;
}
bool traversingRight(int arr[],int lb,int ub){
    while(lb<ub){
        int mid=(ub+lb)/2;
        if(arr[mid]>=arr[lb]&&arr[mid]<=arr[ub]){
            lb=mid+1;
        }
        else{
            return false;
        }
    }
    return true;
}
int main(){
    int arr[]={1,2,3,4,8,5};
    bool leftTraverse=traversingLeft(arr,0,5);
    bool rightTraverse=traversingRight(arr,0,5);
    if(leftTraverse && rightTraverse){
        cout<<"Elements are sorted";
    }
    else{
        cout<<"Elements are not sorted";
    }
    
}