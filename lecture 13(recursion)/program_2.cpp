// head recursion VS tail recursion
#include<iostream>
using namespace std;

// head recursion
// recursion comes before the process
void head_print(int n){
    if(n==0){
        return ;
    }
    head_print(n-1);
    cout<<n<<endl;
}
// head recursion prints the number in ascending order because if carries out recursion till the base case is true, and then come back to the remaining section of each recursion
// di=one in a form of stack  

// tail recursion
// recursion comes after the process
void tail_print(int n){
    if(n==0){
        return ;
    }
    cout<<n<<endl;
    tail_print(n-1);
}

int main(){
    int n=5;
    head_print(n);
    cout<<endl;
    tail_print(n);
    return 0;

}