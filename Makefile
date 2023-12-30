SHELL := bash
CXX ?= g++
FLAGS_CXX ?= \
	--std=c++20

clique: clique.o
	${CXX} ${FLAGS_CXX} $^ -o $@

%.o: %.cc
	${CXX} ${FLAGS_CXX} -c $^ -o $@
