# OperatingSystemsTwo
Code within repository is for Kent State course titled operating systems  <br />
<br />
Question Overview:
Considering a system with five processes P0 through P4 and three resources of type A, B, C. Resource type A has 10 instances, B has 5 instances and type C has 7 instances. <br />Suppose at time t0 following snapshot of the system has been taken:

| Process | Allocation | Max | Available |
| --- | --- | --- | --- |
| P0 | 0 1 0 | 7 5 3 | 3 3 2 |
| P1 | 2 0 0 | 3 2 2 |  |
| P2 | 3 0 2 | 9 0 2 |  |
| P3 | 2 1 1 | 2 2 2 |  |
| P4 | 0 0 2 | 4 3 3 |  |
<br />
Implement the Banker’s algorithm to answer the following questions： <br />
Is the system in a safe state? If Yes, then what is the safe sequence? <br />


## Compilation
To compile the program two steps are nessesary. Clone the respository and run the following:
```bash
g++ banker.cpp -pthread -o banker
./banker
```
## Output expectation
```bash
Allocated: 
P0: 0 1 0 
P1: 2 0 0 
P2: 3 0 2 
P3: 2 1 1 
P4: 0 0 2 

Max: 
P0: 7 5 3 
P1: 3 2 2 
P2: 9 0 2 
P3: 2 2 2 
P4: 4 3 3 

Available: 3 3 2 

The system is in safe state. Safe sequence is: 1 3 4 0 2 
```

### Side Notes
The provided table can be manipluated in addition to the number of processes and resources to test the safety of the system. <br />
Modifications to the matrix table need to follow the same structure as the table above and any changes in the number of resources or processes need to be changed in lines 17 and 18 of the safety.hpp file.