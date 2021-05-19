#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <unistd.h>
#include <ctime>
#include <sys/prctl.h>

using namespace std;

int main(void)
{
    int forkRet = fork();
    int count = 0;
    if (forkRet < 0)
    { //error
        exit(1);
    }
    else if (forkRet == 0)
    { //Child process
        char xClock[] = "/usr/bin/xclock /usr/share/man/man1/xclock.1.gz";
        char *args[] = {xClock, NULL};
        execv(args[0], args);
        prctl(PR_SET_NAME, "myXclock");
    }
    else
    { //Parent process
        while (true)
        {
            time_t now = time(0);
            tm *ltm = localtime(&now);
            count++;
            cout << "[" << 1900 + ltm->tm_year << ":" ;
            cout << setfill('0') << setw(2) << 1 + ltm->tm_mon << ":";
            cout << setfill('0') << setw(2) << ltm->tm_mday << "]";
            cout << setfill('0') << setw(2) << ltm->tm_hour << ":";
            cout << setfill('0') << setw(2) << ltm->tm_min << ":";
            cout << setfill('0') << setw(2) << ltm->tm_sec << "\n";
            if (count % 3 == 0)
            {
                cout << "\"This program has gone on for far too long. Type Ctrl+C to abort this timer application.\"\n";
            }
            sleep(10);
        }
    }
    return 0;
}
