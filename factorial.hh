#ifndef FACTORIAL_H
#define FACTORIAL_H

template<typename TypeN, TypeN N>
consteval TypeN factorial(void) {
  if (0==N || 1==N) {
    return 1;
  }

  return N * factorial<TypeN, (N>1)*(N-1)>();
}

#endif

