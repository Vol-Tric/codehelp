// length of string
#include<iostream>
using namespace std;
int main(){
    char name[50];
    cin>>name;
    int i=0;
    
    while(name[i]!='\0'){
        i++;
    }
    cout<<"length of string is "<<i;
    return 0;

}