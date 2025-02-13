#include <iostream>
#include <vector>
using namespace std;

int shellSort(vector<int>& vec)
{
    int n = vec.size();
    
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            int temp = vec[i];
            int j;
            for (j = i; j >= gap && vec[j - gap] > temp; j -= gap)
                vec[j] = vec[j - gap];
            vec[j] = temp;
        }
    }
    return 0;
}

