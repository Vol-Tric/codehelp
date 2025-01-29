#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void swap(int &a , int &b){

        // we know a ^ a = 0

        a = a ^ b;
        b = a ^ b; // b = (a ^ b) ^ b => b = a ^ 0 => b = a;
        a = a ^ b; // a = (a ^ b) ^ b => a = (a ^ b) ^ a => a = 0 ^ b => a = b;
    }

    bool checkIthBit(int n , int i){
        // n = n >> i;
        // if(n%2 == 0){
        //     return false;
        // }
        // return true;

        if(1 & (n >> i) == 1){
            return true;
        }
        return false;
    }

    int setIthBit(int n , int i){
        int temp = 1;
        temp = temp << i;

        int ans = n | temp;
        return ans;
    }

    int clearIthBit(int n , int i){
        int temp = 1;
        temp = temp << i;
        temp = ~temp;

        int ans = n & temp;
        return ans;
    }

    int toggleIthBit(int n , int i){
        int temp = 1;
        temp = temp << i;
        int ans = n ^ temp; //XOR operation
        return ans;

    }

    int removeLastSetBit(int n){
        int ans = n & (n-1); //n-1 converts every 0 from the right of last set bit to and converts the last set bit to 0 
        // if n = 8 (1000) then n-1 = 7(0111)
        return ans;
    }

    bool checkPowerOfTwo(int n){
        int ans = n & (n-1);
        if(ans == 0){
            return true;
        }
        return false;
    }

    int countNumberOfSetBits(int n){
        int count = 0;
        // while(n > 0){
        //     // // 1st way
        //     // if(n%2 != 0){
        //     //     count++;
        //     // }

        //     // // 2nd way
        //     // if(n & 1 == 1){
        //     //     count++;
        //     // }

        //     // 3rd way
        //     count += n & 1;

        //     n = n >> 1;
        // }


        while(n != 0){//use remove last set bit method
            n = n & (n-1);
            count++;
        }
        return count;
    }

    int MaxBitsFlipForConversion(int n1 , int n2){

        // step 1 : XOR both start and end
        int temp = n1 ^ n2; // it will give 1 to every mismatched bit

        // step 2 : count set bits in XOR
        int ans = countNumberOfSetBits(temp);
        return ans;
    }

    vector<vector<int>>PowerSet(vector<int>nums){
        int n = nums.size();
        int len = 1 << n;

        vector<vector<int>>ans;

        for(int i = 0 ; i < len ; i++){
            vector<int>temp;
            // int checkLen = countNumberOfSetBits(i);
            for(int j = 0 ; j<n ; j++){
                if(i & (1 << j)){
                    temp.push_back(nums[j]);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }

    int bitsDivide(int dividend , int divisor){
        int quotient = 0;
        int count = 1;
        while(dividend >= divisor){
            dividend = dividend >> 1;
            quotient += count;
            count = count * 2;
        }
        return quotient;
    }

};


int main(){
    int n1 = 13;
    int n2 = 7;

    int ans1 = n1 & n2; //AND

    int ans2 = n1 | n2; //OR

    int ans3 = n1 ^ n2; //XOR

    int ans4 = n1 >> 1; //Right shift ( divide by 2 ), 1 means that right shift 1 time. If n1 >> 2 , i.e. right shift 2 times

    int ans5 = n1 << 1; //left shift (multiply by 2) , 1 means that left shift by 1.

    int ans6 = ~n1; //NOT operator, computer stores a -ve number by creating a 2's complement of it . So whenever a number is passed for ~ , first the bits are fliped(1 -> 0 and 0 -> 1) , then the number is checked  , if it is -ve , 2's complement is carried out , else, the number is returned

    int ans7 = ~ans6;

    Solution obj;


    // obj.swap(n1 , n2);
    // cout<< n1 << " , " << n2 << endl;

    // bool ans8 = obj.checkIthBit(n1 , 1);
    // (ans8) ? cout<<"true" : cout<<"false";

    // int n = 9;
    // int ans = obj.setIthBit(n , 2);
    // cout<<"before: "<<n<<" after: "<<ans<<endl;

    // int n = 13;
    // int ans = obj.clearIthBit(n , 2);
    // cout<<"before: "<<n<<" after: "<<ans<<endl;

    // int n = 13;
    // int ans = obj.toggleIthBit(n , 1);
    // cout<<"before: "<<n<<" after: "<<ans<<endl;

    // int n = 40;
    // int ans = obj.removeLastSetBit(n);
    // cout<<"before: "<<n<<" after: "<<ans<<endl;

    // int n = 30;
    // bool ans = obj.checkPowerOfTwo(n);
    // (ans) ? cout<<"true" : cout<<"false";

    // int n = 7;
    // int ans = obj.countNumberOfSetBits(n);
    // cout<<"before: "<<n<<" after: "<<ans<<endl;

    // int start = 10;
    // int end = 7;
    // int ans = obj.MaxBitsFlipForConversion(start , end);
    // cout<<"answer is : "<<ans<<endl;

    // vector<int>nums = {1,2,3};
    // vector<vector<int>>ans = obj.PowerSet(nums);
    // for(auto i : ans){
    //     cout<<"[ ";
    //     for(auto j : i){
    //         cout<< j << " ";
    //     }
    //     cout<<"]"<<endl;
    // }

    // int dividend = 24;
    // int divisor = 3;
    // int ans = obj.bitsDivide(dividend , divisor);
    // cout<<"answer is : "<<ans<<endl;


    string a = "abcdefghijk";
    reverse(a.begin() , a.end());
    cout<<a<<endl;
    return 0;
}