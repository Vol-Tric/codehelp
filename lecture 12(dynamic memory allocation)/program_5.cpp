// 2D array using dynamic memory allocation
#include<iostream>
using namespace std;

int main(){
    int m,n;
    cin>>m>>n;
    int **matrix= new int*[n];
    for(int i=0;i<m;i++){
        matrix[i]=new int[n];
    } 
    // creation of  2D array using dynamic memory allocation
    // **matrix= new int*[n]; , this is the main step in allocating memory
    // first we create a array in heap of length n consisting pointers only and a pointer to its index in stack used to locate it in heap
    // next we run a loop to create an array of length n for each of the pointer present in the initial array
    // this way we can create a 2D array
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
        }
    }
    // entering element

    cout<<endl;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    // printing elements

    for(int i=0;i<m;i++){
        delete []matrix[i];
    }
    // first we delete the array at whom the pointer array was pointing
    delete []matrix;
    // second we delete the pointer array
    // in this way deaalocation of memory is also done for heap
    // it is carried out in this order only because if we first delete the pointer array, then we don't know the location of the rest of the arrays

    return 0;


}