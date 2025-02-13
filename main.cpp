#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <chrono>
#include <cmath>

#include "algorithms/quicksort.h"  
#include "algorithms/heapsort.h"   
#include "algorithms/shellsort.h"  
#include "algorithms/toJson.h"

using namespace std;

// Função para preencher o vetor com números aleatórios
void preencherVetor(vector<int>& A, int k) {
    A.clear();  // Limpa o vetor antes de preencher
    A.reserve(k);  // Evita realocações desnecessárias
    for (int i = 0; i < k; i++) {
        A.push_back(rand() % 20001 - 10000);  // Gera números entre -10000 e 10000
    }
}


// Função para medir o tempo de execução de um algoritmo de ordenação
template <typename Func>
long medirTempo(Func func, vector<int>& A) {
    // Marca o tempo de início
    auto inicio = chrono::high_resolution_clock::now();
    
    // Chama a função de ordenação passada como argumento
    func(A);  
    
    // Marca o tempo de término
    auto fim = chrono::high_resolution_clock::now();
    
    // Calcula e retorna a diferença em milissegundos entre o tempo de início e fim
    return chrono::duration_cast<chrono::microseconds>(fim - inicio).count();
}



void fazQuick(vector<int>& A, int exp) {
    for (int i = pow(2, 10); i <= pow(2, exp); i *= 2) {  // Limitação para tamanhos mais controlados
        preencherVetor(A, i);
        long long tempoQuick = medirTempo([&](vector<int>& vec) { quickSort(vec, 0, vec.size() - 1); }, A);
        cout << "Quicksort: Tempo para ordenar vetor de " << i << " elementos: " << tempoQuick / (float)1000000 << " s" << endl;
        // Aqui chamamos a função writeJson
        writeJson("QuickSort", tempoQuick, A.size() - 1, i);
    }
}


void fazHeap(vector<int>& A, int exp) {
    for (int i = pow(2, 10); i <= pow(2, exp); i *= 2) {  // Limitação para tamanhos mais controlados
        preencherVetor(A, i);
        long long tempoHeap = medirTempo([&](vector<int>& vec) { heapSort(vec); }, A);
        cout <<"HeapSort: Tempo para ordenar vetor de " << i << " elementos: " << tempoHeap/(float)1000000 << " s" << endl;
        // Aqui chamamos a função writeJson
        writeJson("HeapSort", tempoHeap, i);
    }
}

void fazShell(vector<int>& A, int exp) {
    for (int i = pow(2, 10); i <= pow(2, exp); i *= 2) {  // Limitação para tamanhos mais controlados
        preencherVetor(A, i);
        long long tempoShell = medirTempo([&](vector<int>& vec) { shellSort(vec); }, A);
        cout <<"ShellSort: Tempo para ordenar vetor de " << i << " elementos: " << tempoShell/(float)1000000 << " s" << endl;
        // Aqui chamamos a função writeJson
        writeJson("ShellSort", tempoShell, i);
    }
}


int main() {
    srand(time(0));  // Inicializa o gerador de números aleatórios
    int exp = 15;
    vector<int> A;
    fazQuick(A, exp);
    fazHeap(A, exp);
    fazShell(A, exp);
    return 0;
}
