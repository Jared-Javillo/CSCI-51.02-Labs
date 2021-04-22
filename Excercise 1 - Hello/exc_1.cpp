#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    for(int i = argc - 1; i > 0; i--)
    {
        cout << "arg" << i << ": " << argv[i];
        //cout << endl; // cout << "\n";
        printf("%c\n", argv[i][0]);
        printf("%s\n", argv[i]+1);
    }
    return 0; // non-zero means an error
}