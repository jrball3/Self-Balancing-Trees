p = trees
c = g++ -std=c++11
f = -g

all: Driver.o BinarySearchTree.o
	$c $f -o $p Driver.o BinarySearchTree.o

Driver.o: Driver.cpp
	$c $f -c Driver.cpp

BinarySearchTree.o: BinarySearchTree.cpp
	$c $f -c BinarySearchTree.cpp

clean: 
	rm *.o $p
