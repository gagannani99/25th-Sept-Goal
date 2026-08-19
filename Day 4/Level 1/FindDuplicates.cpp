#include<bits/stdc++.h>
using namespace std;
int main(){
    set<int> s;
    vector<int> v={1,2,2,3,1,4,2};
    // vector<int> v={1,2,3};

    int c=0;
    for(auto i : v){
        if(s.find(i)!=s.end()){
            c=1;
            cout<<"Duplicates are there";
            break;
        }
        s.insert(i);
    }
    if(c==0){
        cout<<"No duplicates found";
    }
}