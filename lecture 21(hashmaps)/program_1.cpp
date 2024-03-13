// intorduction to maps

#include<bits/stdc++.h>
using namespace std;

int main(){
    unordered_map<string,int> m;

    // insertion 
    // method 1
    pair<string,int> pair1 = make_pair("hello",1);
    m.insert(pair1);

    // method 2
    pair<string,int> pair2("welcome",2);
    m.insert(pair2);

    // method 3
    m["dashmeet"] = 3;

    // search
    cout<< m["hello"]<<endl;
    cout<< m.at("welcome")<<endl;


    // it creates a nentry into the map and gives the ans zero
    cout<< m["unknown"]<<endl;

    cout<<m.size()<<endl;

    m.erase("unknown");
    cout<<m.size()<<endl;

    // to check presense , bool
    cout<<m.count("dashmeet")<<endl;
    cout<<m.count("unknown")<<endl;

    cout<<endl;


    // traverse whole map
    // method 1
    for(auto i:m){
        cout<<i.first<<"  "<<i.second<<endl;
    }

    cout<<endl;
    
    // method 2, using iterator
    unordered_map<string,int> :: iterator it = m.begin();
    while(it != m.end()){
        cout<<it->first<<"  "<<it->second<<endl;
        it++;
    }
    

    return 0;
}