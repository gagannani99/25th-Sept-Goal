#include<bits/stdc++.h>
using namespace std;
int Fibbo(int n){
    if(n==1){
        return 0;
    }
    else if(n==2){
        return 1;
    }
    
    return Fibbo(n-1)+Fibbo(n-2);
}
int main(){
    int n=7;
    int ans=Fibbo(n);
    cout<<"Fibonacci of n is "<<ans;
}