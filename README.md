# Process generator

Write a program which simulates the generation of a set of k processes. Each process is
represented by a 3-tupel containing a unique process PID, the number of CPU-cycles required to complete the
process, and the size of the memory footprint. The required number of cycles is chosen from the interval <1,000,
11,000> with a mean of 6,000. While it is acceptable to distribute the required cycles uniformly, I suggest that you
attempt to implement a different distribution. The memory footprints of processes fall in the range of 1KB to
100KB with a mean memory footprint of 20 KB. You need to represent the set of k processes with a data structure
of your choice. Show how the values (required cycles and memory footprint) are distributed over your set of
processes. You must submit your program, a short description of your approach and the data structures used, and
the analysis of the value distribution.
