p = test
c = g++ -std=c++0x
f = -g -O3

all: Driver.o RedBlackTree.o AVLTree.o BinarySearchTree.o
	$c $f -o $p Driver.o RedBlackTree.o AVLTree.o BinarySearchTree.o

Driver.o: Driver.cpp
	$c $f -c Driver.cpp

RedBlackTree.o: ../RedBlackTree/RedBlackTree.cpp
	$c $f -c ../RedBlackTree/RedBlackTree.cpp

BinarySearchTree.o: ../BinarySearchTree/BinarySearchTree.cpp
	$c $f -c ../BinarySearchTree/BinarySearchTree.cpp

AVLTree.o: ../AVLTree/AVLTree.cpp
	$c $f -c ../AVLTree/AVLTree.cpp

clean: 
	rm *.o $p

