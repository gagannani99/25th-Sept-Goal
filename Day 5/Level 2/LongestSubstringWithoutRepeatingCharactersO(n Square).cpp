#include<bits/stdc++.h>
using namespace std;
int main(){
    string s="abcabcbb";
    vector<char> s2;
    string ans="";
    for(int i=0;i<s.size();i++){
        s2.push_back(s[i]);
        while(find(s2.begin(),s2.end()-1,s[i])!=s2.end()-1){//*************** */
            s2.erase(s2.begin());

        }
        if(s2.size()>ans.size()){
            ans="";
            for(int j=0;j<s2.size();j++){
                ans+=s2[j];
            }
        }
    }
    
    
    cout<<"Max substring without repiting characters is "<<ans;
}