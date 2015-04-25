p = trees
c = g++ -std=c++0x
f = -g

all: Driver.o RedBlackTree.o
	$c $f -o $p Driver.o RedBlackTree.o

Driver.o: Driver.cpp
	$c $f -c Driver.cpp

RedBlackTree.o: RedBlackTree.cpp
	$c $f -c RedBlackTree.cpp

clean: 
	rm *.o $p
