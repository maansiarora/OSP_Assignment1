.default: all

all: Task1 Task2 Task3

clean:
	rm -rf task *.o *.dSYM

Task1: Task1.o Methods.o
	g++ -Wall -Werror -std=c++14 -g -O -o $@ $^

Task2: Task2.o Methods.o
	g++ -Wall -Werror -std=c++14 -g -O -o $@ $^

Task3: Task3.o Methods.o
	g++ -Wall -Werror -std=c++14 -pthread -g -O -o $@ $^

%.o: %.cpp
	g++ -Wall -Werror -std=c++14 -g -O -c $^
