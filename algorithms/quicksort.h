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
