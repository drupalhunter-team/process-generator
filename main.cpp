#include <iostream>
#include <random>

using namespace std;

class Generator {
    default_random_engine generator;
    normal_distribution<double> distribution;
    double min;
    double max;
public:
    Generator(double mean, double stddev, double min, double max):
        distribution(mean, stddev), min(min), max(max)
    {}

    double operator ()() {
        while (true) {
            double number = this->distribution(generator);
            if (number >= this->min && number <= this->max)
                return number;
        }
    }
};

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
process* pArray;

Generator randCycle(6000.0, 2000.0, 1000.0, 11000.0);
Generator randMemFootprint(20.0, 10.0, 1.0, 100.0);

int getProcessID() {
	return init_pid++;
}

void printAllProcesses(process* p) {
	
	for (int i = 0; i < numProcessesRequired; i++)
		cout << "PID: " << p[i].processId << "\t\t CPU cyles: " << p[i].cpuCycles << "\t\t Memory footprint:" << p[i].memFootprint << endl;
	
}

process createProcess() {

	process p;

	p.processId = getProcessID();
	p.cpuCycles = randCycle();
	p.memFootprint = randMemFootprint();

	return p;

}

void createAllProcesses() {

	for(int i = 0; i < numProcessesRequired; i++)
		pArray[i] = createProcess();
	
}

int main(int argc, char **argv) { 

	// Error handling 
	if (argc < 2) {
        cout << "Error!" << "\nUsage: " << argv[0] << " [REQUIRED: number of processes] [OPTIONAL: start pid from]\n" << endl;
        return -1;
    }

    if (argv[2]) init_pid = atoi(argv[2]);

    numProcessesRequired = atoi(argv[1]);

    pArray = new process[numProcessesRequired];

    createAllProcesses();
    printAllProcesses(pArray);

    // Cleanup
    delete pArray;

    return 0;

}