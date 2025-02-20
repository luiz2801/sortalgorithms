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
    //clearjson("plot/comparison.json");
    clearJson("plot/comparison.json");  // Corrigido para "clearJson" (com "J" maiúsculo)
    
    srand(time(0));  // Inicializa o gerador de números aleatórios
    int min = 19;
    int max = 24; // maximo possível é 30
    vector<int> A;
    shellTime(A, min, max);
    shellTimeOrdered(A, min, max);
    //heapTime(A, min, max);
    //iterativeTime(A, min, max);
    //quickTime(A, min, max);
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

