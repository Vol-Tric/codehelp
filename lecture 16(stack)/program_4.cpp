// remove middle element of stack

#include <bits/stdc++.h> 
using namespace std;

void solve(stack<int>&inputStack, int count, int size){
   // base case, middle element reached
   if(count==size/2){
      inputStack.pop();
      return;
   }

    // store the top element
   int num=inputStack.top();
   inputStack.pop();

   //recursive call
   solve(inputStack, count+1, size);

    // again put the stored element on the top
   inputStack.push(num);
   
}

void deleteMiddle(stack<int>&inputStack, int N){
	
   int count=0;
   solve(inputStack, count, N);
   
}

int main(){
    
    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    

    deleteMiddle(s, s.size());

    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }

    return 0;
}