#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>
#include <string>
#include <iostream>
#include <fstream>
#include <cstring>
#include <fcntl.h>


int main(int argc, char *argv[]) {

if (argc != 3) {  // check to see for valid amount of arguments
std::cout << "invalid args" << std::endl;
std::cout << "Proper use: ./pipe (PATH) (WORD)" << std::endl;
return 0;
}
std::string myfilepath =argv[1];
std::string myarg = argv[2];
int file_size;
void* shmem;
int pid = fork();

if (pid == 0) { // parent
 std::string temp;
int fd = open(argv[1], 0);
file_size = lseek(fd, 0, SEEK_END);
std::cout << file_size <<std::endl;
shmem = mmap(NULL, file_size ,0,0,fd,0);
std::cout << shmem<< std::endl;
std::cout << "not in child now" << std::endl;  
} else { // child
  //std::vector<std::string> array;

std::cout << "its in child" << std::endl;
std::string line;

    sleep(10);
std::cout << shmem << std::endl;
std::cout << file_size << std::endl;
 write(0, shmem, file_size);


  }

}
