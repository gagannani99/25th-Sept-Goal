#include<bits/stdc++.h>
using namespace std;
int main(){
    int num;
    cout<<"Enter the number:";
    cin>>num;
    int sum=0,temp=num;
    while(temp>0){
        int rem=temp%10;
        sum=sum*10+rem;
        temp=temp/10;
    }
    cout<<"Reverse of number is :"<<sum;
    return 0;
}