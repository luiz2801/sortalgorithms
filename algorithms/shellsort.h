#include <iostream>
#include <vector>
using namespace std;

// Função ShellSort
void shellSort(vector<int>& A) {
    int n = A.size();
    for (int gap = n / 2; gap > 0; gap /= 2) { // Reduzindo o intervalo pela metade
        for (int i = gap; i < n; i++) {
            int temp = A[i];
            int j;
            // Move os elementos que estão "gap" posições atrás e são maiores que o temp
            for (j = i; j >= gap && A[j - gap] > temp; j -= gap) {
                A[j] = A[j - gap];
            }
            A[j] = temp;
        }
    }
}


