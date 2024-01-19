all:
	testLL

testLL: testLL.o
	g++ testLL.o -o testLL

LinkedList:
	g++ LinkedList.cpp -o LinkedList

testLL.o:
	g++ -c testLL.cpp

LinkedList.o:
	g++ -c LinkedList.cpp

clean:
	rm *.o testLL LinkedList
