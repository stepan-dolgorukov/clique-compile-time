#ifndef CLIQUE_1_HH
#define CLIQUE_1_HH

namespace cct
{
  template<typename Graph>
  class Clique_1 {
    private:
      const Graph graph;

    public:
      consteval Clique_1(Graph g) : graph{g} {
      }

      consteval int operator()(void) const {
        return graph.size();
      }
  };
}

#endif
