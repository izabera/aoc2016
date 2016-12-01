#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  FILE *path;
  if (argc > 1) path = fmemopen(argv[1], strlen(argv[1]), "r");
  else path = stdin;

  char matrix[2000][2000] = { 0 };

  int num, x = 0, y = 0;
  char dir, olddir = 'N';
  while (fscanf(path, "%c%d, ", &dir, &num) == 2) {
    switch (olddir) {
      case 'N': dir = dir == 'L' ? 'W' : 'E'; break;
      case 'W': dir = dir == 'L' ? 'S' : 'N'; break;
      case 'E': dir = dir == 'L' ? 'N' : 'S'; break;
      case 'S': dir = dir == 'L' ? 'E' : 'W'; break;
    }
    printf("%d %c\n", num, dir);
    switch (dir) {
      case 'N': while (num--) if (matrix[x+1000][--y+1000]) printf("%d %d\n", x, y), exit(0);
                              else  matrix[x+1000][y+1000] = 1; break;
      case 'W': while (num--) if (matrix[--x+1000][y+1000]) printf("%d %d\n", x, y), exit(0);
                              else  matrix[x+1000][y+1000] = 1; break;
      case 'E': while (num--) if (matrix[++x+1000][y+1000]) printf("%d %d\n", x, y), exit(0);
                              else  matrix[x+1000][y+1000] = 1; break;
      case 'S': while (num--) if (matrix[x+1000][++y+1000]) printf("%d %d\n", x, y), exit(0);
                              else  matrix[x+1000][y+1000] = 1; break;
    }
    olddir = dir;
  }
}
