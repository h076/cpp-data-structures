all :
	testSLL

testSLL: testSLL.o singlyLinkedList.o
	g++ testSLL.o singlyLinkedList.o -o testSLL

testSLL.o:
	g++ -c testSLL.cpp

singlyLinkedList.o:
	g++ -c singlyLinkedList.cpp

clean:
	rm *.o testSLL
