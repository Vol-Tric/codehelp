#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int minDelete(int n , int m , int h , vector<int>villan){
        int tempH = h;
        int count = 0;
        for(int i = n - 1 ; i >= 0 ; i--){
            if(villan[i] > tempH){
                m--;
            }
            else if(villan[i] < tempH){
                tempH = tempH - villan[i];
            }
            else{
                tempH = h;
                m--;
            }

            count++;
            if(m == 0){
                break;
            }
        }

        return n - count ;
    }
    
};

int main(){
    int n = 5;
    int m = 1;
    int h = 4;
    vector<int>villans = {1,2,3,1,3};
    Solution obj;
    int ans = obj.minDelete(n , m , h , villans);

    cout<<"answer is : "<<ans<<endl;
    return 0;
}