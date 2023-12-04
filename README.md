# TP_SyntheseInfo_Li_Gaborieau

Objectives : Develop a tiny shell, that displays exit codes and execution times of launched programs.

Question 1 : 
Display a welcome message, followed by a simple prompt: 

To achieve this objective, we will use 2 functions : "welcome" and "prompt". 

As their name suggests,the "welcome" function writes the linestart (prompt) and the WelcomeMessage to the standard output (STDOUT). while the "prompt" function writes only the linestart (prompt) to STDOUT. 


Question 2 : Execution of the entered command and return to the prompt : 

a) read the command entered by user,

b) execute this command (simple command for the moment, without argument)), 

c) print the prompt enseash % and waits for a new command


To achieve these objectives, we implemented a command execution loop in the Ensea Shell. 

This loop is prompting users for commands, reading the input, and executing the entered commands using a child process created with the `fork` system call. 


Question 3) Management of the shell output with the command ”exit” or with <ctrl>+d : 














