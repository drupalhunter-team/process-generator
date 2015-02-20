# Process generator

This is a C program which simulates the generation of a set of N number of processes. Each process is
represented by a 3-tupel containing the following:
<br><br>
1. Unique process PID<br>
2. Number of CPU-cycles required to complete the process<br>
3. Size of the memory footprint. <br>
<br>
The required number of cycles is chosen from the interval <1,000, 11,000> with a mean of 6,000. The memory footprints of processes fall in the range of 1KB to 100KB with a mean memory footprint of 20 KB. 

## Usage
This program accepts couple of parameters. See below for more info.
##### Compile:
`$ g++ main.cpp -std=c++0x`

##### Execute:
`$ ./a.out [1] [2]`

`[1]` - Number of processes you need to create <br>
`[2]` - Start PIDs with a predefined value (optional)


