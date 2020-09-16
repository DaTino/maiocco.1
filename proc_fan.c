#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_BUF 128


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
        if(isprint(optopt)) {
          fprintf(stderr, "Uknown option `-%c`.\n", optopt);
        }
        if {
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

  int proc_limit = atoi(nval); 
  pid_t childpid = 0;

  //work on printing lines from text document...
  char buffer[MAX_BUF];
  FILE *fp;
  fp = fopen("testing.data", "r");
  if(fp == NULL) {
  	perror("Error: testing.data could not be opened.");
	return(-1);
  }	
  while(fgets(buffer, MAX_BUF-1, fp)!=NULL){
  	printf("%s\n", buffer);
  } 

  for (index = optind; index < argc; index++) {
    printf("Non-option argument %s\n", argv[index]);
  }

  return 0;
}
