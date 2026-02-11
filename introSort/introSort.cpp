#include <vector>
#include <math.h>
#include <iostream>
int introPartition(std::vector<int>& arr, int start, int end)
{
    int mid = (start + end) / 2;

    if (arr[mid] < arr[start])  { std::swap(arr[start], arr[mid]); }
    if (arr[end] < arr[start])  { std::swap(arr[end], arr[start]); }
    if (arr[mid] < arr[end])    { std::swap(arr[mid], arr[end]);   }

    int pivot = arr[mid];
    std::swap(arr[mid], arr[end - 1]);

    int i = start;
    int j = end - 2;

    while (true)
    {
        while (arr[i] < pivot) { i++; }

        while (pivot < arr[j]) { j -= 1; }

        if (i >= j) { break; }

        std::swap(arr[i], arr[j]);
        i++;
        j--;
    }

    std::swap(arr[i], arr[end - 1]);
    return i;
}
void introHeapify(std::vector<int>& arr, int i, int n, int offset)
{
    int largest = i;
    int left    = 2 * i + 1;
    int right   = 2 * i + 2;

    if (left < n && arr[offset + left] > arr[offset + largest])
    {
        largest = left;
    }
    if (right < n && arr[offset + right] > arr[offset + largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        std::swap(arr[offset + i], arr[offset + largest]);
        introHeapify(arr, largest, n, offset);
    }
}
void introHeapSort(std::vector<int>& arr, int start, int end)
{
    int n = end - start + 1;

    for (int i = n / 2 - 1; i >= 0; i--)
    {
        introHeapify(arr, i, n, start);
    }

    for (int i = n - 1; i > 0; i--)
    {
        std::swap(arr[start], arr[start + i]);
        introHeapify(arr, 0, i, start);
    }
    
}
void introInsertionSort(std::vector<int>& arr, int start, int end)
{
    for (int i = start + 1; i <= end; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= start && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j -= 1;
        }
        arr[j + 1] = key;
    }
}
void introSortHelper(std::vector<int>& arr, int start, int end, int max_depth)
{
    int size = end - start + 1;

    if (size <= 16)
    {
        introInsertionSort(arr, start, end);
        return;
    }

    if (max_depth == 0)
    {
        introHeapSort(arr, start, end);
        return;
    }

    int pivot = introPartition(arr, start, end);
    introSortHelper(arr, start, pivot - 1, max_depth - 1);
    introSortHelper(arr, pivot + 1, end , max_depth - 1);

}
std::vector<int> introSort(std::vector<int>& arr)
{
    int max_depth = 2 * std::floor(std::log2(arr.size()));
    introSortHelper(arr, 0, arr.size() - 1, max_depth);
    return arr;
}