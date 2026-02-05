#include <iostream>
#include <vector>
#include <math.h>
#include <chrono>
#include <random>

bool bogoSortCheck(std::vector<int> array)
{
    for (int i = 0; i < array.size()-1; i++)
    {
        if (array[i] > array[i + 1])
        {
            return false;
        }
    }
    return true;
}

std::vector<int> bogoSort(std::vector<int>& unsortedArray)
{
    std::random_device rd;
    std::mt19937 gen(rd());

    while (!bogoSortCheck(unsortedArray))
    {

        for (size_t i = unsortedArray.size() - 1; i > 0; i--)
        {
            std::uniform_int_distribution<size_t> distrib(0, i);
            size_t j = distrib(gen);
            int temp = unsortedArray[i];
            unsortedArray[i] = unsortedArray[j];
            unsortedArray[j] = temp;
        }

    }

    return unsortedArray;
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
    std::vector<int> sortedArray = bogoSort(unsortedArray);
    auto endTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> totalTime = endTime - startTime;

    //print out the array and the time it took to sort it
    for (int i = 0; i < sortedArray.size(); i++)
    {
        std::cout << sortedArray[i] << ", ";
    }
    std::cout << "\n\nTotal Time To Sort Array: " << totalTime.count() << " seconds\n";


    return 0;
}