#include <stdio.h>
#include <stdlib.h>

// Start pid from 
int init_pid = 0;

struct process {
   int processId;
   int cpuCycles;
   int memFootprint;
};

void createProcesses(int numProcessesRequired) {

}

int main(int argc, char **argv) { 

	// Error handling 
	if (argc < 2) {
        fprintf(stderr, "Error!\nUsage: %s [REQUIRED: number of processes] [OPTIONAL: start pid from]\n", argv[0]);
        return -1;
    }

    createProcesses(atoi(argv[1]));

    return 0;

}