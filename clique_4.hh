#ifndef CLIQUE_4_HH
#define CLIQUE_4_HH

#include "factorial.hh"

template<typename Graph>
class Clique_4 {
  private:
    const Graph graph;

  public:
    consteval Clique_4(Graph g) : graph{g} {
    }

    int
    consteval operator()(void) const {
      int quantity_cliques = 0;

      for (int a=0; a<size(graph); ++a) {
        for (int b=0; b<size(graph); ++b) {

          if (b == a ||
              0 == graph[a][b]) {
            continue;
          }

          for (int c=0; c<size(graph); ++c) {

            if (c == b ||
                c == a ||
                0 == graph[a][c] ||
                0 == graph[b][c]) {
              continue;
            }

            for (int d=0; d<size(graph); ++d) {

              if (d == a ||
                  d == b ||
                  d == c) {
                continue;
              }

              if (graph[a][d] &&
                  graph[b][d] &&
                  graph[c][d]) {
                ++quantity_cliques;
              }
            }
          }
        }
      }

      return quantity_cliques / factorial<int, 4>();
    }
};

#endif
