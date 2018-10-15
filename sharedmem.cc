#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <string>

int main(int argc, char *argv[]) {

if (argc != 3) {  // check to see for valid amount of arguments
std::cout << "invalid args" << std::endl;
std::cout << "Proper use: ./pipe (PATH) (WORD)" << std::endl;
return 0;
}
std::string myfilepath =argv[1];
std::string myarg = argv[2];

void* shmem = mmap(NULL, 1024, 0,0,0,0);

if (pid == 0) { // parent
  std::ifstream myfile(myfilepath);
 std::string temp;
while(std::getline(myfile, temp)){
if(temp.compare("") != 0){ // checks to see if its empty
temp.append("\n"); // adds a new line
memcpy(shmem, &temp, 1024); // puts the new line on the stream
}
temp = "";
}
    memcpy(shmem, child_message, sizeof(child_message));

  } else { // child
    printf("Parent read: %s\n", shmem);
    sleep(1);
    printf("After 1s, parent read: %s\n", shmem);
  }
}
