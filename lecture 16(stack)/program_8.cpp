// sort elements of stack using recursion
#include <bits/stdc++.h>
using namespace std;

void SortedInsert(stack<int> &stack, int num){
	if(stack.empty()){
		stack.push(num);
		return;
	}

	int top=stack.top();
	if(top>num){
		stack.pop();
		SortedInsert(stack, num);
		stack.push(top);
	}
	if(top<=num){
		stack.push(num);
		return ;
	}
}
void sortStack(stack<int> &stack)
{
	if(stack.empty()){
		return;
	}

	
	int num=stack.top();
	stack.pop();
	sortStack(stack);
	SortedInsert(stack, num);
}


int main(){
    stack<int> s;

    s.push(60);
    s.push(40);
    s.push(30);
    s.push(10);
    s.push(50);
    s.push(20);
    
    sortStack(s);

    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
    return 0;
}