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

      auto
      consteval operator()( void ) const
      {
        std::size_t quantity_cliques{ 0u };

        for (std::size_t a{ 0u }; a < size( graph ); ++a)
        {
          for (std::size_t b{ 1u + a }; b < size( graph ); ++b)
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
