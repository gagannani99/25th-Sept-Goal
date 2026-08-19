#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v={1,2,3,2,4,2,5};
    int target;
    cout<<"Enter the target element:";
    cin>>target;
    int c=0;
    for(int i=0;i<v.size();i++){
        if(v[i]==target){
            c++;
        }
    }
    cout<<"Target is repeated "<<c<<" times";
}