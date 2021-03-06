#include <vector>

using namespace std;

bool compPriority(const vector<int> &a,const vector<int> &b)
{
    return a[2] < b[2];
}

void doProcessP(vector<vector<int>> processVec, int numProcess)
{
    int finProcess = 0;
    int worldTime = 0;
    int procTime = 0;
    int total = 0;
    int totalCPU = 0;
    const int numProcessConst = numProcess;

    vector<vector<int>> arrivedVec;
    vector<int> solving;
    vector<int> waitingTimes;
    vector<int> burstTimes;
    vector<int> arrivalTimes;
    vector<int> startTimes;

    //Filling Vectors for Output
    for (int i = 0; i < numProcess; i++)
    {
        totalCPU += processVec[i][1];
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

        //Solve Processes
        sort(arrivedVec.begin(), arrivedVec.end(), compPriority);

        //If no process in CPU
        if (solving.empty() && !arrivedVec.empty())
        {
            //add first process to CPU
            solving = arrivedVec[0];
            arrivedVec.erase(arrivedVec.begin());
        }
        //if ArrivedVec process is faster than process CPU (Premption)
        if (arrivedVec[0][2] < solving[2] && !arrivedVec.empty())
        {
            cout << worldTime - procTime<< " " << solving[3] << " " << procTime << "\n";
            arrivedVec.push_back(solving);
            solving = arrivedVec[0];
            arrivedVec.erase(arrivedVec.begin());
            procTime = 0;
        }

        //If process in CPU
        if (!solving.empty())
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
            waitingTimes[arrivedVec[i][3]-1] ++;
        }
        worldTime++;
    }
    //Total Stats
    cout << "Total time elapsed: " << worldTime << "ns\n";
    cout << "Total CPU burst time: " << totalCPU << "ns\n";
    totalCPU = ( static_cast<float>(totalCPU) / static_cast<float>(worldTime) ) *100;
    cout << "CPU Utilization: " << totalCPU << "%\n";
    cout << "Throughput: " << static_cast<float>(numProcessConst) / static_cast<float>(worldTime);
    cout << " processes/ns" <<"\n";

    //Waiting Times
    cout << "Waiting Times: \n";
    for (int i = 0; i < numProcessConst; i++)
    {
        cout << " Process " << i + 1 << ": " << waitingTimes[i] << "ns\n";
        total += waitingTimes[i];
    }
    cout << "Average waiting time: " << static_cast<float>(total) /static_cast<float>(numProcessConst) << "ns\n";
    
    //Turnaround Times
    cout << "Turnaround Times: \n";
    total = 0;
    for (int i = 0; i < numProcessConst; i++)
    {
        cout << " Process " << i + 1 << ": " << waitingTimes[i] + burstTimes[i]<< "ns\n";
        total += waitingTimes[i] + burstTimes[i];
    }
    cout << "Average turnaround time: " << static_cast<float>(total) /static_cast<float>(numProcessConst) << "ns\n";

    //Response Times
    cout << "Response Times: \n";
    total = 0;
    for (int i = 0; i < numProcessConst; i++)
    {
        cout << " Process " << i + 1 << ": " << startTimes[i] - arrivalTimes[i]<< "ns\n";
        total +=  startTimes[i] - arrivalTimes[i];
    }
    cout << "Average Response time: " << static_cast<float>(total) /static_cast<float>(numProcessConst) << "ns";
}