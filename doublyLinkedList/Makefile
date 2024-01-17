all :
	testDLL

testDLL: testDLL.o doublyLinkedList.o
	g++ testDLL.o doublyLinkedList.o -o testDLL

testDLL.o:
	g++ -c testDLL.cpp

doublyLinkedList.o:
	g++ -c doublyLinkedList.cpp

clean:
	rm *.o testDLL
