#include<bits/stdc++.h>
using namespace std;
int SumUpToN(int n){
    if(n==1){
        return 1;
    }
    return n+SumUpToN(n-1);
}
int main(){
    int n=5;
    int ans=SumUpToN(n);
    cout<<"Sum is "<<ans;
}