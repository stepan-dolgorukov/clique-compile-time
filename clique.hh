#ifndef CLIQUE_HH
#define CLIQUE_HH

#include <cstddef>

#include "clique_1.hh"
#include "clique_2.hh"
#include "clique_3.hh"
#include "clique_4.hh"
#include "clique_5.hh"

namespace cct
{
  template< std::size_t SizeClique >
  class Clique
  {
    private:
      std::size_t quantity_cliques{ 0u };

    public:
      consteval Clique( auto graph )
      {
        switch ( SizeClique )
        {
          case 1u:
            quantity_cliques = Clique_1{ graph }();
            break;

          case 2u:
            quantity_cliques = Clique_2{ graph }();
            break;

          case 3u:
            quantity_cliques = Clique_3{ graph }();
            break;

          case 4u:
            quantity_cliques = Clique_4{ graph }();
            break;

          case 5u:
            quantity_cliques = Clique_5{ graph }();
            break;
        }
      }

      auto
      consteval operator()( void ) const
      {
        return quantity_cliques;
      }
  };

  template< std::size_t SizeClique >
  auto
  consteval clique( auto Graph )
  {
    return Clique< SizeClique >{ Graph }();
  }
}

#endif
