#include<iostream>
using namespace std;
int main(){
    int n=234;
    int product=1,sum=0;
    while(n>0){
        sum=sum+(n%10);
        product=product*(n%10);
        n=n/10;
    }
    cout<<product-sum;
    
    return 0;
}