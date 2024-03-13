// to check whether UPPER or Lower
#include <iostream>
using namespace std;
int main(){
    cout<<"enter the character: ";
    char ch;
    cin>>ch;
    if(isupper(ch)){
        cout<<"UPPER"<<endl;
    }
    else if(islower(ch)){
        cout<<"lower"<<endl;
    }
    else{
        cout<<"other"<<endl;

    }
    return 0;
}