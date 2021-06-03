Lab8_Grp26_readme file

Description of programs:
    -> Our Producer program reads a text file (to be inputed by the user) and stores its contents into a shared memory. Our Consumer program reads what's in the shared memory and writes the contents into an empty text file (to be inputted by the user). Even if the text file were not to be empty, it would get overwritten with the contents coming from the Consumer program. Both programs make use of semaphores to help indicate if it has entered a critical section, whether that be it is reading a text file or writing a text file.


How to run and use the program:
    -> (Before anything: make sure that the code is compiled and has an executable file for this is what you will run in the command promt/terminal and not the .cpp/.c)
    -> Initial Steps:
    -> Initial Step 1: To compile your file type: g++ -o executable-file-name program-source-code.cpp/.c
    -> STEPS TO RUN:
    -> First:  Run the Producer code first by typing: ./"executable-file-name" <Your desired text file to copy to another empty or non-empty text file> <size of shared memory>
        e.g ./producer Copy_this.txt 1024
    -> Second: Click enter after typing what was said in the first step. You will notice the console starts to print out the current state of the producer program. It will first say that it is Reading, to indicate that it is reading the text file you inputed and storing it in a shared memory. It will then continously start printing "Waiting" to indicate that the producer is waiting for a consumer to write the contents of the shared memory to another text file.
    -> Third:  Now go into another terminal/command prompt and run the Consumer code by typing: ./"executable-file-name" <An empty or non-empty text file to have the contents of the shared memory copied to> <size of shared memory>
    -> Fourth: Click enter after typing what was said in the third step. You will notice the console starts printing "Ready" indicating that the program is ready to get the contents in the shared memory to be written into the text file. It will alternate between "Reading" and "Waiting" states to indicate that it is continously reading the contents and writing them into the desired text file. Once all the contents have been read and written, the console will then print the current state being "Finished" and a final message saying "Copy Successful!". In the terminal/command prompt where you inputed the Producer run command in the first step, you will also notice something getting printed, "Writing File Finished". This is to show that the producer program was notified that the writing process done by the consumer program has been completed.
    -> Fifth:  If you then check on your text file, it should contain the contents of the text file inputted into the Producer program. 

Other Notes
    -> Program tested in WSL Ubuntu on top of Windows 10

