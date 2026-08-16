#include<bits/stdc++.h>
using namespace std;
// Without return type and without parameters
void add(){
    cout<<"Addition between 2 and 3 is "<<2+3;
}
// With return type and without parameters
int subract(){
    return 3-2;
}
// Without return type and with parameters
void multiply(int a, int b){
    cout<<"Product of a and b is "<<a*b<<"\n";
}
// With return type and with parameters
int division(int a,int b){
    return a/b;
}
int main(){
    add();
    cout<<"\n";
    int sub=subract();
    cout<<"Diff of 3 and 2 is "<<sub<<"\n";
    multiply(2,3);
    cout<<"Division of 10,2 is "<<division(10,2);
}