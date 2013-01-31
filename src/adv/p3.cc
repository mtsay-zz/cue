#include<stdio.h>

char path[32];
int map[5][5] = {
  { 8, 8, 4, 4, 5 },
  { 4, 9, 6, 4, 8 },
  { 8, 6, 4, 1, 2 },
  { 4, 8, 2, 6, 3 },
  { 0, 6, 8, 8, 4 }
};

int can_go(char direction, int x, int y) {
  switch(direction) {
    case 'u':
      return y > 0;
    case 'd':
      return y < 4;
    case 'l':
      return x > 0;
    case 'r':
      return x < 4;
  }

  return 0;
}

int search(char *, int, int, int);
int go(char *curr, char d, int x, int y, int cost) {
  int dy = 0, dx = 0;
  switch(d) {
    case 'u':
      dy = -1;
      break;
    case 'd':
      dy = 1;
      break;
    case 'l':
      dx = -1;
      break;
    case 'r':
      dx = 1;
      break;
  }

  *curr = d;
  return search(curr + 1, x + dx, y + dy, cost + map[y + dy][x + dx]); 
}

int search(char *curr, int x, int y, int cost) {
  if (x == 4 && y == 0)
    return *curr = '\0', cost == 35;
  else if (cost > 35)
    return 0;

  for (char *d = "ruld"; *d; d++)
    if (can_go(*d, x, y)
      && go(curr, *d, x, y, cost))
      return 1;
  return 0;
}

int main() {
  if (search(path, 0, 4, 0))
    printf("solution: %s\n", path);
}
