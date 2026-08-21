#include<bits/stdc++.h>
using namespace std;
void Print1ToN(int n){
    if(n==1){
        cout<<n<<" ";
    }
    else{
        cout<<n<<" ";
        Print1ToN(n-1);
    }
}
int main(){
    int n=5;
    Print1ToN(n);
}