#############################################################################
# File name:  Makefile
# Author:     chadd williams
# Date:       Sept 1, 2021
# Class:      CS360
# Assignment: 
# Purpose:    
#############################################################################


FILES := $(wildcard src/*.cpp)
TARGETS := $(addprefix bin/, $(notdir $(addsuffix .out, $(FILES))))
TARGETS += $(addprefix bin/, $(notdir $(addsuffix .txt, $(FILES))))

all: bin $(TARGETS) bin/main.s

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
# CPP_VERSION=c++2a

bin:
	mkdir -p bin

bin/%.out: src/$(notdir %)
	g++ -fdump-lang-class=$@ -c $< -Iinclude -o bin/ignore.o


bin/main.s: src/*.cpp include/*.h
	g++ -o bin/main.s -Wall -g src/driver.cpp -Iinclude  -fverbose-asm -S

clean:
	rm -rf bin/*.o bin/*.out bin/*.s bin/*.txt


# https://gist.github.com/GavinRay97/700ff1631d7e5ac460efd0780759c908
bin/%.txt: src/$(notdir %)
	clang++-16 -c  -Iinclude  -std=${CPP_VERSION} -Xclang -fdump-record-layouts -emit-llvm $<  > $@_records.txt
	clang++-16 -c  -Iinclude -std=${CPP_VERSION} -Xclang -fdump-vtable-layouts -emit-llvm $<  > $@_vtable.txt

bin/cat.o:
	clang++-16 -c -Iinclude -o $@ src/cat.cpp

bin/example.o:
	clang++-16 -c -Iinclude -o $@ src/example.cpp

bin/testNames.o:
	clang++-16 -c -Iinclude -o $@ src/testNames.cpp