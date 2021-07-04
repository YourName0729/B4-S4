# A template C++ Makefile for your SAT solver.

# Debugging flags
#FLAGS=-Wall -Wold-style-cast -Wformat=2 -ansi -pedantic -ggdb3 -DDEBUG

# Optimizing flags
FLAGS=-Wold-style-cast -Wformat=2 -ansi -pedantic -O3 -std=c++17

HEADERS=clause.hpp cnf.hpp converter.hpp


# List all the .o files you need to build here
OBJS=clause.hpp cnf.hpp converter.hpp main.cpp

# Compile targets
all: 
	g++ $(FLAGS) $(OBJS) -lz 

# Add more compilation targets here



# The "phony" `clean' compilation target.  Type `make clean' to remove
# your object files and your executable.
.PHONY: clean
clean:
	rm -rf $(OBJS) $(EXENAME)
