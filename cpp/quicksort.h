//#include <iostream>
//#include <vector>
//using namespace std;
//
//int partition(vector<int>& A, int p, int r) {
//   int mid = p + (r - p) / 2; // Encontra o índice do meio
//   int x = A[mid]; // Pivô será o elemento no meio do vetor
//   swap(A[mid], A[r]); // Coloca o pivô na última posição para fazer a partição
//   int i = p - 1;
//  
//   for (int j = p; j < r; j++) {
//       if (A[j] <= x) {
//           i = i + 1;
//           swap(A[i], A[j]);
//       }
//   }
//   swap(A[i + 1], A[r]); // Coloca o pivô no lugar correto
//   return i + 1;
//}
//void quicksort(vector<int>& A, int p, int r) {
//   if (p < r) {
//       int q = partition(A, p, r);
//       quicksort(A, p, q - 1);  // Recursão na parte esquerda
//       quicksort(A, q + 1, r);  // Recursão na parte direita
//   }
//}
//
#include <iostream>
#include <vector>

// Função para particionar o vetor
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];  // Escolhe o pivô (último elemento)
    int i = low - 1;        // Índice do menor elemento

    for (int j = low; j < high; j++) {
        // Se o elemento atual for menor ou igual ao pivô
        if (arr[j] <= pivot) {
            i++;  // Incrementa o índice do menor elemento
            std::swap(arr[i], arr[j]);  // Troca os elementos
        }
    }

    // Coloca o pivô na posição correta
    std::swap(arr[i + 1], arr[high]);
    return i + 1;  // Retorna o índice do pivô
}

// Função recursiva para ordenar o vetor usando QuickSort
void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        // Particiona o vetor e obtém o índice do pivô
        int pi = partition(arr, low, high);

        // Ordena as duas partes
        quickSort(arr, low, pi - 1);  // Ordena a parte esquerda
        quickSort(arr, pi + 1, high); // Ordena a parte direita
    }
}
