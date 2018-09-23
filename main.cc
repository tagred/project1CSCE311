#include <iostream>
#include <fstream>
#include <unistd.h>
#include <stdio.h>

void readpipe (string file) {
FILE *stream;

}



int main (int argc, char *argv[]) {
if (argc > 1) { // check to see for valid amount of arguments

}
pid_t pid;
int mypipe[2];



if (pipe (mypipe)){ //fails if true pipe failed

} 






pid = fork();

if (pid == (pid_t) 0) {
close (mypipe[1]);
{
close (mypipe[1]);
read_frim_pipe (mypipe[0]);
}
else if ( pid < (pid_t) 0)
{
//failed
}
else {
close (mypipe[0]);
write_to_pipe ( mypipe[1]);

}








}
