#include<bits/stdc++.h>
using namespace std;
int main(){
    int num,sum=0;
    cout<<"Enter the number:";
    cin>>num;
    for(int i=1;i<=num;i++){
        sum+=i;
    }
    cout<<"Sum of natural numbers upto "<<num<<" are "<<sum;
    return 0;
}