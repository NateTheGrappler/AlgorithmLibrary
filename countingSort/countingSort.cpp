#include <iostream>
#include <vector>
#include <math.h>

std::vector<int> countingSort(std::vector<int> arr)
{
    int n = arr.size();
    int maxValue = 0;

    for (int i = 0; i < n; i++)
    {
        maxValue = std::max(maxValue, arr[i]);
    }

    std::vector<int> countArray(maxValue + 1, 0);

    for (int value : arr)
    {
        countArray[value] += 1;
    }

    for (int i = 1; i <= maxValue; i++)
    {
        countArray[i] += countArray[i - 1];
    }

    std::vector<int> answerArray(n);
    for (int i = n - 1; i >= 0; i--)
    {
        answerArray[countArray[arr[i]] - 1] = arr[i];
        countArray[arr[i]] -= 1;
    }

    return answerArray;
}