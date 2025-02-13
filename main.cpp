#include <iostream>

#include "algorithms/quicksort.h"  
#include "algorithms/heapsort.h"   
#include "algorithms/shellsort.h"  
#include "algorithms/toJson.h"
#include "utils/loadPythonModule.h"
#include "utils/calculateTime.h"

using namespace std;

int main() {
    srand(time(0));  // Inicializa o gerador de números aleatórios
    int exp = 18;
    vector<int> A;
    quickTime(A, exp);
    heapTime(A, exp);
    shellTime(A, exp);
    loadPythonModule();
    return 0;
}
