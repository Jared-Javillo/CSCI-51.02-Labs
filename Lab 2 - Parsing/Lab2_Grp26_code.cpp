#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <string.h>

using namespace std;

int main(void) {
    int agentNum;
    char input[100];
    vector<string> inputSplit;
    char* chars_array;

    cin.getline(input,100);
    agentNum = atoi(input);
    for (int i = 0; i < agentNum; i++) {
        int count = 0;
        inputSplit.clear();
        cin.getline(input,100);
        chars_array = strtok(input," ");
        while(chars_array)
        {
            count++;
            inputSplit.push_back(chars_array);
            chars_array = strtok(NULL, " ");
        }
		cout << "Agent#" << i + 1 << " is at (" << inputSplit[0] << ", " << inputSplit[1] << ")" << '\n';
        cout << "Says: ";
        for (int i = 2; i < inputSplit.size(); i++){
            cout << inputSplit[i] << " ";
        }
        cout << "\n";
	};
}