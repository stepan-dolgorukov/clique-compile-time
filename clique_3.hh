#ifndef CLIQUE_3_HH
#define CLIQUE_3_HH

#include "factorial.hh"

template<typename Graph>
class Clique_3 {
  private:
    const Graph graph;

  public:
    consteval Clique_3(Graph g) : graph{g} {
    }

    consteval int operator()() const {
      int quantity_cliques = 0;

      for (int a=0; a<size(graph); ++a) {
        for (int b=0; b<size(graph); ++b) {

          if (b == a ||
              0 == graph[a][b]) {
            continue;
          }

          for (int c=0; c<size(graph); ++c) {
            if (c == a ||
                c == b) {
              continue;
            }

            if (1 == graph[b][c] &&
                1 == graph[c][a]) {
              ++quantity_cliques;
            }
          }
        }
      }
      return quantity_cliques / factorial<int, 3>();
    }
};

#endif
