#include <vector>

using namespace std;

bool compProcessNumber(const vector<int> &a,const vector<int> &b)
{
    return a[3] < b[3];
}
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
    //to help get Start time of each process
    int tempStartTime = processVec[0][0];
    vector<vector<int>> tempSTVec;
    vector<int> initiaL;
    initiaL.push_back(tempStartTime);
    initiaL.push_back(processVec[0][3]);
    tempSTVec.push_back(initiaL);
    cout << tempStartTime <<" "<< processVec[0][3] <<" "<< processVec[0][1]<<"x"<<"\n";
    for (int i = 1; i < numProcess; i++)
    {
        vector<int> tempHolder;
        tempStartTime = tempStartTime + processVec[i-1][1];
        cout << tempStartTime <<" "<< processVec[i][3] <<" "<< processVec[i][1]<<"x"<<"\n";
        tempHolder.push_back(tempStartTime);
        tempHolder.push_back(processVec[i][3]);
        tempSTVec.push_back(tempHolder);
    }
    //to get total elapsed time of CPU
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
    sort(processVec.begin(), processVec.end(), compProcessNumber);
    sort(tempSTVec.begin(), tempSTVec.end(), compBurstTime);
    //Waiting time
    cout << "Waiting Times: \n";
    int total = 0;
    for (int i = 0; i < numProcess; i++)
    {
        cout << " Process " << i+1 << ": " << tempSTVec[i][0] - processVec[i][0] << "ns\n";
        total = total + (tempSTVec[i][0] - processVec[i][0]);
    }
    cout << "Average waiting time: " << static_cast<float>(total)/static_cast<float>(numProcess) << "ns\n";
    //Turnaround time
    total = 0;
    cout << "Turnaround Times: \n";
    for (int i = 0; i < numProcess; i++)
    {
        cout << " Process " << i+1 << ": " << processVec[i][1]+(tempSTVec[i][0] - processVec[i][0]) << "ns\n";
        total = total + (processVec[i][1]+(tempSTVec[i][0] - processVec[i][0]));
    }
    cout << "Average turnaround time: " << static_cast<float>(total)/static_cast<float>(numProcess) << "ns\n";
    //Response time
    total = 0;
    cout << "Response Times: \n";
    for (int i = 0; i < numProcess; i++)
    {
        cout << " Process " << i+1 << ": " << tempSTVec[i][0] - processVec[i][0] << "ns\n";
        total = total + (tempSTVec[i][0] - processVec[i][0]);
    }
    cout << "Average response time: " << static_cast<float>(total)/static_cast<float>(numProcess) << "ns";
}