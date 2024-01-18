#ifndef CLIQUE_HH
#define CLIQUE_HH

#include <cstddef>

#include "clique_2.hh"
#include "clique_3.hh"
#include "clique_4.hh"
#include "clique_5.hh"

using namespace std;

template<size_t SizeClique>
class Clique {
  private:
    size_t quantity_cliques = 0u;

  public:
    template<typename TypeGraph>
    consteval Clique(TypeGraph graph) {
      switch(SizeClique){
        case 2u:
          quantity_cliques = Clique_2{graph}();
          break;

        case 3u:
          quantity_cliques = Clique_3{graph}();
          break;

        case 4u:
          quantity_cliques = Clique_4{graph}();
          break;

        case 5u:
          quantity_cliques = Clique_5{graph}();
          break;
      }
    }

    consteval int operator()(void) const {
      return quantity_cliques;
    }
};

#endif
