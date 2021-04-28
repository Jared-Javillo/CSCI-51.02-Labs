Lab3_Grp26_readme file

Description of program:
    -> Our C++ program implements a stack. For the whole program to work, we created an .hpp file that contains two structs, 
       namely IntNode and IntStack. The IntNode struct contains an integer data type called "data" and pointers that are IntNode
       instantiations namely *top_child and *parent. So for every IntNode instantiation (or essentially for every node) it will have 
       its own data value or integer amount and a set of pointers to point to the respective top_child and parent node. The IntStack 
       struct contains functions that can push a new node into a stack, pop a node (or remove) from a stack, and peek at the 
       current or most recent node added in a stack. The functions are IntNode data type functions so that they can access the nodes 
       and their values. 


How to run and use the program:
    -> (Before anything: make sure that the code is compiled and has an executable file (.exec) for this is what you will run in the command promt/terminal and not the .cpp or the .hpp file)
    -> (To compile your code, type: g++ -o "Name you want your executable/run file to be" "Name of your .cpp file)
    -> STEPS:
    -> First:  Run the code in either command prompt or terminal (if you are using MAC) by typing: .\"Name of the .exec"
    -> Second: Once it runs you will be presented with a prompt "Enter an Integer of root node: ." Type the integer of your choice and click enter
    -> Third:  You will be presented with 4 options: 1.Push, 2.Pop, 3.Peek, and 4.End. You will then be asked to type the number of the function you want to perform. 
    -> (Choosing 4 will end the program and it will say "Bye Bye")
    -> Fourth: At this point you are free to choose which functions to perform, whether it be Push a node into the stack, Pop a node from it, or Peek at the most recently added node. 
    -> Fifth:  Once you are done using the code, simply type 4 when being asked what function to perform to end the program.  
          
