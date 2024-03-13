// palindrome

#include<iostream>
using namespace std;
int count_string(char name[]){
    int i=0,count=0;
    while(name[i]!='\0'){
        count++;
        i++;
    }
    return count;
}
void reverse(char name[],int count){
    
    int start=0;
    int end=count-1;
    while(start<end){
        swap(name[start++],name[end--]);
    }
    cout<<name;
}
bool check_palindrome(char name[],int count){
    int start=0;
    int end=count-1;
    while(start<end){
        if(name[start]!=name[end]){
            return false;
            
            
        }
        else{
            start++;
            end--;
        }
    }
    return true;
}
int main(){
    char name[50];
    cin>>name;
    int count=count_string(name);
    bool check=check_palindrome(name,count);
    cout<<check;
    return 0;

}