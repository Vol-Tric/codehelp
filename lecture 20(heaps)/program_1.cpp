#include<bits/stdc++.h>
using namespace std;

class Heap{
    public:
    int arr[100];
    int size=0;

    void insert(int data){
        ++size;
        int index = size;
        arr[index] = data;

        while(index > 1){
            int parent = index/2;

            if(arr[parent] < arr[index]){
                swap(arr[parent] ,arr[index]);
                index = parent;
            }
            else{
                return ;
            }
        }
    }
    void deletion(){
        if(size == 0){
            cout<<"Heap empty"<<endl;
            return;
        }
        else{
            // step1
            swap(arr[1],arr[size]);

            // step2
            size--;

            // step3
            int i=1;
            while(i<size){
                int leftIndex = 2*i;
                int rightIndex = 2*i + 1;

                if(leftIndex < size && arr[i] < arr[leftIndex]){
                    swap(arr[i] , arr[leftIndex]);
                    i = leftIndex;
                }

                else if(rightIndex < size && arr[i] < arr[rightIndex]){
                    swap(arr[i] , arr[rightIndex]);
                    i = rightIndex;
                }
                else{
                    return;
                }
            }
        }
    }

    void print(){
        if(size == 0){
            cout<<"Empty heap"<<endl;

        }
        else{
            for(int i=1;i<=size;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
    }
};



int main(){
    Heap obj;
    obj.insert(60);
    obj.insert(50);
    obj.insert(40);
    obj.insert(30);
    obj.insert(20);
    obj.insert(10);
    

    obj.print();

    obj.deletion();
    obj.print();
    return 0;
}