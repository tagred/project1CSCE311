#include <sys/socket.h>
#include <sys/un.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <fstream>
//char *socket_path = "./socket";
char *socket_path = "\0hidden";

int main(int argc, char *argv[]) {
  struct sockaddr_un addr;
  char buf[1024];
  int fd,rc;

  if (argc > 1) socket_path=argv[1];

  if ( (fd = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {
    perror("socket error");
    exit(-1);
  }

  memset(&addr, 0, sizeof(addr));
  addr.sun_family = AF_UNIX;
  if (*socket_path == '\0') {
    *addr.sun_path = '\0';
    strncpy(addr.sun_path+1, socket_path+1, sizeof(addr.sun_path)-2);
  } else {
    strncpy(addr.sun_path, socket_path, sizeof(addr.sun_path)-1);
  }

  if (connect(fd, (struct sockaddr*)&addr, sizeof(addr)) == -1) {
    perror("connect error");
    exit(-1);
  }
std::string filepath;
std::string myarg;
std::string line;
std::cin >> filepath;
std::cin >> myarg;
std::ifstream myfile(filepath);
write(fd, myarg.c_str(), 1024);
while(std::getline(myfile, line)) {
//std::cout << temp << std::endl;
if(line.compare("") != 0){
line.append("\n");
write(fd, line.c_str(), 1024);
}
line = "";
}

/* while(1) {
if (write(fd, buf, 1024) != rc) {
      if (rc > 0) fprintf(stderr,"partial write");
      else {
        perror("write error");
        exit(-1);
      }
    }

  }
*/
myfile.close();
  return 0;
}
