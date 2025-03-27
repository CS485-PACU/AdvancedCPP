#############################################################################
# File name:  Makefile
# Author:     chadd williams
# Date:       Sept 1, 2021
# Class:      CS360
# Assignment: 
# Purpose:    
#############################################################################

all: bin bin/main bin/main-no-elide

ENSCRIPT_FLAGS=-C -T 2 -p - -M Letter -Ecpp --color -fCourier8
VALGRIND_FLAGS=-v --leak-check=yes --track-origins=yes --leak-check=full --show-leak-kinds=all 

compiler=clang++-16
#compiler=g++

# clang (Mac)
# Version 10 or later
# CPP_VERSION=c++20
# Version 9 or earlier
CPP_VERSION=c++2b

# g++ (Linux)
# Version 10 or later
# CPP_VERSION=c++20
# Version 9 or earlier (Codespaces)
#CPP_VERSION=c++2b

bin:
	mkdir -p bin

bin/main: bin src/*.cpp include/*.h
	${compiler} -std=${CPP_VERSION} -o bin/main -g -Wall src/*.cpp -Iinclude
	#-fno-elide-constructors 

bin/main-no-elide: bin src/*.cpp include/*.h
	${compiler} -fno-elide-constructors -std=${CPP_VERSION} -o bin/main-no-elide -g -Wall src/*.cpp -Iinclude
	

#bin/main.o: bin src/helloWorld.cpp
#	${compiler} -std=c++20 -c -o bin/main.o -g -Wall src/helloWorld.cpp 
 
valgrind: bin/main
	valgrind ${VALGRIND_FLAGS} bin/main

printAll:
	enscript ${ENSCRIPT_FLAGS} src/*.cpp include/*.h  | ps2pdf - bin/src.pdf

runMe: bin/main
	bin/main
	
clean:
	rm -rf bin/main* bin/*.o bin/main.dSYM bin/*.pdf
