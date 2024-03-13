// pattern
// 1 2 3 4 5 5 4 3 2 1
// 1 2 3 4 * * 4 3 2 1
// 1 2 3 * * * * 3 2 1
// 1 2 * * * * * * 2 1
// 1 * * * * * * * * 1

#include<iostream>
using namespace std;
int main(){
    int n=5;
    for(int i=0;i<=n-1;i++){
        int count=1;
        int rev_count=n-i;
        // 1st triangle(straight numbers)
        for(int j=n-i;j>=1;j--){
            cout<<count<<" ";
            count++;
        }
        // 2nd triangle(*)
        for(int k=0;k<=2*(i-1);k=k+2){
            cout<<"* * ";
        }
        // 3rd triangle(reversed numbers)
        for(int m=n-i;m>=1;m--){
            cout<<rev_count<<" ";
            rev_count--;
        }
        cout<<endl;
    }
    return 0;
}