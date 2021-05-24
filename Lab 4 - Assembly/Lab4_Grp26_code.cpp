
#include <iostream>

using namespace std;

int binMult(int a, int b) 
{
    int product = 0;
    while ( b != 0) {
            if ( (b&1) == 1) {
                    product += a;
            }
            a <<= 1;
            b >>= 1;
    }
    return product;
}

int main()
{   
    while(true)
    {
        int a, b, cont, res = 0;   
        cout << "\nWelcome to the Binary Multiplicator!\n";
        cout << "Enter First Integer: ";
        cin >> a;
        cout << "Enter Second Integer: ";
        cin >> b;
        res = binMult(a,b);
        cout << "The product is: " << res << "\n";
        

        cout << "1 - Yes\n";
        cout << "0 - No\n ";
        cout << "Continue?: ";
        cin >> cont;
        if (cont == 0)
        {
            break;
        }
        else
        {
            continue;
        }
    }

};
