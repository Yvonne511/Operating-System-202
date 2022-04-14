/*
Loop {
    Obtain a command name from the user
    Replace command’s trailing newline with a ’\0’
    If (command is type 1)
        Implement the command directly
    else // the fun begins {
        parentOrChild = fork() // now your lab has two!! processes running
        if (parentOrChild == 0) { // code executed by the child process
            // Calculate arguments for execve() and execute it
            // The execve’ed command exits }
        else // code executed by the parent process
    wait() // parent waits for child to exit
}
*/

// g++ main.cpp
// ./a.out

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
using namespace std;
#define Length 50

int main() {
  char command[Length];
  while (fgets(command, Length+1, stdin)!= NULL){
    command[strcspn(command, "\r\n")] = 0;
    if (strcmp(command, "hello")==0) 
      cout<<"A Friendly Greeting"<<endl;
    else if(strcmp(command, "bye")==0) 
      {cout<<"Exit"<<endl;
      exit(0);}
    else if(strcmp(command, "assignment")==0) 
      cout<<"202 lab #1 (Spring 2022)"<<endl;
    else if(strcmp(command, "author")==0) 
      cout<<"Yvonne Wu (Yiyi Wu) "<<"N11015159 "<<"yw4142"<<endl;
    else if(strcmp(command, "section")==0) 
      cout<<"002"<<endl;
    else{
      int parentOrChild = fork();
      if (parentOrChild == 0){
        char directory[] = "/bin/";
        strcat(directory, command);
        char* argv[] = {command, NULL,NULL};
        execve(directory, argv, NULL);
        exit(0);
      } else {
        int status;
        wait(&status);
        }
    }
  }
}