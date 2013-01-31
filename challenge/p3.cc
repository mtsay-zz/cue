#include <stdio.h>

int nx[] = { 3, 4, 9, 14, 15, 19, 28, 37, 47, 50, 54, 56, 59, 61, 70, 73, 78, 81, 92, 95, 97, 99, 0 };
int map[100];

void init_map() {
  for (int *ni = nx; *ni; ni++)
    map[*ni] = 1;
}

int count(int *ni, int sum, int num) {
  if (*ni)
    return count(ni + 1, sum + *ni, num + 1) + count(ni + 1, sum, num);
  else if (sum < 100 && num > 1)
    return map[sum];
  else
    return 0; 
}

int main() {
  init_map();

  printf("%d\n", count(nx, 0, 0));
}
