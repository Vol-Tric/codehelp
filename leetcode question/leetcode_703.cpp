#include<bits/stdc++.h>
using namespace std;

class KthLargest {
    priority_queue<int , vector<int> , greater<int>>arr;
    int index = 0;
public:
    KthLargest(int k, vector<int>& nums) {
        index = k;
        for(auto i : nums){
            arr.push(i);
            if(arr.size() > index){
                arr.pop();
            }
        }
    }
    
    int add(int val) {
        arr.push(val);
        if(arr.size() > index){
            arr.pop();
        }
        return arr.top();

    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

int main(){
    vector<int>nums = {4,5,8,2};

    KthLargest obj(3 , nums);

    cout<<"answers incoming..."<<endl;
    cout<<obj.add(3)<<endl;
    cout<<obj.add(5)<<endl;
    cout<<obj.add(10)<<endl;
    cout<<obj.add(9)<<endl;
    cout<<obj.add(4)<<endl;

    return 0;
}