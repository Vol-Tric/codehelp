// Say digit
// Eg 1: 412
// output: four one two 

// Eg 2: 213
// output: two one three
#include<iostream>
#include<string>
using namespace std;

void sayDigit(int n, string numbers[]){
    if(n==0){
        return ;
    }
    int digit=n%10;
    
    sayDigit(n/10,numbers);
    cout<<numbers[digit]<<"  ";
}

int main(){
    int n=213;
    
    string numbers[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    sayDigit(n,numbers);
    return 0;

}