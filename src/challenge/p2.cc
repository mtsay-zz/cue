#include <stdio.h>

int a = 0;
int b = 1;

int fib() {
  a = a + b;
  b = a - b;
  return a;
}

int px[1000000];
int n = 2;

int prime() {
  int *pi = px;

  while(*pi)
    if (n % *pi)
      pi++;
    else
      n++, pi = px;
  return *pi = n;
}

int main() {
  int d, f, p, sd = 0;

  scanf("%d", &d);
  for (f = fib(); f < d; f = fib()) ;
  for (p = prime(); f != p; f < p ? f = fib() : p = prime()) ;

  f++;
  for (int *pi = px; *pi; pi++)
    if (!(f % *pi))
      sd += *pi;

  printf("%d\n", sd);
}
