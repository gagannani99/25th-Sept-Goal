#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={1,2,3,4,5};
    int sum=0;
    int ec=0,oc=0;
    for(int i=0;i<5;i++){
        if(arr[i]%2==0){
            ec++;;
        }
        else{
            oc++;
        }
    }
    cout<<"Even count "<<ec<<" Odd count "<<oc;
}