#include <iostream>

#include "algorithms/quicksort.h"
#include "algorithms/quickiterative.h"
#include "algorithms/heapsort.h"
#include "algorithms/shellsort.h"
#include "utils/toJson.h"
#include "utils/loadPythonModule.h"
#include "utils/calculateTime.h"

using namespace std;

int main() {
    clearJson("plot/comparison.json");

    srand(time(0));  // Inicializa o gerador de números aleatórios
    int min = 1;
    int max = 18;
    vector<int> A;
    quickTime(A, min, max);
    iterativeTime(A, min, max);
    heapTime(A, min, max);
    shellTime(A, min, max);
    loadPythonModule();
    return 0;
    
    // to compile this file:
    // $ g++ -I/<pathToPython>/python/<version>/include/python<version> -o main main.cpp -L/<pathToPython>/python/<version>/lib -lpython<version>
    
    // you may find this path:
    // $ find ~/ -name Python.h

    // if you can't find this path, you may need to install python3-dev in your machine, for example:
    // $ sudo apt install python3-dev (for Ubuntu users)
    // $ sudo dnf install python3-devel (for Fedora users)
    
    // you may need to export the path:
    // $ export LD_LIBRARY_PATH=/<pathToPython>/python/<version>/lib:$LD_LIBRARY_PATH

}