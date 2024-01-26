SHELL ?= bash
CXX ?= g++
FLAGS_CXX ?= \
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
	clique_2.hh.gch \
	clique_3.hh.gch \
	clique_4.hh.gch \
	clique_5.hh.gch
	${CXX} ${FLAGS_CXX} $<

clique_2.hh.gch: \
	clique_2.hh
	${CXX} ${FLAGS_CXX} $<

clique_3.hh.gch: \
	clique_3.hh
	${CXX} ${FLAGS_CXX} $<

clique_4.hh.gch: \
	clique_4.hh
	${CXX} ${FLAGS_CXX} $<

clique_5.hh.gch: \
	clique_5.hh
	${CXX} ${FLAGS_CXX} $<
