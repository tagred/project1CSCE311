#Copyright 2018 Christopher Masselli
#Created by Christopher Masselli

CC = g++

FLAGS = -std=c++11 # compile with C++ 11 standard
FLAGS += -Wall # compile with all warnings

all: server client pipe

server: server.o
	$(CC) $(FLAGS) -o $@ $^
	rm server.o
client: client.o
	$(CC) $(FLAGS) -o $@ $^
	rm client.o
pipe: main.o
	$(CC) $(FLAGS) -o $@ $^
	rm main.o
main.o: main.cc
	$(CC) $(FLAGS) -c $^
client.o: client.cc
	$(CC) $(FLAGS) -c $^
server.o: server.cc
	$(CC) $(FLAGS) -c $^
backup:
	zip $(USER) main.cc makefile
clean: 
	rm pipe server client
	rm -f *.o socket 

