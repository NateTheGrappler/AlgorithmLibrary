#include <iostream>
#include <vector>

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


int main()
{

    std::vector<int> unsortedArray = { 43, 30, 23, 8, 4, 17, 40, 19, 44, 49, 9, 38, 50, 39, 44, 23, 8, 6, 4, 28 };

    std::vector<int> sortedArray = bubbleSort(unsortedArray);

    for (int i = 0; i < sortedArray.size(); i++)
    {
        std::cout << sortedArray[i] << std::endl;
    }

    return 0;
}