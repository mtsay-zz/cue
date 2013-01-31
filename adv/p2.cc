#include<stdio.h>

char stack[256];
int stack_top;
char buf[256];

void push(char c) {
  stack[stack_top++] = c;
}

char pop() {
  return stack[--stack_top];
}

char map[256];
void init_map() {
  map['}'] = '{';
  map[']'] = '[';
  map[')'] = '(';
}

int main() {
  scanf("%s", buf);

  init_map();

  for (int i = 0; buf[i]; i++)
    switch(buf[i]) {
      case '{':
      case '[':
      case '(':
        push(buf[i]);
        break;
      case '}':
      case ']':
      case ')':
        if (pop() != map[buf[i]])
          return printf("%d\n", i), 0;
        break;
    }
}
