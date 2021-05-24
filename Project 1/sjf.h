#include <vector>

using namespace std;

void doProcessSJF(vector<vector<int>> processVec, int numProcess )
{
    int output = 0;
    int timePassed = 0;

    sort(processVec.begin(), processVec.end(),compArrTime);
    for (int i = 0; i < numProcess; i++)
    {
        if(timePassed < processVec[i][0])
        {
            timePassed += (processVec[i][0] - timePassed) + processVec[i][1];
        }else if(timePassed >= processVec[i][0])
        {
            timePassed +=  processVec[i][1];
        }
        cout << processVec[i][0] <<" "<< processVec[i][3] <<" "<< processVec[i][1]<<"x"<<"\n";
    }
}