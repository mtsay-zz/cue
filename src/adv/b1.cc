#include <stdio.h>

long s;

void msrand(long seed) {
  s = seed;
}

long mrand() {
  return s = (69069 * s + 1) % (1L << 32);
}

int next() {
  return (int)(mrand() % 36);
}

int p[] = { 34, 27, 16, 1, 34, 31, 24, 17, 34, 35, 16, 13, 0 };

int main() {
  msrand(6);

  while(1) {
    int *i = p;

    while (*i && next() == *i)
      i++;

    if (!*i) {
      printf("%d\n", next());
      printf("%d\n", next());
      printf("%d\n", next());
      return 0;
    }
  }
} 
