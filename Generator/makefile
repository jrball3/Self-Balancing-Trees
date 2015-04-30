COMPILER = g++
FLAGS = -std=c++0x
OUTPUT = gen

all: gen

gen: gen_input.o
	$(COMPILER) $(FLAGS) gen_input.cpp -o $(OUTPUT)

gen.o: gen_input.cpp
	$(COMPILER) $(FLAGS) -c gen_input.cpp

clean:
	rm *.o $(OUTPUT)

