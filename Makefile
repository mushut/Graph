all: graph-test.exe

graph-test.exe:
	g++ -std=c++11 -g -o graph-test.exe main.cpp node.cpp

clean:
	rm graph-test.exe
