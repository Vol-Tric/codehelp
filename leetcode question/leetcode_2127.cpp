#include<bits/stdc++.h>
using namespace std;


class Solution{
    public:
    int maximumInvitations(vector<int>& fav){
        int n = fav.size();
        vector<int> inDegree(n , 0) , chainLen(n , 0);
        vector<bool> visited(n , false);

        for(auto i : fav){
            inDegree[i]++;
        }

        queue<int>q;
        for(int i=0 ; i<n ; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            visited[node] = true;

            int next = fav[node];
            chainLen[next] = chainLen[node] + 1;
            inDegree[next]--;
            if(inDegree[next] == 0){
                q.push(next);
            }
        }

        int maxCycle = 0 , totalChains = 0;
        for(int i=0 ; i<n ; i++){
            if(!visited[i]){
                int current = i , cycleLen = 0;
                while(!visited[current]){
                    visited[current] = true;
                    current = fav[current];
                    cycleLen++;
                }

                if(cycleLen == 2){
                    totalChains += 2 + chainLen[i] + chainLen[fav[i]];
                }
                else{
                    maxCycle = max(maxCycle , cycleLen);
                }
            }
        }
        return max(maxCycle , totalChains);
    }
};

int main(){
    vector<int>fav = {2,2,1,2};
    Solution obj;
    int ans = obj.maximumInvitations(fav);
    cout<<"answer is : "<<ans<<endl;
    return 0;
}