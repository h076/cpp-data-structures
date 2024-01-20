all: testLL

testLL: testLL.o LinkedList.o
	g++ testLL.o LinkedList.o -o testLL

testLL.o:
	g++ -c testLL.cpp

LinkedList.o:
	g++ -c LinkedList.cpp

clean:
	rm *.o testLL
