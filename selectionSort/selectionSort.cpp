#include <vector>
#include <iostream>

std::vector<int> selectionSort(std::vector<int> unsortedArray)
{
    int n = unsortedArray.size();
    for (int i = 0; i < n; i++)
    {
        int index = i;
        for (int j = i; j < n; j++)
        {
            if (unsortedArray[index] > unsortedArray[j])
            {
                index = j;
            }
        }
        int temp = unsortedArray[i];
        unsortedArray[i] = unsortedArray[index];
        unsortedArray[index] = temp;
    }

    return unsortedArray;
}