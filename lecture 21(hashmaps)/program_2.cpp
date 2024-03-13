// maximum frequency number
#include<bits/stdc++.h>
using namespace std;

int maximumFrequency(vector<int> &arr, int n)
{
    map<int,int> m;

    int maxFreq = 0;
    int maxAns = INT_MIN;



    for(int i=0;i<n;i++){
        m[arr[i]]++;
        maxFreq = max(maxFreq , m[arr[i]]);
    }

    for(int i=0;i<n;i++){
        if(maxFreq == m[arr[i]]){
            maxAns = arr[i];
            break;
        }
    }
    return maxAns;  
}

int main(){
    int arr[13] = {2, 12, 2, 11, -12, 2, -1, 2, 2, 11, 12, 2, -6};
    int n=13;
    vector<int>v;

    for(int i =0;i<n;i++){
        v.push_back(arr[i]);
    }

    int ans = maximumFrequency(v , n);
    cout<<ans<<endl;
    return 0;

}