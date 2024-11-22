// Anna Waltz
#include "safety.hpp"

int main() {
    int processes[numPro];
    for(int i = 0 ; i < numPro ; i++)
        processes[i] = i;


    std::ifstream table("matrix.txt", std::ios_base::in);
    if (!table) {
        std::cout << "Failed to open matrix.txt." << std::endl;
        return EXIT_FAILURE;
    }

    int max[numPro][numRe];
    int allocated[numPro][numRe];
    int available[numRe];

    //format of text file will match the given table for the assignment
    for (int i = 0; i < numPro; ++i) {
        // get the allocation and max matrixes
        for (int j = 0; j < numRe; ++j) table >> allocated[i][j];
        for (int j = 0; j < numRe; ++j) table >> max[i][j];

        // first row of file will contain avaliable resources
        if (i == 0) for (int j = 0; j < numRe; ++j) table >> available[j];
    }

    //print the given allocated matrix, good for debug
    cout << "Allocated: " << endl;
    for (int i = 0; i < numPro; ++i){
        cout << "P" << i << ": " ;
        for (int j = 0; j < numRe; ++j) 
            cout << allocated[i][j] << ' ';
        cout << "\n";
    }
    cout << endl;

    //print the given max matrix, good for debug
    cout << "Max: " << endl;
    for (int i = 0; i < numPro; ++i){
        cout << "P" << i << ": " ;
        for (int j = 0; j < numRe; ++j) 
            cout << max[i][j] << ' ';
        cout << "\n";
    }
    cout << endl;

    //print the given avaiable resources
    cout << "Available: ";
    for (int i = 0; i < numRe; ++i) 
        cout << available[i] << ' ';
    cout << "\n" << endl;

    // finally, Is the system in a safe state? 
    // If Yes, then what is the safe sequence?
    checkSafe(processes, available, max, allocated);
    
}
  