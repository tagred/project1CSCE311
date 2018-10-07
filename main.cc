#include <iostream>
#include <fstream>
#include <unistd.h>
#include <stdio.h>

void readpipe(int file) {
FILE *stream;
std::string *c;
stream =fdopen (file, "r");

//while ((c = gets(stream)) != EOF) {
//if (c.find(myarg)) {
//std::cout << c << std::endl;
//} 
}

fclose(stream);
}

void writepipe(int file, std::string filepath) {
FILE *stream;
stream = fdopen(file, "w");
std::ofstream myfile(filepath);
std::string line;
while (getline(myfile, line) != EOF) {
std::cout << line<< std::endl;
std::fprintf (stream, line);
}
fclose(stream);
myfile.close();
}



int main(int argc, char *argv[]) {
if (argc == 1) {  // check to see for valid amount of arguments
}

std::string myfile =argv[1];
std::string myarg = argv[2];
pid_t pid;
int mypipe[2];


if (pipe(mypipe)) {  // fails if true pipe failed
}

pid = fork();

if (pid == (pid_t) 0) {  // child
close(mypipe[1]);
readpipe(mypipe[0], myarg);
// do something with the writing
} else if (pid < (pid_t) 0) {
// failed
} else {   // parent
close(mypipe[0]);
writepipe(mypipe[1], filepath);
}
}
