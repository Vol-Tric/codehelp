#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int>doors(int numDoor , int numPerson){
        vector<bool>door(numDoor+1 , false);

        for(int i=1 ; i<=numPerson ; i++){
            cout<<"person "<<i<<endl;
            for(int j = 1 ; j<=numDoor ; j++){
                if(j%i == 0){
                    door[j] = !door[j];
                }
                
                
                if(door[j]){
                    cout<<j<<" ";
                }
                
            }
            cout<<endl;
        }

        vector<int>ans;
        for(int i=1 ; i<=numDoor ; i++){
            if(door[i]){
                ans.push_back(i);
            }
        }

        return ans;
    }
};

int main(){
    int numDoor = 100;
    int numPerson = 100;
    Solution obj;
    vector<int>ans = obj.doors(numDoor , numPerson);

    for(auto i : ans){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}