#ifndef CLIQUE_5_HH
#define CLIQUE_5_HH

namespace cct
{
  template< typename Graph >
  class Clique_5
  {
    private:
      const Graph graph;

    public:
      consteval Clique_5( Graph g ) : graph{ g }
      {}

      int
      consteval operator()( void ) const
      {
        int quantity_cliques = 0;

        for( int a = 0; a < size( graph ); ++a )
        {
          for( int b = 0; b < size( graph ); ++b )
          {
            if( b == a ||
                0 == graph[ a ][ b ] )
            {
              continue;
            }

            for( int c = 0; c < size( graph ); ++c )
            {
              if( c == b ||
                  c == a ||
                  0 == graph[ a ][ c ] ||
                  0 == graph[ b ][ c ] )
              {
                continue;
              }

              for( int d = 0; d < size( graph ); ++d )
              {
                if( d == a ||
                    d == b ||
                    d == c ||
                    0 == graph[ a ][ d ] ||
                    0 == graph[ b ][ d ] ||
                    0 == graph[ c ][ d ] )
                {
                  continue;
                }

                for( int e = 0; e < size( graph ); ++e )
                {
                  if( e == a ||
                      e == b ||
                      e == c ||
                      e == d )
                  {
                    continue;
                  }

                  if( 1 == graph[ a ][ e ] &&
                      1 == graph[ b ][ e ] &&
                      1 == graph[ c ][ e ] &&
                      1 == graph[ d ][ e ] )
                  {
                      ++quantity_cliques;
                  }
                }

              }
            }
          }
        }

        return quantity_cliques;
      }
  };
}

#endif
