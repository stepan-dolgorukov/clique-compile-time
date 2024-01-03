SHELL := bash
CXX ?= g++
FLAGS_CXX ?= \
	--std=c++20

clique: clique.o
	${CXX} ${FLAGS_CXX} $^ -o $@

clique.o: clique.cc clique.hh
	${CXX} ${FLAGS_CXX} -c $<
