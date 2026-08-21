#include<bits/stdc++.h>
using namespace std;
bool isPalindrome(string s,int lb,int ub){
    if(lb>ub){
        return true;
    }
    if(s[lb]!=s[ub]){
        return false;
    }
    return isPalindrome(s,lb+1,ub-1);
}
int main(){
    string s="abc";
    bool ans=isPalindrome(s,0,s.size()-1);
    if (ans==true)
    cout<<"s is palindrome";
    else
    cout<<"s is not palindrome";
}