#include<bits/stdc++.h>
using namespace std;
int main(){
    int num;
    cout<<"Enter the number:";
    cin>>num;
    int c=0,temp=num;
    while(temp>0){
        c++;
        temp=temp/10;
    }
    cout<<"Number of digits are:"<<c;
    return 0;
}