//proc_fan.c by Alberto Maiocco
// 9/22/20

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
    return -1;
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
          perror("Error: Incorrect argument usage.");
          return -1;
        }
        if(isprint(optopt)) {
          fprintf(stderr, "Uknown option `-%c`.\n", optopt);
          perror("Error: Unknown option entered.");
          return -1;
        }
        else {
          fprintf (stderr, "Unkown option character `\\x%x`.\n", optopt);
          perror("Error: Unknown option character read.");
          return -1;
        }
        return 1;
      default:
        abort();
    }
  }

  //exec is gonna go here in order to run test sim <- don't need it cuz of stdin
  //think the process limiting is gonna go here?
  printf("%d\n", atoi(nval));

  int proc_limit = atoi(nval);
  pid_t childpid = 0;
  int proc_count = 0;
  int status = 0;
  int pid = 0;
  int total = 0;
  //work on printing lines from text document...
  char buffer[MAX_BUF];
  //don't really need a file pointer because we're reading in externally, right?

  //putting stuff in buffer not from file, but from < operator and stdin!!
  while (fgets(buffer, MAX_BUF-1, stdin) != NULL) {
    //makin babies
    if((childpid = fork()) == 0) {
      printf("Child: %d is born!\n", getpid());
      system(buffer);
      exit(EXIT_SUCCESS);
    }
    else {
      //this just counts total, not really what I want...
      //buffer needs to hold strings
      total++;
      proc_count++;
    }

    if(proc_count >= proc_limit) {
      do {
        pid = waitpid(-1, &status, WNOHANG);
        if (pid > 0) {
          proc_count--;
        }
      } while(pid==0);
    }

  }

  //waiting for death...
  do {
    pid = waitpid(-1, &status, WNOHANG);
    if (pid > 0) {
      proc_count--;
      printf("\nChild Slain %d, with Epitaph %d\n", pid, WEXITSTATUS(status));
    }
    //I think 0 means no status change while waiting?
  } while(pid==0 || proc_count > 0);
  printf("Total Children Forked: %d\n", total);

  return 0;
}
