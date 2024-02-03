#ifndef CLIQUE_2_HH
#define CLIQUE_2_HH

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

      consteval int operator()( void ) const
      {
        int quantity_cliques{ 0 };

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
