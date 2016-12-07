#include <stdio.h>
int main() {
  char buf[598][10];
  int i = 0;
  while (fgets(buf[i++], 10, stdin)) ;
  for (i = 0; i < 8; i++) {
    int letters[26] = { 0 }, max = 0;
    for (int j = 0; j < 598; j++) letters[buf[j][i]-'a']++;
    for (int j = 1; j < 26; j++)
      if (letters[j] > letters[max]) max = j;
    putchar(max+'a');
  }
  putchar('\n');
}
