// median of 2 sorted arrays

#include<bits/stdc++.h>
using namespace std;

class Solution {
    void merge(vector<int> nums1 , vector<int> nums2 , int n1 , int n2 , vector<int>&nums3){
        int i=0;
        int j=0;

        while(i<n1 && j<n2){
            if(nums1[i] < nums2[j]){
                nums3.push_back(nums1[i]);
                i++;
            }
            else{
                nums3.push_back(nums2[j]);
                j++;
            }
        }

        while(i < n1){
            nums3.push_back(nums1[i]);
            i++;
        }

        while(j < n2){
            nums3.push_back(nums2[j]);
            j++;
        }
    }

public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums3;
        merge(nums1 , nums2 , nums1.size() , nums2.size() , nums3);

        int size = nums3.size();
        double ans;

        // odd size
        if(size%2 != 0){
            ans = nums3[size/2];
        }
        // even size
        else if(size%2 == 0){
            int mid = size/2;
            double temp = nums3[mid - 1] + nums3[mid];
            ans = temp/2;
        }
        return ans;
    }
};

int main(){
    int arr1[2]={1,2};
    int n1=2;
    vector<int>v1;

    int arr2[2]={3,4};
    int n2=2;
    vector<int>v2;

    for(int i =0;i<n1;i++){
        v1.push_back(arr1[i]);
    }
    for(int i =0;i<n2;i++){
        v2.push_back(arr2[i]);
    }

    Solution obj;

    double ans = obj.findMedianSortedArrays(v1 , v2);
    cout<<ans<<endl;
    return 0;
}