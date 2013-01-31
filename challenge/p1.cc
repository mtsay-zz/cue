#include <stdio.h>

#define BUFFER_SIZE 2096
char buf[BUFFER_SIZE];

char *pm;
int lm;

int f(char *p, char *q) {
  while(p < q)
    if (*p == *q)
      p++, q--;
    else
      return 0;
  return 1;
}

int main() {
  scanf("%s", buf);

  for (char *p = buf; *p; p++)
    for (char *q = p; *q; q++)
      if (f(p, q) && q - p > lm)
        pm = p, lm = q - p + 1;

  pm[lm] = '\0';
  printf("%s\n", pm);
}
