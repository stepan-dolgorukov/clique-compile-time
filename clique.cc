#include<bits/stdc++.h>
using namespace std;

template<typename Graph>
class Clique_3 {
  private:
    const Graph graph;

  public:
    consteval Clique_3(Graph g) : graph{g} {
    }

    consteval bool operator()() {
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
              return true;
            }
          }
        }
      }
      return false;
    }
};

template<typename Graph>
class Clique_4 {
  private:
    const Graph graph;

  public:
    consteval Clique_4(Graph g) : graph{g} {
    }

    consteval bool operator()() {
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
                  return true;
              }
            }
          }
        }
      }

      return false;
    }
};

template<size_t SizeClique, typename Graph>
class Clique {
  private:
    const Graph graph;
    const size_t size_clique = SizeClique;

  public:
    consteval Clique(Graph g) : graph{g} {
    }

    consteval bool operator()() {
      switch (SizeClique) {
        case 0u:
        case 1u:
        case 2u:
          return true;

        case 3u:
          return Clique_3(graph)();

        case 4u:
          return Clique_4(graph)();
      }

      return false;
    }
};

int main() {
  constexpr array<array<int, 4>, 4> g{
    0, 1, 1, 1,
    1, 0, 1, 1,
    1, 1, 0, 1,
    1, 1, 1, 0
  };

  cout<<(Clique<4, decltype(g)>{g}());
}
