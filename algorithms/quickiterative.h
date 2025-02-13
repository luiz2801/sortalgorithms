#include <vector>
#include <stack>

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int iterativePartition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void iterativeQuickSort(std::vector<int>& arr) {
    std::stack<int> stack;
    int low = 0;
    int high = arr.size() - 1;

    stack.push(low);
    stack.push(high);

    while (!stack.empty()) {
        high = stack.top();
        stack.pop();
        low = stack.top();
        stack.pop();

        int pivotIndex = iterativePartition(arr, low, high);

        if (pivotIndex - 1 > low) {
            stack.push(low);
            stack.push(pivotIndex - 1);
        }

        if (pivotIndex + 1 < high) {
            stack.push(pivotIndex + 1);
            stack.push(high);
        }
    }
}

