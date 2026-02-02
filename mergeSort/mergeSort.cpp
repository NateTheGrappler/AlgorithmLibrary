#include <iostream>
#include <vector>
#include <math.h>
#include <chrono>
#include <random>

std::vector<int> mergeSort_Helper(std::vector<int> left, std::vector<int> right);

std::vector<int> bubbleSort(std::vector<int>& unsortedArray)
{
    int lengthOfArray = unsortedArray.size();
    for (int i = 0; i < lengthOfArray; i++)
    {
        for (int j = 0; j < lengthOfArray - i - 1; j++)
        {
            if (unsortedArray[j] > unsortedArray[j + 1])
            {
                int greaterVal = unsortedArray[j];
                int lowerVal = unsortedArray[j + 1];
                unsortedArray[j] = lowerVal;
                unsortedArray[j + 1] = greaterVal;
            }
        }
    }
    return unsortedArray;
}

std::vector<int> mergeSort(std::vector<int>& unsortedArray)
{
    if (unsortedArray.size() <= 1)
    {
        return unsortedArray;
    }

    size_t mid = unsortedArray.size()/2;
    std::vector<int> left_array;
    std::vector<int> right_array;
    for (size_t i = 0; i < mid; ++i)
    {
        left_array.push_back(unsortedArray[i]);
    }
    for (size_t i = mid; i < unsortedArray.size(); i++)
    {
        right_array.push_back(unsortedArray[i]);
    }

    left_array = mergeSort(left_array);
    right_array = mergeSort(right_array);
    
    return mergeSort_Helper(left_array, right_array);
}

std::vector<int> mergeSort_Helper(std::vector<int> left, std::vector<int> right)
{
    std::vector<int> result;
    size_t i = 0;
    size_t j = 0;

    while (i < left.size() && j < right.size())
    {
        if(left[i] < right[j])
        {
            result.push_back(left[i]);
            i++;
        }
        else
        {
            result.push_back(right[j]);
            j++;
        }
    }

    while (i < left.size())
    {
        result.push_back(left[i]);
        i++;
    }
    while (j < right.size())
    {
        result.push_back(right[j]);
        j++;
    }

    return result;

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
    std::vector<int> sortedArray = mergeSort(unsortedArray);
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