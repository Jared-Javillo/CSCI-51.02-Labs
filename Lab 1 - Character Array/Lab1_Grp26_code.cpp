#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include <ctype.h>

using namespace std;

char alpL[] = "abcdefghijklmnopqrstuvwxyz";
char alpU[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char* aP;

void UppLow(string x){
    char arr[x.length()+1];
    strcpy(arr, x.c_str());
    for(int i = 0; i < x.length(); i++) {
        if(isalpha(arr[i])){
            if(isupper(arr[i])){
                aP = &alpU[25];
                if(arr[i] == *aP){
                    cout << "A";
                }
                else{
                    for(int j = 0; j < strlen(alpU); j++){
                        aP = &alpU[j];
                        if(*aP == arr[i]){
                            cout << alpU[j+1];
                        };
                    };
                };
            }
            else{
                aP = &alpL[25];
                if(arr[i] == *aP){
                    cout << "a";
                }
                else{
                    for(int j = 0; j < strlen(alpL); j++){
                        aP = &alpL[j];
                        if(*aP == arr[i]){
                            cout << alpL[j+1];
                        };
                    };
                };
            };
        }
        else{
            cout << arr[i];
        };
    };
};

int main(void) {
    string name;
    cout << "1. ";
    cin >> name; 
    cout << "2. " << name << "\n";
    cout << "3. "<< name[0];
    for (int i = 1; i < name.length(); i++) {
        cout << "#";
    };
    cout << "\n";
    cout << "4. ";
    UppLow(name);
    return 0;
}