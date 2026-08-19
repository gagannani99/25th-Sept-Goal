#include<bits/stdc++.h>
using namespace std;
int main(){
    unordered_map<int,int> um;
    int c=0;
    for(int i=1;i<10;i++){
        um[i]=c;
        c+=1;
    }
    for(auto i: um){
        cout<<i.first<<"->"<<i.second<<"\n";
    }
    int key;
    cout<<"Enter any value:";
    cin>>key;
    if(um.find(key)!=um.end()){
        cout<<"Element found";
    }
    else{
        cout<<"Element not found";
    }

}