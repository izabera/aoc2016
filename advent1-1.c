#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  FILE *path;
  if (argc > 1) path = fmemopen(argv[1], strlen(argv[1]), "r");
  else path = stdin;

  int num, x = 0, y = 0;
  char dir, olddir = 'N';
  while (fscanf(path, "%c%d, ", &dir, &num) == 2) {
    switch (olddir) {
      case 'N': dir = dir == 'L' ? 'W' : 'E'; break;
      case 'W': dir = dir == 'L' ? 'S' : 'N'; break;
      case 'E': dir = dir == 'L' ? 'N' : 'S'; break;
      case 'S': dir = dir == 'L' ? 'E' : 'W'; break;
    }
    switch (dir) {
      case 'N': y -= num; break;
      case 'W': x -= num; break;
      case 'E': x += num; break;
      case 'S': y += num; break;
    }
    olddir = dir;
  }
  printf("x = %d    y = %d   total = %d\n", x, y);
}
