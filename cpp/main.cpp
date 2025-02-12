#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "quicksort.h"  
#include "heapsort.h"   
#include "shellsort.h"  
#include <chrono>
#include <cmath>

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
// O template permite medir o tempo para qualquer função de ordenação
template <typename Func>
long long medirTempo(Func func, vector<int>& A) {
    // Marca o tempo de início
    auto inicio = chrono::high_resolution_clock::now();
    
    // Chama a função de ordenação passada como argumento
    func(A);  
    
    // Marca o tempo de término
    auto fim = chrono::high_resolution_clock::now();
    
    // Calcula e retorna a diferença em milissegundos entre o tempo de início e fim
    return chrono::duration_cast<chrono::microseconds>(fim - inicio).count();
}
// Função para rodar o QuickSort e medir o tempo
void fazQuick(vector<int>& A) {
    for (int i = pow(2, 10); i <= pow(2,30); i *= 2) {  // Limitação para tamanhos mais controlados
        preencherVetor(A, i);
        long long tempoQuick = medirTempo([&](vector<int>& vec) { quickSort(vec, 0, vec.size() - 1); }, A);
        cout <<"Quicksort: Tempo para ordenar vetor de " << i << " elementos: " << tempoQuick / (float)1000000<< " s" << endl;
    }
}

// Função para rodar o HeapSort e medir o tempo
void fazHeap(vector<int>& A) {
    for (int i = pow(2, 10); i <= pow(2,30); i *= 2) {  // Limitação para tamanhos mais controlados
        preencherVetor(A, i);
        long long tempoHeap = medirTempo([&](vector<int>& vec) { heapSort(vec); }, A);  
        cout <<"HeapSort: Tempo para ordenar vetor de " << i << " elementos: " << tempoHeap/(float)1000000 << " s" << endl;
    }
}

// Função para rodar o ShellSort e medir o tempo
void fazShell(vector<int>& A) {
    for (int i = pow(2, 5); i <= pow(2,25); i *= 2) {  // Limitação mais controlada para ShellSort
        preencherVetor(A, i);
        long long tempoShell = medirTempo([&](vector<int>& vec) { shellSort(vec); }, A);
        cout <<"ShellSort: Tempo para ordenar vetor de " << i << " elementos: " << tempoShell/(float)1000000 << " s" << endl;
    }
}


int main() {
    srand(time(0));  // Inicializa o gerador de números aleatórios

    vector<int> A;
    for (int i = 0; i < 11; i++){
        fazHeap(A);
        std::cout<<endl;
    }  
    for (int i = 0; i < 11; i++){
        fazQuick(A);
        std::cout<<endl;
    }
  
    
    //fazQuick(A); 

    //fazQuick(A);  

    return 0;
}
