//           1 
//         1 2 3
//       1 2 3 4 5
//     1 2 3 4 5 6 7
//   1 2 3 4 5 6 7 8 9
// 1 2 3 4 5 6 7 8 9 10 11
// 36
#include<iostream>
using namespace std;
int main(){
    int n=6;
    int sum=0;
    for(int i=1;i<=n;++i){
        for(int space=n-i-1;space>=0;space--){
            cout<<"  ";
        }
        int k=1;
        while(k!=2*(i)){
            cout<<k<<" ";
            ++k;
            sum++;
        }
        cout<<endl;

    }
    cout<<sum;
    return 0;
}