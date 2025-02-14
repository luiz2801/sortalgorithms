#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>
#include <iomanip>
#include <cstdlib> // Para rand()
#include <ctime>   // Para srand()

using namespace std;

// Função para preencher o vetor com números aleatórios
void fillVector(vector<int>& A, int k) {
    A.clear();  // Limpa o vetor antes de preencher
    A.reserve(k);  // Evita realocações desnecessárias
    for (int i = 0; i < k; i++) {
        A.push_back(rand() % 20001 - 10000);  // Gera números entre -10000 e 10000
    }
}



void fillSortedVector(std::vector<int>& A, int k) {
    A.clear();      // Limpa o vetor antes de preencher
    A.reserve(k);   // Evita realocações desnecessárias

    int start = -10000;  // Valor inicial para o primeiro elemento
    int step = (20000 + 1)/ k; // Passo para distribuir os valores ordenadamente

    for (int i = 0; i < k; i++) {
        A.push_back(start + i * step);
    }
}


// Função para medir o tempo de execução de um algoritmo de ordenação
template <typename Func>
long long medirTempo(Func func, vector<int>& A) {
    auto inicio = chrono::high_resolution_clock::now(); // Tempo inicial
    func(A); // Chama a função de ordenação passada como argumento
    auto fim = chrono::high_resolution_clock::now(); // Tempo final
    return chrono::duration_cast<chrono::microseconds>(fim - inicio).count(); // Retorna tempo em microssegundos
}


void quickTime(vector<int>& A, int min, int max) {
    for (int i = static_cast<int>(pow(2, min)); i <= static_cast<int>(pow(2, max)); i *= 2) {
        fillVector(A, i); //random
        //fillSortedVector(A, i);
        long long time = medirTempo([&](vector<int>& vec) { quickSort(vec, 0, vec.size() - 1); }, A);
        cout << fixed << setprecision(6) << "Quicksort: Tempo para ordenar vetor de " 
        << i << " elementos: " << time / 1000000.0 << " s" << endl;
        writeJson("QuickSort", time, i);
    }
}

void heapTime(vector<int>& A, int min, int max) {
    for (int i = static_cast<int>(pow(2, min)); i <= static_cast<int>(pow(2, max)); i *= 2) {
        fillVector(A, i);
        //fillSortedVector(A, i);
        long long time = medirTempo([&](vector<int>& vec) { heapSort(vec); }, A);
        cout << fixed << setprecision(6) << "HeapSort: Tempo para ordenar vetor de " << i 
             << " elementos: " << time / 1000000.0 << " s" << endl;
        writeJson("HeapSort", time, i);
    }
}




void iterativeTime(vector<int>& A, int min, int max) {
    for (int i = static_cast<int>(pow(2, min)); i <= static_cast<int>(pow(2, max)); i *= 2) {
        //fillVector(A, i);
        fillSortedVector(A, i);
        long long time = medirTempo([&](vector<int>& vec) { iterativeQuickSort(vec); }, A);
        cout << fixed << setprecision(6) << "Quicksort iterativo: Tempo para ordenar vetor de " << i 
             << " elementos: " << time / 1000000.0 << " s" << endl;
        writeJson("QuickIterative", time, i);
    }
}

void shellTime(vector<int>& A, int min, int max) {
    for (int i = static_cast<int>(pow(2, min)); i <= static_cast<int>(pow(2, max)); i *= 2) {
        fillVector(A, i);
        //fillSortedVector(A, i);
        long long time = medirTempo([&](vector<int>& vec) { shellSort(vec); }, A);
        cout << fixed << setprecision(6) << "ShellSort: Tempo para ordenar vetor de " << i 
             << " elementos: " << time / 1000000.0 << " s" << endl;
        writeJson("ShellSort", time, i);
    }
}
