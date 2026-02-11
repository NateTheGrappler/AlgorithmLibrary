function introPartition(arr, start, end) 
{
    let mid = Math.floor((start + end) / 2);

    // Fix: Need to use temporary variables for swapping
    if (arr[mid] < arr[start]) 
    {
        [arr[start], arr[mid]] = [arr[mid], arr[start]];
    }
    if (arr[end] < arr[start]) 
    {
        [arr[end], arr[start]] = [arr[start], arr[end]];
    }
    if (arr[mid] < arr[end]) 
    {
        [arr[mid], arr[end]] = [arr[end], arr[mid]];
    }

    let pivot = arr[mid];
    [arr[mid], arr[end - 1]] = [arr[end - 1], arr[mid]];

    let i = start;
    let j = end - 2;

    while (true) 
    {
        // Fix: Add bounds checking
        while (i <= end - 2 && arr[i] < pivot) { i++; }
        while (j >= start && pivot < arr[j]) { j--; }

        if (i >= j) { break; }

        [arr[i], arr[j]] = [arr[j], arr[i]];
        i++;
        j--;
    }
    [arr[i], arr[end - 1]] = [arr[end - 1], arr[i]];
    return i;
}

function introHeapify(arr, i, n, offset) 
{ 
    let largest = i;
    let left = 2 * i + 1;
    let right = 2 * i + 2;

    if (left < n && arr[offset + left] > arr[offset + largest])
    {
        largest = left;
    }
    if (right < n && arr[offset + right] > arr[offset + largest]) 
    {
        largest = right;
    }

    if (largest !== i) 
    {
        [arr[offset + i], arr[offset + largest]] = [arr[offset + largest], arr[offset + i]];
        introHeapify(arr, largest, n, offset);
    }
}

function introHeapSort(arr, start, end) 
{
    let n = end - start + 1;

    for (let i = Math.floor(n / 2) - 1; i >= 0; i--) 
    {
        introHeapify(arr, i, n, start);
    }
    for (let i = n - 1; i > 0; i--) 
    {
        [arr[start], arr[start + i]] = [arr[start + i], arr[start]];
        introHeapify(arr, 0, i, start);
    }
}

function introInsertionSort(arr, start, end) 
{
    for (let i = start + 1; i <= end; i++) 
    {
        let key = arr[i];
        let j = i - 1;
        while (j >= start && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

function introSortHelper(arr, start, end, max_depth) 
{
    let size = end - start + 1;

    if (size <= 16)
    {
        introInsertionSort(arr, start, end);
        return;
    }
    
    if (start >= end) return;
    
    if (max_depth === 0)
    {
        introHeapSort(arr, start, end);
        return;
    }

    let pivot = introPartition(arr, start, end);
    introSortHelper(arr, start, pivot - 1, max_depth - 1);
    introSortHelper(arr, pivot + 1, end, max_depth - 1);
}

function introSort(arr) {
    if (arr.length <= 1) return arr;
    
    let max_depth = 2 * Math.floor(Math.log2(arr.length));
    introSortHelper(arr, 0, arr.length - 1, max_depth);
    return arr;
}