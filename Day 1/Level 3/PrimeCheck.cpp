#include<bits/stdc++.h>
using namespace std;
int main(){
    int num,s=0;
    cout<<"Enter the number:";
    cin>>num;
    for(int i=2;i<pow(num,0.5)+1;i++){
        if(num%i==0){
            s=1;
            cout<<"Not Prime";
            break;
        }
    }
    if(s==0){
        cout<<"Prime";
    }
    return 0;
}