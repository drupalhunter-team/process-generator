#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct process {
   int processId;
   int cpuCycles;
   int memFootprint;
}process;

// Start pid from 
int init_pid = 0;
// Number of processes required
int numProcessesRequired;

int getProcessID() {
	return init_pid++;
}

int getCpuCycle() {
    return rand() % 11000 + 1000;
}

int getMemFootprint() {
	return rand() % 100 + 1;
}

void printProcess(process p) {
	printf("PID: %d\tCPU Cycles: %d\tMemory footprint: %d\n", p.processId, p.cpuCycles, p.memFootprint);
}

process createProcess() {

	process p;

	p.processId = getProcessID();
	p.cpuCycles = getCpuCycle();
	p.memFootprint = getMemFootprint();

	return p;

}

void createAllProcesses() {
	
	int i;

	for(i = 0; i < numProcessesRequired; i++) {
		printProcess(createProcess());
	}

}

int main(int argc, char **argv) { 

	// Error handling 
	if (argc < 2) {
        fprintf(stderr, "Error!\nUsage: %s [REQUIRED: number of processes] [OPTIONAL: start pid from]\n", argv[0]);
        return -1;
    }

    if (argv[2]) init_pid = atoi(argv[2]);

    numProcessesRequired = atoi(argv[1]);

    createAllProcesses();

    return 0;

}