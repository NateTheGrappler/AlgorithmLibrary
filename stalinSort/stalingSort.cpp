#include <vector>

std::vector<int> stalinSort(std::vector<int> arr)
{
    if (arr.size() == 0)
    {
        return arr;
    }

    int firstElement = arr[0];
    std::vector<int> sorted_list = { firstElement };

    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] >= sorted_list[sorted_list.size() - 1])
        {
            sorted_list.push_back(arr[i]);
        }
    }
    return sorted_list;
}
