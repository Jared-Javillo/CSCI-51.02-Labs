#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main(int argc, char* argv[]) {

// just use execv to run ANY program

    //if(execv( "/usr/bin/gedit", argv ) == -1) {
    // error
    if(execl("/usr/bin/gedit", "REALLY NOT GEDIT", NULL)){
        cout << "Error. Booooo!" << endl;
    }

        cout << "Will this line still be printed?" << endl;

}