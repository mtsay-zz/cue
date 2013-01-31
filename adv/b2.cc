#include<stdio.h>

char path[128];
int map[12][12] = {
  { 0, 8, 1, 7, 8, 8, 5, 2, 9, 5, 9, 5 },
  { 8, 5, 1, 1, 5, 6, 9, 4, 4, 5, 2, 1 },
  { 7, 2, 3, 5, 2, 9, 2, 6, 9, 3, 9, 4 },
  { 9, 2, 5, 9, 8, 9, 5, 7, 7, 5, 9, 6 },
  { 2, 4, 6, 7, 1, 4, 2, 6, 6, 2, 5, 8 },
  { 2, 8, 1, 5, 3, 8, 4, 9, 7, 5, 2, 3 },
  { 2, 9, 3, 5, 6, 7, 2, 4, 9, 4, 2, 5 },
  { 6, 3, 1, 7, 8, 2, 3, 3, 6, 7, 9, 3 },
  { 2, 5, 7, 4, 2, 7, 8, 5, 5, 3, 5, 8 },
  { 5, 2, 9, 8, 3, 6, 1, 4, 9, 5, 6, 3 },
  { 4, 6, 9, 8, 5, 4, 9, 7, 6, 4, 6, 8 },
  { 2, 7, 7, 1, 9, 9, 7, 3, 7, 2, 2, 5 }
};

int can_go(char direction, int x, int y) {
  switch(direction) {
    case 'u':
      return y > 0;
    case 'd':
      return y < 11;
    case 'l':
      return x > 0;
    case 'r':
      return x < 11;
  }

  return 0;
}

int update_cost(int x, int y, int step, int cost) {
  return cost + map[y][x] + (x == 11 && y == 11 ? 0 : step);
}

int search(char *, int, int, int, int);
int go(char *curr, char d, int x, int y, int step, int cost) {
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
  return search(curr + 1, x + dx, y + dy, step + 1, update_cost(x + dx, y + dy, step, cost)); 
}

int search(char *curr, int x, int y, int step, int cost) {
  if (x == 11 && y == 11)
    return *curr = '\0', cost == 444;
  else if (cost > 444)
    return 0;

  for (char *d = "rdlu"; *d; d++)
    if (can_go(*d, x, y)
      && go(curr, *d, x, y, step, cost))
      return 1;
  return 0;
}

int main() {
  if (search(path, 0, 0, 0, 0))
    printf("solution: %s\n", path);
}
