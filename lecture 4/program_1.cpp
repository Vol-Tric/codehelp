// WAP in which an amount is entered and find how many notes of each denomination would be needed to make the amount
// the denomination are of 100, 50, 20, 1
#include<iostream>
using namespace std;
int main(){
    int amount=1330;
    int hundred=0,fifty=0,twenty=0,one=0,remainder;
    while(amount>0){
        hundred=amount/100;
        amount=amount%100;

        fifty=amount/50;
        amount=amount%50;

        twenty=amount/20;
        amount=amount%20;

        one=amount/1;
        amount=amount%1;    
    }
    cout<<"no. of hundreds note are: "<<hundred<<endl;
    cout<<"no. of fifty note are: "<<fifty<<endl;
    cout<<"no. of twenty note are: "<<twenty<<endl;
    cout<<"no. of one note are: "<<one<<endl;

    return 0;
}