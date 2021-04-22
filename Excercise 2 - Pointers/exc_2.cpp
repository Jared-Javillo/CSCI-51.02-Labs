#include <iostream>
using namespace std;

int main(void) {
    int i; // "regular" variable
    int *p; // pointer to an int variable
    p = &i; // & = "address of"
    i = 2;

    cout <<"int i: "<< i << endl;
    cout << "pointer p: "<< *p << endl;
    cout << "address of i: " << &i << endl;
    cout << "dereference p:" << *p << endl; 
}