#include <iostream>
#include <fstream>
#include <unistd.h>
#include <stdio.h>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <regex>



void readpipe(int file, std::string myarg) { // child process reads pipe and gives output
FILE *stream;
stream =fdopen (file, "r"); // open to read
std::vector<std::string> array;
char temp[1024];
while(!feof(stream)) { // loops until the stream is empty
fgets(temp, 1024, stream); // pulls off a line from the stream
array.push_back(temp); // places it on the back of a vector of strings
}
fclose(stream); // closes the pipe since we have gotten all the info from it

//builds regex
std::string myregex = "[^A-z](";
myregex.append(myarg);
myregex.append(")[^A-z]");
std::regex e (myregex, std::regex_constants::icase);

//sorts
std::sort(array.begin(), array.end());

for(std::vector<std::string>::iterator it = array.begin(); it != array.end(); ++it) { //iterates vector
    if(std::regex_search(*it,e)) { // checks to see if that lines contains the word we are looking for if so print the line
std::cout << *it;
}
}
}

void writepipe(int file, std::string filepath) {
FILE *stream;
stream = fdopen(file, "w");  //open to write
std::ifstream myfile(filepath); // create the stream of the file
std::string temp;
while(std::getline(myfile, temp)) { // loop until there are no more lines in the file
//std::cout << temp << std::endl;
if(temp.compare("") != 0){ // checks to see if its empty
temp.append("\n"); // adds a new line
fputs(temp.c_str(), stream); // puts the new line on the stream
}
temp = "";
}
myfile.close();
fclose(stream);
}



int main(int argc, char *argv[]) {



if (argc != 3) {  // check to see for valid amount of arguments
std::cout << "invalid args" << std::endl;
std::cout << "Proper use: ./pipe (PATH) (WORD)" << std::endl;
return 0;
}
std::string myfile =argv[1];
std::string myarg = argv[2];

pid_t pid;
int mypipe[2];


if (pipe(mypipe)) {  // fails if true pipe failed
}

pid = fork(); // gets the pid 0 if child and if parent gets pid of child

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
