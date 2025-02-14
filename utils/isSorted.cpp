#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib> // Para rand()
#include <ctime>   // Para srand()
#include <iomanip> // Para formatar saída
#include <cmath>

bool isSorted(const vector<int>& A) {
    for (size_t i = 1; i < A.size(); i++) {
        if (A[i] < A[i - 1]) {
            return false;
        }
    }
    return true;
}