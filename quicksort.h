#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& A, int p, int r){
    int x = A[r]; //pivot
    int i = p-1;
    
    for (int j = p; j < r; j++){
        if (A[j] <= x){
            i = i + 1;
            swap(A[i], A[j]);
        }
    }
    swap(A[i + 1], A[r]); //put the pivot in the right position
    return i + 1;
};


void quicksort(vector<int>& A, int p, int r){
    if (p < r){
        int q = partition(A, p, r);
        quicksort(A, p, q - 1);
        quicksort(A, q + 1 , r);
    }  
    //return A;
};

