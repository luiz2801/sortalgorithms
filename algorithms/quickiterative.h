#include <vector>
#include <stack>
#include <algorithm> // For std::swap

void iterativeQuickSort(std::vector<int>& arr) {
    if (arr.empty()) return;

    std::stack<std::pair<int, int>> stack;
    stack.push({0, arr.size() - 1});

    while (!stack.empty()) {
        int low = stack.top().first;
        int high = stack.top().second;
        stack.pop();

        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; ++j) {
            if (arr[j] <= pivot) {
                ++i;
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[i + 1], arr[high]);
        int pivotIndex = i + 1;

        if (pivotIndex - 1 > low) {
            stack.push({low, pivotIndex - 1});
        }
        if (pivotIndex + 1 < high) {
            stack.push({pivotIndex + 1, high});
        }
    }
}
