#ifndef CLIQUE_3_HH
#define CLIQUE_3_HH

#include <cstddef>

#include "factorial.hh"

namespace cct
{
  template< typename Graph >
  class Clique_3
  {
    private:
      const Graph graph;

    public:
      consteval Clique_3( Graph g ) : graph{ g }
      {}

      auto
      consteval operator()( void ) const
      {
        std::size_t quantity_cliques{ 0u };

        for( std::size_t a{ 0u }; a < size( graph ); ++a )
        {
          for( std::size_t b{ 0u }; b < size( graph ); ++b )
          {
            if( b == a ||
                0 == graph[ a ][ b ] )
            {
              continue;
            }

            for( std::size_t c{ 0u }; c < size( graph ); ++c )
            {
              if( c == a ||
                  c == b )
              {
                continue;
              }

              if( 1 == graph[ b ][ c ] &&
                  1 == graph[ c ][ a ] )
              {
                ++quantity_cliques;
              }
            }
          }
        }

        return quantity_cliques / factorial< int, 3 >();
      }
  };
}

#endif
