#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include <cmath>

using namespace std;

vector<int> IntSplit(char input[100]){
    int count = 0;
    vector<string> inputSplit;
    vector<int> intSplit;
    char* chars_array;

    inputSplit.clear();
    chars_array = strtok(input," ");
    while(chars_array)
    {
        count++;
        inputSplit.push_back(chars_array);
        chars_array = strtok(NULL, " ");
    }
    count = 0;
    for (int i=0; i<= 2; i++)
    {
        int num = atoi(inputSplit.at(i).c_str());
        intSplit.push_back(num);
    }

    return intSplit;
}

int manhattanDist(vector<int> point1, vector<int> point2){
    int xValue = abs(point1[0] - point2[0]);
    int yValue = abs(point1[1] - point2[1]);
    int zValue = abs(point1[2] - point2[2]);
    return xValue + yValue + zValue;
}

int main(){
    char input[100];
    int i = 0;
    int numberOfTestCases = 0;

    cin.getline(input,100);
    numberOfTestCases = atoi(input);
    while(i < numberOfTestCases){
        int numberOfPoints = 0;
        int x = 0;
        
        vector<int> vectorArr[100];
        cin.getline(input,100);
        numberOfPoints = atoi(input);
        while(x < numberOfPoints){
            cin.getline(input,100);
            vectorArr[x] = IntSplit(input);
            x++;
        }

        x = 0;
        while(x < numberOfPoints-1){
            cout << manhattanDist(vectorArr[x],vectorArr[x+1]) << "\n";
            x++;
        }
        cout << "\n";
        i++;
    }
}