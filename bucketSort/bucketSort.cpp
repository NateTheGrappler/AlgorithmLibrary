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

std::vector<int> bucketSort(std::vector<int>& arr)
{
    const int n = arr.size();
    int min_val = *std::min_element(arr.begin(), arr.end());
    int max_val = *std::max_element(arr.begin(), arr.end());
    std::vector<std::vector<int>> buckets(n);

    for (int num : arr)
    {
        double normalized = static_cast<double>(num - min_val) / (max_val - min_val);
        int bucketIndex = static_cast<int>(normalized * n);
        if (bucketIndex == n) 
        {
            bucketIndex = n - 1;
        }
        buckets[bucketIndex].push_back(num);
    }

    for (std::vector<int>& bucket : buckets)
    {
        if (!bucket.empty())
        {
            insertionSort(bucket);
        }
    }

    int index = 0;
    for (const std::vector<int>& bucket : buckets)
    {
        for (int num : bucket)
        {
            arr[index] = num;
            index += 1;
        }
    }

    return arr;
}