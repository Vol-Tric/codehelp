// OOPS
#include<bits/stdc++.h>

using namespace std;

class Hero{
private:
    int health;
    char level;
public:
    char *name;



    Hero(){
        name=new char[100];
    }
    // parameterized constructor
    // this: pointer that stores the address of the current object 
    // this->health means the health of the current object in use
    Hero(int health){
        this->health=health;
    }

    // parameterized constructor with 2 arguments
    Hero(int health, char level){
        this->health=health;
        this- level;
    }

    // manually created copy constructor
    // when we create a copy constructor, the default copy constructor terminates automatically
    // &temp is used to pass by refrence instead of pass by value because it can lead to an infinite loop going between Hero and (Hero temp)
    Hero (Hero &temp){
        this->health=temp.health;
        this->level=temp.level;
    }




    int getHealth(){
        return health;
    }

    char getlevel(){
        return level;
    }

    char getName(){
        return *name;
    }

    void setName(char name[]){
        strcpy(this->name,name);
    }
    
    void setHealth(int h){
        health=h;
    }
       
    void setlevel(char n){
     level=n;
    }
        

};

int main(){
    // // static object
    // Hero h1;
    // h1.setHealth(20);
    // h1.setlevel('A');
    // int health=h1.getHealth();
    // cout<<health<<endl;
    // char level=h1.getlevel();
    // cout< level<<endl;

    // // dynamic object
    // Hero *h2=new Hero;
    // (*h2).setHealth(30);
    // (*h2).setlevel('B');
    
    // cout<<(*h2).getHealth()<<endl;
    // // both (*h2).getHealth() and h2->getlevel() means same as in 1st, we deaalocate the pointer and then applies function using '.', and in second we directly usec dynamic object and point towards the function using '->'
    // cout<<h2->getlevel()<<endl;



    // // creating an object with parameterized constructor
    // // static parameterized object
    // Hero h3(30);
    // cout<<h3.getHealth()<<endl;

    // // parameterized constructor with 2 arguments
    // Hero h4(55,'A');
    // cout<<h4.getHealth()<<endl;
    // cout<<h4.getlevel()<<endl;
    
    // // creating an object with parameterized constructor
    // // dynamic parameterized object
    // Hero *h5 =new Hero(40);
    // cout<<(*h5).getHealth()<<endl;

    // // parameterized constructor with 2 arguments
    // Hero *h6 =new Hero(45,'B');
    // cout<<(*h6).getHealth()<<endl;
    // cout<<h6->getlevel()<<endl;



    // Hero h7(55,'A');
    // cout<<h7.getHealth()<<endl;
    // cout<<h7.getlevel()<<endl;

    // // copy constructor : h8 copies all the values of h7
    // // copy constructor is genetrated automatically but we can also write it
    // Hero h8(h7);
    // cout<<h8.getHealth()<<endl;
    // cout<<h8.getlevel()<<endl;

    // Shallow vs Deep copy;
    // defuault copy constructor uses shallow copy
    Hero h9;
    char name[7]="Babbar";
    h9.setHealth(20);
    h9.setlevel('A');
    h9.setName(name);
    cout<<h9.getHealth()<<endl;
    cout<<h9.getlevel()<<endl;
    cout<<h9.getName()<<endl;

    cout<<endl;

    // default copy constructor
    Hero h10(h9);
    cout<<h10.getHealth()<<endl;
    cout<<h10.getlevel()<<endl;
    cout<<h10.getName()<<endl;


    h9.name[0]='G';

    cout<<h9.getHealth()<<endl;
    cout<<h9.getlevel()<<endl;
    cout<<h9.getName()<<endl;

    cout<<endl;

    cout<<h10.getHealth()<<endl;
    cout<<h10.getlevel()<<endl;
    cout<<h10.getName()<<endl;




    return 0;
}