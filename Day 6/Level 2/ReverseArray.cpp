#include<bits/stdc++.h>
using namespace std;
void reverseVector(vector<int> &v,int lb, int ub){
    if(lb>ub){
        return;
    }
    swap(v[ub],v[lb]);
    reverseVector(v,lb+1, ub-1);
}
int main(){
    vector<int> v={1,2,3,4,5};
    reverseVector(v,0,v.size()-1);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}