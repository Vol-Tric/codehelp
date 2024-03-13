// inheritence
#include<bits/stdc++.h>
using namespace std;

class Human{

public:
    int height=100;
    int weight;

    int getHeight(){
        return this->height;
    }

    int getWeight(){
        return this->weight;
    }

    void setWeight(int weight){
        this->weight=weight;
    }
};

class Male: public Human{
public:
    string color;

    void sleeping(){
        cout<<"sleeping"<<endl;
    }

};

int main(){
    Human h1;
    Male m1;
    h1.setWeight(50);
    cout<<h1.getHeight()<<endl;
    cout<<h1.getWeight()<<endl;
    

    m1.sleeping();
    cout<<m1.getHeight()<<endl;
    m1.setWeight(40);
    cout<<m1.getWeight()<<endl;
    return 0;
}