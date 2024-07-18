// fractional knapsack
#include<bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};

class Solution {
    static bool cmp(pair<double , Item>a , pair<double , Item>b){
        return a.first > b.first;
    }
  public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n) {
        // Your code here
        vector<pair<double , Item>>v;

        for(int i=0 ; i<n ; i++){
            double perUnitValue = (1.0*arr[i].value)/arr[i].weight;
            v.push_back(make_pair(perUnitValue , arr[i]));
        }

        sort(v.begin() , v.end() , cmp);

        double totalValue = 0;
        
        for(int i=0 ; i<n ; i++){
            if(w == 0){
                break;
            }
            if(v[i].second.weight > w){
                // only fraction of the item
                totalValue += w * v[i].first; //only w units of weight is left
                w = 0;
            }
            else{
                // full item
                totalValue += v[i].second.value;
                w -= v[i].second.weight;
            }
        }
        return totalValue;
    }
};

int main(){
    int n = 3;
    int w = 50;
    Item arr[n];
    arr[0].value = 60 , arr[0].weight = 10;
    arr[1].value = 100 , arr[1].weight = 20;
    arr[2].value = 120 , arr[2].weight = 30;

    Solution obj;
    double ans = obj.fractionalKnapsack(w , arr , n);
    cout<<"answer is : "<<ans<<endl;
    return 0;
}