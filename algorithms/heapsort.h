#include <iostream>
#include <vector>
using namespace std;


int dadHeap(int i){
    return i/2;
};

int leftHeap(int i){
    return 2*i + 1;
}

int rightHeap(int i){
    return 2*i + 2;
};


void maxHeap(vector<int>& A, int i, int n){
    int l = leftHeap(i);
    int r = rightHeap(i);
    //int n = A.size();
    int maior = i;
    if (l < n && A[l] > A[i]){ //check if the left son is bigger than the root
        maior = l;
    }
    if (r < n && A[r] > A[maior]){//check if the right son is bigger than the root
        maior = r;
    }
    if (maior != i){
        swap(A[i], A[maior]); 
        maxHeap(A, maior, n);
    }
};

void buildMaxHeap(vector<int> &A){
    int n = A.size();
    for (int i = n/2 - 1; i >= 0; i--){
        maxHeap(A, i, n);
    }
};


void heapSort(vector<int> &A){
    int n = A.size();
    
    for (int j = n; j > 1; j--){
        //std::cout<<"indo agora para o valor"<<j<<endl;
        int l = j;
        swap(A[l], A[j]);
        n = n - 1;
        maxHeap(A, l, n);
    }
};
