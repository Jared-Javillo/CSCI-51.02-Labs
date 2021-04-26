#include <iostream>
#include "Lab3_Grp26_struct.hpp"

using namespace std;

IntNode *addNode(int x)
{
	IntNode *newNode = new IntNode;

    newNode->data = x;
    newNode->top_child = NULL;
    newNode->parent = NULL;
    return newNode;
    delete newNode;
}

IntNode* push(IntNode *parent, IntNode *child){
    parent -> top_child = child;
    child -> parent = parent;
    return child;
}

IntNode* pop(IntNode *poppedNode){
	return poppedNode->parent;
}

int peek(IntNode peekedNode){
    return peekedNode.data;
}

int main(void) {
    int inputInt;
    IntNode* pointer = new IntNode;
    IntNode* tempNode = new IntNode;
    cout << "Enter Integer of root node: ";
    cin >> inputInt;
    pointer = addNode(inputInt);

    while (true){
        cout << "\n----------------\n";
        cout << "1. Push" <<"\n" << "2. Pop" << "\n";
        cout << "3. Peek "<< "\n" << "4. end";
        cout << "\n-----------------\n";
        cout << "Enter the number of the action you want to perform: ";
        cin >> inputInt;
        
        switch (inputInt){
            case 1:{
                cout << "Push option was chosen" << "\n" << "\n";
                cout << "Enter Digit: " << "\n";
                cin >> inputInt;
                cout << "Pushed " << inputInt << "\n" << "\n";
                tempNode = addNode(inputInt);
                pointer = push(pointer,tempNode);
                continue;
            }
            case 2:{
                cout << "Pop option was chosen" << "\n";
                if (pointer -> parent == NULL){
                    cout << "Popped root node \n" ;
                    pointer == NULL;
                    cout << "Please enter integer of new root node: ";
                    cin >> inputInt;
                    pointer = addNode(inputInt);
                } else {
                    cout << "Popped " << pointer->data << "\n" <<"\n";
                    pointer = pop(pointer);
                }
                continue;
            }
            case 3:{
                cout << "Peek option was chosen" << "\n";
                cout << "Peeked: " << pointer->data<< "\n" << "\n";
                continue;
            }
            case 4:{
                cout << "Bye Bye" << "\n";
                return 0;
            }
            default:{ 
                cout << "Invalid option" << "\n" << "\n";
                continue;
            }
        delete (tempNode);
        }
    }
    delete (tempNode);
    delete (pointer);
    return 0;
}