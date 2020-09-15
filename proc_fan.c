#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

  //check num arguments, should only be 2
  if (argc < 2) {
    perror("Error: Wrong number of args\n");
    return 1;
  }

  char *nval = NULL;

  //get opt section, only n is needed
  int opt, index;
  while((opt=getopt(argc, argv, "n:")) != -1) {
    switch (opt) {
      case 'n':
        nval = optarg;
	break;
      case '?':
        if (optopt == 'n') {
          fprintf(stderr, "Option -%c requires an argument.\n", optopt);
        }
        else if(isprint(optopt)) {
          fprintf(stderr, "Uknown option `-%c`.\n", optopt);
        }
        else {
          fprintf (stderr, "Unkown option character `\\x%x`.\n", optopt);
        }
        return 1;
      default:
        abort();
    }
  }

  //exec is gonna go here in order to run test sim
  //think the process limiting is gonna go here?
  printf("%d\n", atoi(nval));

  for (index = optind; index < argc; index++) {
    printf("Non-option argument %s\n", argv[index]);
  }

  return 0;
}
