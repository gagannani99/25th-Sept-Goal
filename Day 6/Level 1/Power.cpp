#include<bits/stdc++.h>
using namespace std;
int Power(int n,int x){
    if(x==1){
        return n;
    }
    else if(x==0){
        return 1;
    }
    
    return n*Power(n,x-1);
}
int main(){
    int n=5;
    int ans=Power(n,3);
    cout<<"5 Power 3 is "<<ans;
}