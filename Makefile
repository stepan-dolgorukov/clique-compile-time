SHELL ?= bash
CXX ?= g++
FLAGS_CXX += \
--std=c++20

clique: \
clique.o
	${CXX} ${FLAGS_CXX} $^ -o $@

clique.o: \
clique.cc \
clique.hh.gch
	${CXX} ${FLAGS_CXX} -c $<

clique.hh.gch: \
clique.hh \
clique_2.hh \
clique_3.hh \
clique_4.hh \
clique_5.hh
	${CXX} ${FLAGS_CXX} $<
