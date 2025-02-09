#include <iostream>
#include <vector>
#include <cmath>
using namespace std;



int leftchild(int i){
    return 2*i+1;
}

int rightchild(int i){
    return 2*i+2;
}




void minHeapfy(vector<int> &A, int i){
    int left = leftchild(i);
    int right = rightchild(i);
    int lowest = i;
    if (left < A.size() && A[left] < A[lowest]){
        lowest = left;
    }
    if (right < A.size() && A[right] < A[lowest]){
        lowest = right;
    }
    if (lowest!= i){
        swap(A[i], A[lowest]);
        minHeapfy(A, lowest);
    }
}


void buildMinheap(vector<int> &A){
    int n = A.size();
    for (int i = n/2 -1 ; i >= 0 ; i-- ){
        minHeapfy(A, i);
    }
}



void printHeap(const vector<int>& A) {
    int n = A.size();
    int levels = log2(n) + 1; // Número de níveis da árvore

    int index = 0;
    for (int i = 0; i < levels; i++) {
        int nodes_in_level = pow(2, i); // Número de nós no nível atual
        for (int j = 0; j < nodes_in_level && index < n; j++) {
            cout << A[index] << " ";
            index++;
        }
        cout << endl;
    }
}



//int main(){
//    vector<int> A = {2, 3, 5, 6, 90, 14, 12, 15, 1, 8, 0};
//    
//    int b = 12;
//    int a = 10;
//    swap(a, b);
//    std::cout<<a<<b<<endl;
//
//    
//
//}