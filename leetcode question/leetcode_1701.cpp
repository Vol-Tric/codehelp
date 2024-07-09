// average waiting time
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // double averageWaitingTime(vector<vector<int>>& customers) {
    //     double ans = 0;
    //     int prevWaitingTime = 1;
    //     int currWaitingTime = 0;

    //     for(auto i : customers){
    //         currWaitingTime = i[1] + prevWaitingTime;
    //         ans += (currWaitingTime - i[0]  );
    //         prevWaitingTime +=  i[1];
            
    //     }
        
    //     ans = ans / customers.size();
    //     return ans;
    // }

    double averageWaitingTime(vector<vector<int>>& customers) {
        double total_waiting_time = 0;
        int current_time = 0;

        for (const auto& customer : customers) {
            int arrival = customer[0];
            int service = customer[1];
            if (current_time < arrival) {
                current_time = arrival;
            }
            int waiting_time = current_time - arrival + service;
            total_waiting_time += waiting_time;
            current_time += service;
        }

        return total_waiting_time / customers.size();
    }
};

int main(){
    vector<vector<int>>customers = {{1,2} , {2,5} , {4,3}};
    Solution obj;
    double ans = obj.averageWaitingTime(customers);
    cout<<"answer is : "<<ans<<endl;
    return 0;
}