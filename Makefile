CC = g++ -std=c++11 
SRC = gsc.cpp
NAME = gsc

all:
	$(CC) $(SRC) -o $(NAME)
	
clean:
	rm $(NAME)	
