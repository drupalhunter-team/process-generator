#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Start pid from 
int init_pid = 0;
// Number of processes required
int numProcessesRequired;

typedef struct process {
   int processId;
   int cpuCycles;
   int memFootprint;
}process;

int getProcessID() {
	return init_pid++;
}

int getCpuCycle() {
    return rand() % 11000 + 1000;
}

int getMemFootprint() {
	return rand() % 100 + 1;
}

void printProcesses(process *pArray) {

	int i;

	for (i = 0; i < numProcessesRequired; i++) {
		printf("%d. PID: %d\tCPU Cycles: %d\tMemory footprint: %d\n", i, pArray[i].processId, pArray[i].cpuCycles, pArray[i].memFootprint);
	}

}

void createProcesses() {

	int i;
	process p[numProcessesRequired];

	for (i = 0; i < numProcessesRequired; i++) {
		p[i].processId = getProcessID();
		p[i].cpuCycles = getCpuCycle();
		p[i].memFootprint = getMemFootprint();
		printf("%d\n", p[i].memFootprint);
	} 

	printProcesses(p);

}

int main(int argc, char **argv) { 

	// Error handling 
	if (argc < 2) {
        fprintf(stderr, "Error!\nUsage: %s [REQUIRED: number of processes] [OPTIONAL: start pid from]\n", argv[0]);
        return -1;
    }

    numProcessesRequired = atoi(argv[1]);

    createProcesses();

    return 0;

}