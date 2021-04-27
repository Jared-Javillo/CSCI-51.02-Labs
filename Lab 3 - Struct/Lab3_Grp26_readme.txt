Lab3_Grp26_readme file

Description of program:
    -> Our C++ program implements a stack. 
       For the whole .cpp code to work, we created a struct named IntNode and made it into its own separate file (.hpp). 
       The struct contains an integer data type called "data" and pointers that are its own data types (IntNode data type) 
       namely *top_child and *parent. So for every IntNode instantiation (or essentially a node) it will have its own set
       of pointers to the top_child and parent node. 

       and contains functions that can push a new value into the stack,
       pop a value or remove a value from the stack, and peek at the current or most recent value added in the stack.

How to run and use the program:
    -> (Before anything: make sure that the code is compiled and has an executable file (.exec) for this is what you will run in the command promt/terminal and not the .cpp or the .hpp file)
    -> (To compile your code, type: )
    -> First: run the code in either command prompt or terminal (if you are using MAC) by typing: .\"Name of the .exec"
    -> The program has 3 options: push, pop, peek.
       Each option can be chosen by inputing a specific number.
          
