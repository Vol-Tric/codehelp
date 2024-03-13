// reverse an array
#include<iostream>
using namespace std;
void print_array(int array[],int num){
    for(int i=0;i<num;i++){
        cout<<array[i]<<" ";
    }
}

void reverse(int array[],int num){
    int start=0;
    int end=num-1;

    while(start<end){
        swap(array[start],array[end]);
        start++;
        end--;
    }
}
int main(){
    int array1[5]={1,2,3,45,5};
    int array2[8]={99,88,77,66,55,44,33,22};

    reverse(array1,5);
    reverse(array2,8);

    print_array(array1,5);
    cout<<endl;
    print_array(array2,8);

    return 0;
}