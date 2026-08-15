#include<bits/stdc++.h>
using namespace std;
int main(){
    int num,s=0;
    cout<<"Enter the number:";
    cin>>num;
    int t1=0,t2=1;
    if(num==1){
        cout<<t1;
    }
    else if(num==2){
        cout<<t1<<" "<<t2;
    }
    else{
        cout<<t1<<" "<<t2<<" ";
        for(int i=3;i<=num;i++){
            int t3=t1+t2;
            cout<<t3<<" ";
            t1=t2;
            t2=t3;
        }
    }
    return 0;
}