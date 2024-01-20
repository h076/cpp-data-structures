all: mergeSort

mergeSort: mergeSort.o LinkedList.o
	g++ -Wall mergeSort.o LinkedList.o -o mergeSort

mergeSort.o:
	g++ -c mergeSort.cpp

LinkedList.o:
	g++ -c LinkedList.cpp

clean:
	rm *.o mergeSort
