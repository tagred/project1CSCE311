#include <iostream>
#include <fstream>
#include <unistd.h>
#include <stdio.h>
#include <vector>
#include <sstream>
#include <algorithm>

void readpipe(int file, std::string myarg) {
FILE *stream;
stream =fdopen (file, "r");
std::vector<std::string> array;
std::stringstream ss;
char temp[200];
while(!feof(stream)) {
fgets(temp, 200, stream);
std::cout<< temp << std::endl;
array.push_back(temp);
}
fclose(stream);
std::sort(array.begin(), array.end());
for(std::vector<std::string>::iterator it = array.begin(); it != array.end(); ++it) {
    if(it.find(myarg)) {
std::cout << *it << std::endl;
}
}
}

void writepipe(int file, std::string filepath) {
FILE *stream;
stream = fdopen(file, "w");
std::ifstream myfile(filepath);
std::string temp;
while(std::getline(myfile, temp)) {
fputs(temp.c_str(), stream);
}
myfile.close();
fclose(stream);

}



int main(int argc, char *argv[]) {
if (argc == 1) {  // check to see for valid amount of arguments
std::cout << "invalid args" << std::endl;
return 0;
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
writepipe(mypipe[1], myfile);
}
return 1;
}
