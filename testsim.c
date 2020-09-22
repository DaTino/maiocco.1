//testsim.c by Alberto Maiocco
// 9/22/20
//should run according to ex 3.9's parameters...

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int n;
	int sleep_time;

	if (argc <= 2) {
		perror("Error: Incorrect arg amount");
		exit(-1);
	}

	//take in args here, sleep_time then amt of child proc
	sscanf(argv[1], "%d", &sleep_time);
	sscanf(argv[2], "%d", &n);

	int i;
	for(i=n; i>0; i--) {
		printf("Process %d w/ Repeat: %d, sleep_time remaining: %d s\n", getpid(), i, sleep_time);
		sleep(sleep_time);
	}

	printf("Child Process %d has been slain. Glory upon the Klingon Empire.\n", getpid());

	return sleep_time;

}
