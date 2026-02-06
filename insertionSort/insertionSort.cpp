#include <iostream>
#include <vector>

std::vector<int> insertionSort(std::vector<int> arr)
{
    int n = arr.size();

    if (n <= 1)
    {
        return arr;
    }

    for (int i = 1; i < n - 1; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (key < arr[j] && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}