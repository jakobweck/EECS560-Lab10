prog: main.o LeftistHeap.o SkewHeap.o Queue.o QueueNode.o
	g++ -g -Wall -std=c++11 main.o LeftistHeap.o SkewHeap.o Queue.o QueueNode.o -o prog

main.o: main.cpp
	g++ -g -Wall -std=c++11 -c main.cpp

LeftistHeap.o: LeftistHeap.cpp LeftistHeap.h ConcatHeap.h
	g++ -g -Wall -std=c++11 -c LeftistHeap.cpp

SkewHeap.o: SkewHeap.cpp SkewHeap.h ConcatHeap.h
	g++ -g -Wall -std=c++11 -c SkewHeap.cpp

Queue.o: Queue.cpp Queue.h
	g++ -g -Wall -std=c++11 -c Queue.cpp

QueueNode.o: QueueNode.cpp QueueNode.h
	g++ -g -Wall -std=c++11 -c QueueNode.cpp

clean:
	rm *.o prog
