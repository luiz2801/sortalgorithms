#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <chrono>
#include <cmath>
#include <Python.h>
#include "algorithms/quickiterative.h"
#include "algorithms/quicksort.h"
#include "algorithms/heapsort.h"
#include "algorithms/shellsort.h"
#include "algorithms/toJson.h"

using namespace std;

// Função para preencher o vetor com números aleatórios
void fillVector(vector<int>& A, int k) {
    A.clear();  // Limpa o vetor antes de preencher
    A.reserve(k);  // Evita realocações desnecessárias
    for (int i = 0; i < k; i++) {
        A.push_back(rand() % 20001 - 10000);  // Gera números entre -10000 e 10000
    }
}

// Função para medir o tempo de execução de um algoritmo de ordenação
template <typename Func>
long medirTempo(Func func, vector<int>& A) {
    auto inicio = chrono::high_resolution_clock::now();
    func(A);  // Chama o algoritmo de ordenação
    auto fim = chrono::high_resolution_clock::now();
    return chrono::duration_cast<chrono::microseconds>(fim - inicio).count();
}

void quickTime(vector<int>& A, int exp) {
    for (int i = pow(2, 10); i <= pow(2, exp); i *= 2) {
        fillVector(A, i);
        long long time = medirTempo([&](vector<int>& vec) { quickSort(vec, 0, vec.size() - 1); }, A);
        cout << "Quicksort: Tempo para ordenar vetor de " << i << " elementos: " << time / (float)1000000 << " s" << endl;
        writeJson("QuickSort", time, A.size() - 1);
    }
}

void iterativeTime(vector<int>& A, int exp) {
    for (int i = pow(2, 10); i <= pow(2, exp); i *= 2) {
        fillVector(A, i);
        long long time = medirTempo([&](vector<int>& vec) { iterativeQuickSort(vec); }, A);
        cout << "Quicksort iterativo: Tempo para ordenar vetor de " << i << " elementos: " << time / (float)1000000 << " s" << endl;
        writeJson("QuickIterative", time, A.size() - 1);
    }
}

void heapTime(vector<int>& A, int exp) {
    for (int i = pow(2, 10); i <= pow(2, exp); i *= 2) {
        fillVector(A, i);
        long long time = medirTempo([&](vector<int>& vec) { heapSort(vec); }, A);
        cout << "HeapSort: Tempo para ordenar vetor de " << i << " elementos: " << time / (float)1000000 << " s" << endl;
        writeJson("HeapSort", time, i);
    }
}

void shellTime(vector<int>& A, int exp) {
    for (int i = pow(2, 10); i <= pow(2, exp); i *= 2) {
        fillVector(A, i);
        long long time = medirTempo([&](vector<int>& vec) { shellSort(vec); }, A);
        cout << "ShellSort: Tempo para ordenar vetor de " << i << " elementos: " << time / (float)1000000 << " s" << endl;
        writeJson("ShellSort", time, i);
    }
}

int main() {
    clearJson("plot/comparison.json");  // Limpa o arquivo JSON antes de iniciar a gravação
    srand(time(0));  // Inicializa o gerador de números aleatórios
    int exp = 18;
    vector<int> A;
    
    quickTime(A, exp);
    iterativeTime(A, exp);
    heapTime(A, exp);
    shellTime(A, exp);

    // Inicializa o interpretador Python
    Py_Initialize();

    // Nome do arquivo do script (sem ".py")
    PyObject *sysPath = PySys_GetObject("path");
    PyList_Append(sysPath, PyUnicode_DecodeFSDefault("."));
    PyObject *pName = PyUnicode_DecodeFSDefault("plot.plot");

    // Importa o módulo (o script Python precisa estar no mesmo diretório ou no PYTHONPATH)
    PyObject *pModule = PyImport_Import(pName);
    Py_XDECREF(pName);

    if (pModule != nullptr) {
        PyObject *pFunc = PyObject_GetAttrString(pModule, "plotar_grafico");
        if (PyCallable_Check(pFunc)) {
            PyObject_CallObject(pFunc, nullptr);
        } else {
            std::cerr << "Erro: Função não encontrada ou não pode ser chamada.\n";
        }
        Py_XDECREF(pFunc);
        Py_XDECREF(pModule);
    } else {
        PyErr_Print();
        std::cerr << "Erro: Não foi possível importar o script Python.\n";
    }

    // Finaliza o interpretador Python
    Py_Finalize();

    return 0;
}
