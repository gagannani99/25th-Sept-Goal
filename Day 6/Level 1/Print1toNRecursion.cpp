#include<bits/stdc++.h>
using namespace std;
void Print1ToN(int a,int n){
    if(a==n){
        cout<<a<<" ";
    }
    else{
        cout<<a<<" ";
        Print1ToN(a+1,n);
    }
}
int main(){
    int n=5;
    Print1ToN(1,n);
}