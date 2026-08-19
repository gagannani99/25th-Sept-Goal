#include<bits/stdc++.h>
using namespace std;
int main(){
    string s="hello",temp;
    temp=s;
    int i=0,j=s.size()-1;
    while(i<=j){
        char temp=s[i];
        s[i]=s[j];
        s[j]=temp;
        i++;
        j--;
    }
    cout<<"Reverse of "<<temp<<" is "<<s;
}