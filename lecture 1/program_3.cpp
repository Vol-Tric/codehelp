// prime number between 0 & N(user entered)
#include <iostream>
using namespace std;
bool prime(int n){
    
    if(n==0||n==1){
        return false;    
    }
    else{
        for(int i=2;i<=n/2;i++){
            if(n%i==0){
                return false;
            }
        }
    }

    return true;
}
int main(){
    cout<<"Enter the number:";
    int n;
    bool check;
    cin>>n;
    for(int i=1;i<=n;i++){
        check=prime(i);
        if(check){
            cout<<i<<" is a prime number"<<endl;
        }
    }
    return 0;
}