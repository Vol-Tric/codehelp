// book allocation problem
// Given an array 'arr' of integer numbers, where 'arr[i]" represents the number of pages in the 'i-
// th' book. There are 'm' number of students and the task is to allocate all the books to their
//  students. Allocate books in such a way that:
//  1. Each student gets at least one book.
//  2. Each book should be allocated to a student.
//  3. Book allocation should be in a contiguous manner.
// You have to allocate the book to 'm' students such that the maximum number of pages
//  assigned to a student is minimum.
// Example:
//  Let's consider 'n=4' (number of books) and 'm=2' (number of students).
//  'arr = (10, 20, 30, 40 ).
// all possible way to allocate 4 books between 2 students as per the conditions are 
// {10} {20,30,40}
// {10,20} {30,40}
// {10,20,30} {40}
#include <iostream>
#include <vector>
using namespace std;
bool isPossible(vector<int>arr,int n,int m,int mid){
    int studentCount=1;
    int pageSum=0;

    for(int i=0;i<n;i++){
        if(pageSum+arr[i]<=mid){
            pageSum+=arr[i];
        }
        else{
            studentCount++;
            if(studentCount>m||arr[i]>mid){
                return false;
            }
            pageSum=arr[i];
        }
        if(studentCount>m){
            return false;
        }
    }
    return true;


}
int allocateBooks(vector<int>arr,int n,int m){
    int start=0;
    int sum=0;
    for(int i=0;i<n;i++){
        sum=sum+arr[i];
    }
    int end=sum;
    int mid=start+(end-start)/2;
    int ans=-1;
    while(start<=end){
        if(isPossible(arr,n,m,mid)){
            ans=mid;
            end=mid-1;
        }
        else{
            start=mid+1;

        }
        mid=start+(end-start)/2;
    }
    return ans;
}

int main(){
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    // m= number of students;
    int m=2;
    // n=number of books;
    int n=v.size();
    for(int i=0;i<n;i++){
        cout<<v[i]<<endl;
    }
    int ans=allocateBooks(v,n,m);
    cout<<ans<<endl;
    return 0;

}