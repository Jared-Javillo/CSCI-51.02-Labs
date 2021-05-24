#include <vector>

using namespace std;

bool compBurstTime(const vector<int> &a,const vector<int> &b)
{
    return a[1] < b[1];
}

void doProcessSJF(vector<vector<int>> processVec, int numProcess )
{
    int output = 0;
    int timePassed = 0;
    sort(processVec.begin(), processVec.end());
    sort(processVec.begin()+1, processVec.end(), compBurstTime);
    int tempCompletionTime = processVec[0][0];
    cout << tempCompletionTime <<" "<< processVec[0][3] <<" "<< processVec[0][1]<<"x"<<"\n";
    for (int i = 1; i < numProcess; i++)
    {
        tempCompletionTime = tempCompletionTime + processVec[i-1][1];
        cout << tempCompletionTime <<" "<< processVec[i][3] <<" "<< processVec[i][1]<<"x"<<"\n";
    }
    for (int i = 0; i < numProcess; i++)
    {
        if(timePassed < processVec[i][0])
        {
            timePassed += (processVec[i][0] - timePassed) + processVec[i][1];
        }else if(timePassed >= processVec[i][0])
        {
            timePassed +=  processVec[i][1];
        }
        output += processVec[i][1];
    }
    cout <<"Total time elapsed: " << timePassed <<"ns\n";
    cout <<"Total CPU burst time: " << output <<"ns"<< "\n";
    output = ( static_cast<float>(output) / static_cast<float>(timePassed) ) *100;
    cout <<"CPU Utilization: "<< output << "%\n";
    cout << "Throughput: " << static_cast<float>(numProcess) / static_cast<float>(timePassed) << " processes/ns" <<"\n";
    
}