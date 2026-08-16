#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[]={2,3,4,5,6};
    int XOR1=0,XOR2=0;
    for(int i=1;i<=6;i++){
        XOR1^=i;
    }    
    for(int i=0;i<5;i++){
        XOR2=XOR2^arr[i];
    }
    cout<<"Missing number is "<<(XOR1^XOR2);
}