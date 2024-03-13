// check palindrome of string
#include<iostream>
using namespace std;

void swap(char *a, char *b){
    char *temp=a;
    a=b;
    b=temp;
}

bool checkPalindrome(string &s,int i){
    int len=s.length();
    if(i>len/2){
        return 0;
    }
    if(s[i]==s[len-i-1]){
        i++;
        checkPalindrome(s,i);
        return 1;
    }
    return 0;

}

int main(){
    string s="aaaaaaaaaaaaaaaaaa";
    int length=s.length();
    bool check=checkPalindrome(s,0);
    
    
    cout<<check<<endl;
    return 0;
}