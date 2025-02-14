#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

// Retorna o índice do filho esquerdo
int leftHeap(int i) {
    return 2 * i + 1;
}

// Retorna o índice do filho direito
int rightHeap(int i) {
    return 2 * i + 2;
}

// Garante a propriedade de Heap Máximo
void maxHeap(vector<int>& A, int i, int n) {
    int l = leftHeap(i);
    int r = rightHeap(i);
    int maior = i;

    if (l < n && A[l] > A[maior]) {
        maior = l;
    }
    if (r < n && A[r] > A[maior]) {
        maior = r;
    }
    if (maior != i) {
        swap(A[i], A[maior]);
        maxHeap(A, maior, n);
    }
}

// Constrói um Heap Máximo a partir de um vetor
void buildMaxHeap(vector<int>& A) {
    int n = A.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeap(A, i, n);
    }
}

// Verifica se o vetor está ordenado corretamente


void heapSort(vector<int>& A) {
    int n = A.size();
    buildMaxHeap(A);
    for (int i = n - 1; i > 0; i--) {
        swap(A[0], A[i]);
        maxHeap(A, 0, i);
    }
}