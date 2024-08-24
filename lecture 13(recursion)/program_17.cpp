// merge sort using recursion
#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    void merge(vector<int>& nums, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        vector<int> leftArray(n1);
        vector<int> rightArray(n2);

        for (int i = 0; i < n1; i++) {
            leftArray[i] = nums[left + i];
        }
        for (int j = 0; j < n2; j++) {
            rightArray[j] = nums[mid + 1 + j];
        }

        int i = 0, j = 0, k = left;

        while (i < n1 && j < n2) {
            if (leftArray[i] <= rightArray[j]) {
                nums[k] = leftArray[i];
                i++;
            } else {
                nums[k] = rightArray[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            nums[k] = leftArray[i];
            i++;
            k++;
        }

        while (j < n2) {
            nums[k] = rightArray[j];
            j++;
            k++;
        }
    }

    void mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) {
            return;
        }

        int mid = left + (right - left) / 2;

        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        merge(nums, left, mid, right);
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};


int main(){
    vector<int>arr = {2,3,5,1,6,4,7,4,8,6,9,3};
    
    cout<<"before sorting"<<endl;
    for(auto i : arr){
        cout<<i<<" ";
    }
    cout<<endl;

    Solution obj;

    obj.sortArray(arr);

    cout<<"after sorting"<<endl;
    for(auto i : arr){
        cout<<i<<" ";
    }
    return 0;

}