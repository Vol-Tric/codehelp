// quick sort using recursion
#include<bits/stdc++.h>
using namespace std;


class Solution {
private:
    int partition(vector<int>& nums, int start, int end) {
        int pivot = nums[start];
        int count = 0;

        for (int i = start + 1; i <= end; i++) { // Corrected the loop condition
            if (nums[i] <= pivot) {
                count++;
            }
        }

        int pivot_index = start + count;
        swap(nums[pivot_index], nums[start]);

        int i = start;
        int j = end;

        while (i < pivot_index && j > pivot_index) {
            while (i < pivot_index && nums[i] <= pivot) {
                i++;
            }

            while (j > pivot_index && nums[j] > pivot) {
                j--;
            }

            if (i < pivot_index && j > pivot_index) {
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
        }
        return pivot_index;
    }

    void quickSort(vector<int>& nums, int start, int end) {
        if (start >= end) {
            return;
        }

        int partitionElement = partition(nums, start, end);
        quickSort(nums, start, partitionElement - 1); // Corrected boundary
        quickSort(nums, partitionElement + 1, end);
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
};


int main(){
    vector<int> arr = {2,3,5,1,6,4,7,4,8,6,9,3};
    int len = arr.size();
    cout<<"before sorting"<<endl;
    for(int i=0 ; i<len ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    Solution obj;
    obj.sortArray(arr);
    
    cout<<"after sorting"<<endl;
    for(int i=0 ; i<len ; i++){
        cout<<arr[i]<<" ";
    }
    return 0;

}