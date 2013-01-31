#include<assert.h>
#include <stdio.h>

long s = 6;

void msrand(long seed) {
  s = seed;
}

long mrand() {
  return s = (69069 * s + 1) % (1L << 32);
}

int next() {
  return (int)(mrand() % 36);
}

int main() {
  msrand(6);
  assert(next() == 19);
  assert(next() == 16);
  printf("%d\n", next());
  printf("%d\n", next());
  printf("%d\n", next());
} 
