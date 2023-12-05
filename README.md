# TP_SyntheseInfo_Li_Gaborieau

Objectives : Develop a tiny shell, that displays exit codes and execution times of launched programs.

## Question 1 : Display a welcome message, followed by a simple prompt: 
Display a welcome message, followed by a simple prompt: 

To achieve this objective, we will use 2 functions : "welcome" and "prompt". 

As their name suggests,the "welcome" function writes the linestart (prompt) and the WelcomeMessage to the standard output (STDOUT). while the "prompt" function writes only the linestart (prompt) to STDOUT. 


## Question 2 : Execution of the entered command and return to the prompt : 

- a) read the command entered by user,

- b) execute this command (simple command for the moment, without argument)), 

- c) print the prompt enseash % and waits for a new command


To achieve these objectives, we implemented a command execution loop in the Ensea Shell. 

This loop is prompting users for commands, reading the input, and executing the entered commands using a child process created with the `fork` system call. 


## Question 3 : Management of the shell output with the command ”exit” or with <ctrl>+d : 

To archive these objectives, we start with the code from question 2 and add we add the "exitFunction" to exit proprely with a byebye message. 


 ## Question 4 : Display the return code (or signal) of the previous command in the prompt :

After executing a command, the father process waits for the child process to finish, ans checks whether the child process exited normally or was terminated by a signal. 
Depending on the outcome, the global variable linestart4 is updated to include the corresponding information.


## Question 5 : Measurement of the command execution time using the call clock_gettime :

To measur the execution time of commands, we used the "clock_gettime" function to captured the start and stop times around the execution of each command. 
We then calculate and incorporate it into the global variable linestart5. 


## Question 6 : Execution of a complex command (with arguments) :

By utilizing the execvp system call, the child process executes the command with the arguments. 
The main loop now parses user input to separate the command and its arguments, ensuring proper execution. 


## Question 7 : Management of redirections to stdin and stdout with ’<’ and ’>’ :

Manage redirections to stdin and stdout with `<` and `>`.


  




