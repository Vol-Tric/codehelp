// count power
// here the logic used is if we need to find a^b
// if b is even then ans=2(a^(b/2))
// if b is odd then ans=a*(2(a^(b/2)))
#include<iostream>
using namespace std;

int power(int a,int b){
    // base case
    if(b==0){
        return 1;
    }
    if(b==1){
        return a;
    }
    // recursive call
    int ans=power(a,b/2);

    // if b is even
    if(b%2==0){
        return ans*ans;
    }
    // if b is odd
    else{
        return a*ans*ans;
    }
}


int main(){
    int a=3;
    int b=3;
    
    int ans=power(a,b);
    cout<<ans<<endl;
    return 0;
}