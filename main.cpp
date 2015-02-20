#include <iostream>
#include <random>

using namespace std;

struct process {
   int processId;
   int cpuCycles;
   int memFootprint;
};

// Start pid from 
int init_pid = 0;
// Number of processes required
int numProcessesRequired;
// Where all processes will be stored
process* pArray = new process;

int getProcessID() {
	return init_pid++;
}

int getCpuCycle() {
    return rand() % 11000 + 1000;
}

int getMemFootprint() {
	return rand() % 100 + 1;
}

void printAllProcesses(process* p) {

	int i;

	for (i = 0; i < numProcessesRequired; i++) {
		cout << "PID: " << p[i].processId << "\t\t CPU cyles: " << p[i].cpuCycles << "\t\t Memory footprint:" << p[i].memFootprint << endl;
	}
	
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
		pArray[i] = createProcess();
	}

}

int main(int argc, char **argv) { 

	// Error handling 
	if (argc < 2) {
        cout << "Error!" << "\nUsage: " << argv[0] << " [REQUIRED: number of processes] [OPTIONAL: start pid from]\n" << endl;
        return -1;
    }

    if (argv[2]) init_pid = atoi(argv[2]);

    numProcessesRequired = atoi(argv[1]);

    createAllProcesses();
    printAllProcesses(pArray);

    // Cleanup
    delete pArray;

    return 0;

}