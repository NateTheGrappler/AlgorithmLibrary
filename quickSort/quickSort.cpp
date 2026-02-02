#include <iostream>
#include <vector>
#include <math.h>
#include <chrono>
#include <random>

std::vector<int> quickSort(std::vector<int>& unsortedArray, int start, int end)
{
    if (start >= end)
    {
        return unsortedArray;
    }

    int pivot = partition(unsortedArray, start, end);
    quickSort(unsortedArray, start, pivot - 1);
    quickSort(unsortedArray, pivot+1, end);

    return unsortedArray;
}

int partition(std::vector<int>& unsortedArray, int start, int end)
{
    int pivot = unsortedArray[end];
    int i = start - 1;

    for (int j = start; j < end; j++)
    {
        if (pivot > unsortedArray[j])
        {
            i++;
            int temp = unsortedArray[i];
            unsortedArray[i] = unsortedArray[j];
            unsortedArray[j] = temp;
        }
    }
    i++;
    int temp = unsortedArray[i];
    unsortedArray[i] = unsortedArray[end];
    unsortedArray[end] = temp;

    return i;
}

int main()
{


    //set up needed vars
    double min;
    double max;
    double n;
    std::vector<int> unsortedArray;

    //get info from user
    std::cout << "Min: ";
    std::cin >> min;
    std::cout << "Max: ";
    std::cin >> max;
    std::cout << "Number Of Elements: ";
    std::cin >> n;

    //randomly generate array given params
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(min, max);

    for (int i = 0; i < n; i++)
    {
        unsortedArray.push_back(distrib(gen));
    }

    //time array and actuall call the sorting function
    auto startTime = std::chrono::high_resolution_clock::now();
    std::vector<int> sortedArray = quickSort(unsortedArray, 0, unsortedArray.size()-1);
    auto endTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> totalTime = endTime - startTime;

    //print out the array and the time it took to sort it
    //for (int i = 0; i < sortedArray.size(); i++)
    //{
    //    std::cout << sortedArray[i] << ", ";
    //}
    std::cout << "\n\nTotal Time To Sort Array: " << totalTime.count() << " seconds\n";


    return 0;
}