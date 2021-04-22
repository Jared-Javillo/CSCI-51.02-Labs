#include <iostream>
using namespace std;

int addTwoV1(int x) {
    x += 2;
    return x;
}

int addTwoV2(int* x) {
    *x += 2;
    return *x;
}

void myFunction( ){
    cout << "inside myFunction()\n";
}

int main(void) {
    myFunction( );
    int x = addTwoV1(1);
    cout << x << "\n";
    cout << addTwoV2(&x);
    return 0;
}