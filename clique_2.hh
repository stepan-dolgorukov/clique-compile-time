#ifndef CLIQUE_2_HH
#define CLIQUE_2_HH

#include <cstddef>

namespace cct
{
  template< typename Graph >
  class Clique_2
  {
    private:
      const Graph graph;

    public:
      consteval Clique_2( Graph g ) : graph{ g }
      {}

      consteval std::size_t operator()( void ) const
      {
        std::size_t quantity_cliques{ 0u };

        for (int a = 0; a < size( graph ); ++a)
        {
          for (int b = a + 1; b < size( graph ); ++b)
          {
            if (1 == graph[ a ][ b ])
            {
              ++quantity_cliques;
            }
          }
        }

        return quantity_cliques;
      }
  };
}

#endif
