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
    int worldTime = 0;
    int procTime = 0;
    int cPUBurst = 0;
    int total = 0;
    const int numProcessConst = numProcess;

    vector<vector<int>> arrivedVec;
    vector<int> solving;
    vector<int> waitingTimes;
    vector<int> burstTimes;
    vector<int> arrivalTimes;
    vector<int> startTimes;

    for (int i = 0; i < numProcess; i++)
    {
        cPUBurst += processVec[i][1];
        burstTimes.push_back(processVec[i][1]);
        waitingTimes.push_back(0);
        startTimes.push_back(0);
        arrivalTimes.push_back(processVec[i][0]);
    }
    sort(processVec.begin(), processVec.end());
    while(!processVec.empty() || !(arrivedVec.empty()) || !(solving.empty()))
    {
        //Arriving Processes
        for (int i = 0; i < numProcess; i++)
        {
            if (processVec[i][0] <= 0)
            {
                arrivedVec.push_back(processVec[i]);
                processVec.erase(processVec.begin() + i);
                numProcess -= 1;
                i -= 1;
            }
            else
            {
                processVec[i][0] = processVec[i][0] - 1;
            }
        }
        //Solve Processes (arranged by burst times)
        sort(arrivedVec.begin(), arrivedVec.end(), compBurstTime);
        //If no process in CPU
        if (solving.empty() && !arrivedVec.empty())
        {
            //add first process to CPU
            solving = arrivedVec[0];
            arrivedVec.erase(arrivedVec.begin());
        }
        //If process is in CPU
        if(!solving.empty())
        {
            //if its the process's first time
            if (burstTimes[solving[3] - 1] == solving[1])
            {
                startTimes[solving[3] - 1] = worldTime;
            }
            
            //Process is processing
            solving[1] -= 1;
            procTime ++;
            //If process is finished
            if (solving[1] <= 0)
            {
                //delete process from CPU and output
                solving[1] = 0;
                cout << worldTime - procTime +1 << " " << solving[3] << " " << procTime << "x\n";
                solving.clear();
                procTime = 0;
            }
        }

        //Add waiting time for process in arrivedVec
        for (int i = 0; i < arrivedVec.size(); i++)
        {
            waitingTimes[arrivedVec[0][3]-1] ++;
        }

        

        worldTime++;
        
    }
    // sort(processVec.begin()+1, processVec.end(), compBurstTime);
    // //to help get Start time of each process
    // int tempStartTime = processVec[0][0];
    // vector<vector<int>> tempSTVec;
    // vector<int> initiaL;
    // initiaL.push_back(tempStartTime);
    // initiaL.push_back(processVec[0][3]);
    // tempSTVec.push_back(initiaL);
    // cout << tempStartTime <<" "<< processVec[0][3] <<" "<< processVec[0][1]<<"x"<<"\n";
    // for (int i = 1; i < numProcess; i++)
    // {
    //     vector<int> tempHolder;
    //     tempStartTime = tempStartTime + processVec[i-1][1];
    //     cout << tempStartTime <<" "<< processVec[i][3] <<" "<< processVec[i][1]<<"x"<<"\n";
    //     tempHolder.push_back(tempStartTime);
    //     tempHolder.push_back(processVec[i][3]);
    //     tempSTVec.push_back(tempHolder);
    // }
    // //to get total elapsed time of CPU
    // for (int i = 0; i < numProcess; i++)
    // {
    //     if(timePassed < processVec[i][0])
    //     {
    //         timePassed += (processVec[i][0] - timePassed) + processVec[i][1];
    //     }else if(timePassed >= processVec[i][0])
    //     {
    //         timePassed +=  processVec[i][1];
    //     }
    //     cPUBurst += processVec[i][1];
    // }


    cout <<"Total time elapsed: " << worldTime <<"ns\n";
    cout <<"Total CPU burst time: " << cPUBurst <<"ns"<< "\n";
    cPUBurst = ( static_cast<float>(cPUBurst) / static_cast<float>(worldTime) ) *100;
    cout <<"CPU Utilization: "<< cPUBurst << "%\n";
    cout << "Throughput: " << static_cast<float>(numProcessConst) / static_cast<float>(worldTime) << " processes/ns" <<"\n";
    // sort(processVec.begin(), processVec.end(), compProcessNumber);
    // sort(tempSTVec.begin(), tempSTVec.end(), compBurstTime);

    //Waiting time
    cout << "Waiting Times: \n";
    for (int i = 0; i < numProcessConst; i++)
    {
        //cout << " Process " << i+1 << ": " << tempSTVec[i][0] - processVec[i][0] << "ns\n";
        //total = total + (tempSTVec[i][0] - processVec[i][0]);
        cout << " Process " << i + 1 << ": " << waitingTimes[i] << "ns\n";
        total += waitingTimes[i];
    }
    cout << "Average waiting time: " << static_cast<float>(total)/static_cast<float>(numProcessConst) << "ns\n";
    //Turnaround time
    total = 0;
    cout << "Turnaround Times: \n";
    for (int i = 0; i < numProcessConst; i++)
    {
        // cout << " Process " << i+1 << ": " << processVec[i][1]+(tempSTVec[i][0] - processVec[i][0]) << "ns\n";
        // total = total + (processVec[i][1]+(tempSTVec[i][0] - processVec[i][0]));
        cout << " Process " << i + 1 << ": " << waitingTimes[i] + burstTimes[i]<< "ns\n";
        total += waitingTimes[i] + burstTimes[i];
    }
    cout << "Average turnaround time: " << static_cast<float>(total)/static_cast<float>(numProcessConst) << "ns\n";
    //Response time
    total = 0;
    cout << "Response Times: \n";
    for (int i = 0; i < numProcessConst; i++)
    {
        // cout << " Process " << i+1 << ": " << tempSTVec[i][0] - processVec[i][0] << "ns\n";
        // total = total + (tempSTVec[i][0] - processVec[i][0]);
        cout << " Process " << i + 1 << ": " << startTimes[i] - arrivalTimes[i]<< "ns\n";
        total +=  startTimes[i] - arrivalTimes[i];
    }
    cout << "Average response time: " << static_cast<float>(total)/static_cast<float>(numProcessConst) << "ns\n";
}