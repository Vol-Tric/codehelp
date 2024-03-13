// Jaggered Array
// A jagged array is an array of arrays such that member arrays can be of different sizes, in 2D array terms for each row we can have a variable number of columns. These types of arrays are also known as Jagged arrays. 
// arr[3][] = 1 2 3 4        // arr[0][4] : 1st row have 4 columns
//            5 6            // arr[1][2] : 2nd row have 2 columns
//            7 8 9          // arr[2][3] : 3rd row have 3 columns

#include<iostream>
using namespace std;

int main(){
    int m;
    cin>>m;
    int *sizes=new int[m];
    // sizes is an array that store length of eacch column for later use
    int **array=new int*[m];
    for(int i=0;i<m;i++){
        int n=0;
        cout<<"enter no. of elements of this column:";
        cin>>n;
        sizes[i]=n;
        array[i]=new int[n];
        for(int j=0;j<n;j++){
            cin>>array[i][j];
        }
    }
    // creating of jaggered array

    cout<<endl;

    for(int i=0;i<m;i++){
        for(int j=0;j<sizes[i];j++){
            cout<<array[i][j]<<" ";
        }
        cout<<endl;

    }
    // printing of jaggered array

    for(int i=0;i<m;i++){
        delete []array[i];
    }
    delete []array;
    // deletion of array
    return 0;
}