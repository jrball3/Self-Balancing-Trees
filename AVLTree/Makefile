p = trees
c = g++ -std=c++0x
f = -g

all: Driver.o AVLTree.o
	$c $f -o $p Driver.o AVLTree.o

Driver.o: Driver.cpp
	$c $f -c Driver.cpp

AVLTree.o: AVLTree.cpp
	$c $f -c AVLTree.cpp

clean: 
	rm *.o $p
