#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v={0};
    unordered_map<int,int> m;
    int sum=0;
    for(int i=0;i<v.size();i++){
        sum+=v[i];
        m[i]=sum;
    }
    int index=-1;
    for(int i=0;i<v.size();i++){
        if(i==0){
            if(m[i]==(m[v.size()-1]-m[i])){
            index=i;
            break;}
        }
        if(i==v.size()-1){
            if(v[i]==m[i-1]){
                index=i;
                break;
            }
        }
        if(m[i-1]==(m[v.size()-1]-m[i])){
            index=i;
            break;
        }
    }
    cout<<"Equilibrium point is "<<index;
}