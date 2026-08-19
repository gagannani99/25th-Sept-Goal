#include<bits/stdc++.h>
using namespace std;
int main(){
    unordered_set<int> s;
    int c=0;
    for(int i=1;i<10;i++){
        s.insert(i);
    }
    for(auto i: s){
        cout<<i<<" ";
    }
    cout<<"\n";
    int key;
    cout<<"Enter any value:";
    cin>>key;
    if(s.find(key)!=s.end()){
        cout<<"Element found";
    }
    else{
        cout<<"Element not found";
    }

}