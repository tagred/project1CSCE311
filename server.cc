#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <stdlib.h>
#include <vector>
#include <regex>
#include <algorithm>
#include <iostream>

//char *socket_path = "./socket";
char *socket_path = "\0hidden";

int main(int argc, char *argv[]) {
  struct sockaddr_un addr;
  char buf[1024];
  int fd,cl,rc;

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
    unlink(socket_path);
  }

  if (bind(fd, (struct sockaddr*)&addr, sizeof(addr)) == -1) {
    perror("bind error");
    exit(-1);
  }

  if (listen(fd, 5) == -1) {
    perror("listen error");
    exit(-1);
  }
  std::vector<std::string> array;
  while (1) {
    if ( (cl = accept(fd, NULL, NULL)) == -1) {
      perror("accept error");
      continue;
    }
    while ( (rc=read(cl,buf,sizeof(buf))) > 0) {
      array.push_back(buf); 
	}
    if (rc == -1) {
      perror("read");
      exit(-1);
    }
    else if (rc == 0) {
      printf("EOF\n");
      close(cl);
    }
  
std::string myregex = "[^A-z](";
myregex.append(array.front());
array.erase(array.begin());
myregex.append(")[^A-z]");
std::regex e (myregex, std::regex_constants::icase);

std::sort(array.begin(), array.end());

for(std::vector<std::string>::iterator it = array.begin(); it != array.end(); ++it) {
    if(std::regex_search(*it,e)) {
std::cout << *it;
}
}
}


  return 0;
}
