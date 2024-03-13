// reverse a string using recursion
#include<iostream>
using namespace std;

void swap(char *a, char *b){
    char *temp=a;
    a=b;
    b=temp;
}

// pass by refrence using &s
// void reverseString(string &s, int i, int j){
//     // base case
//     if(i>j){
//         return ;
//     }
//     // process
//     swap(s[i], s[j]);
//     i++;
//     j--;
//     // recursive relation
//     reverseString(s,i,j);

// }


// recusive relation using only one pointer, better for optimization
void ReverseString(string &s,int i){
    int len=s.length();
    if(i>len/2){
        return ;
    }

    swap(s[i],s[len-i-1]);
    i++;

    ReverseString(s,i);
}

int main(){
    string s="abcde";
    int length=s.length();
    cout<<"before swap"<<endl;
    cout<<s<<endl;
    // reverseString(s,0,length-1);
    ReverseString(s,0);
    cout<<"after swap"<<endl;
    cout<<s<<endl;
    return 0;
}