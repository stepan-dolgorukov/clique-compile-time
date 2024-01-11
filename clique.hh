#ifndef CLIQUE_HH
#define CLIQUE_HH

#include <cstddef>

#include "clique_2.hh"
#include "clique_3.hh"
#include "clique_4.hh"
#include "clique_5.hh"

using namespace std;

template<size_t SizeClique, typename Graph>
class Clique {
  private:
    const Graph graph;
    const size_t size_clique = SizeClique;

  public:
    consteval Clique(Graph g) : graph{g} {
    }

    consteval int operator()(void) const {
      switch (SizeClique) {
        case 0u:
        case 1u:
        case 2u:
          return true;

        case 3u:
          return Clique_3(graph)();

        case 4u:
          return Clique_4(graph)();
      }

      return false;
    }
};

#endif
