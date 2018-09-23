#Copyright 2018 Christopher Masselli
#Created by Christopher Masselli

CC = g++

FLAGS = -std=c++11 # compile with C++ 11 standard
FLAGS += -Wall # compile with all warnings

01hw: main.o
	$(CC) $(FLAGS) -o $@ $^
	rm main.o
main.o: main.cc
	$(CC) $(FLAGS) -c $^
backup:
	zip $(USER) main.cc makefile
clean: 
	rm 01hw

