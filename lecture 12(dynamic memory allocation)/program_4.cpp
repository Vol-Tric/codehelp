// void pointer
#include<iostream>
using namespace std;

// int main(){
//     int i=50;
//     int *ptr1=&i;
//     void *ptr2;
//     ptr2=ptr1;
//     cout<<*(int*)ptr2<<endl;
//     return 0;

// }


int main() {
    // Declare variables of different types
    int intValue = 42;
    double doubleValue = 3.14;
    char charValue = 'A';

    // Declare a void pointer
    void *genericPointer;

    // Assign the address of an int variable to the void pointer
    genericPointer = &intValue;

    // Dereference the void pointer and cast it to int to retrieve the value
    int retrievedIntValue = *(int*)genericPointer;

    // Output the result
    cout << "Value stored in int variable: " << retrievedIntValue << endl;

    // Assign the address of a double variable to the void pointer
    genericPointer = &doubleValue;

    // Dereference the void pointer and cast it to double to retrieve the value
    double retrievedDoubleValue = *(double*)genericPointer;

    // Output the result
    cout << "Value stored in double variable: " << retrievedDoubleValue << endl;

    // Assign the address of a char variable to the void pointer
    genericPointer = &charValue;

    // Dereference the void pointer and cast it to char to retrieve the value
    char retrievedCharValue = *(char*)genericPointer;

    // Output the result
    cout << "Value stored in char variable: " << retrievedCharValue << endl;

    return 0;
}
