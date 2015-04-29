p = driver
c = g++ -std=c++0x
f = -g

all: TestAllDriver.o RedBlackTree.o AVLTree.o BinarySearchTree.o
	$c $f -o $p TestAllDriver.o RedBlackTree.o AVLTree.o BinarySearchTree.o

TestAllDriver.o: TestAllDriver.cpp
	$c $f -c TestAllDriver.cpp

RedBlackTree.o: RedBlackTree/RedBlackTree.cpp
	$c $f -c RedBlackTree/RedBlackTree.cpp

BinarySearchTree.o: BinarySearchTree/BinarySearchTree.cpp
	$c $f -c BinarySearchTree/BinarySearchTree.cpp

AVLTree.o: AVLTree/AVLTree.cpp
	$c $f -c AVLTree/AVLTree.cpp

clean: 
	rm *.o $p

