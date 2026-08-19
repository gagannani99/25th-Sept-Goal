#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v={21,43,11,54,33,22,54,66,75,32,1,45};
    
    
    sort(v.begin(),v.end(),greater<int>());
    int maxele=INT_MIN;
    for(int i=1;i<v.size();i++){
        if(v[i]!=v[0]){
            maxele=v[i];
            break;
        }
    }
    cout<<"2nd max element is "<<maxele;
}