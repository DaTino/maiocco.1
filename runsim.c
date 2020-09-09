#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

  if (argc != 2) {
    perror("Error: Wrong number of args\n");
    return -1;
  }

  return 0;
}
