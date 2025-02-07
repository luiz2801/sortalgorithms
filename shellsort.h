#include <iostream>
#include <vector>
using namespace std;

/* function to sort a vector using shellSort */
int shellSort(vector<int>& vec)
{
    int n = vec.size(); // Get the size of the vector
    
    // Start with a big gap, then reduce the gap
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        // Do a gapped insertion sort for this gap size.
        // The first gap elements vec[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is gap sorted
        for (int i = gap; i < n; i += 1)
        {
            // add vec[i] to the elements that have been gap sorted
            // save vec[i] in temp and make a hole at position i
            int temp = vec[i];

            // shift earlier gap-sorted elements up until the correct 
            // location for vec[i] is found
            int j;
            for (j = i; j >= gap && vec[j - gap] > temp; j -= gap)
                vec[j] = vec[j - gap];

            // put temp (the original vec[i]) in its correct location
            vec[j] = temp;
        }
    }
    return 0;
}

void printArray(const vector<int>& vec)
{
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;
}

