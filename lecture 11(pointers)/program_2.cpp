// pointer with char
#include<iostream>
using namespace std;

int main(){
    int arr[5]={2,33,4,55,6};
    char cr[6]="abcde";

    cout<<arr<<endl;
    cout<<cr<<endl;
    // this implies that for char, cout prints the output entirely
    cout<<endl;

    char *c=&cr[0];
    cout<<c<<endl;
    // similarly the pointer in the char also give the whole output as the cout function works differently for char
    cout<<endl;

    char ch='j';
    char *ptr=&ch;
    cout<<ptr<<endl;
    // some random character are printed after J it till a NULL (\0) is found by the compiler as char need NULL to terminate
    cout<<endl;

    


}