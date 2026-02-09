
function heapify(arr, n, i)
{
    let largest = i;

    let left  = i * 2 + 1;
    let right = i * 2 + 2;

    if(n > left && arr[largest] < arr[left])
    {
        largest = left;
    }
    if(n > right && arr[largest] < arr[right])
    {
        largest = right;
    }

    if(largest != i)
    {
        [arr[i], arr[largest]] = [arr[largest], arr[i]];

        heapify(arr, n, largest);
    }
}

function heapSort(arr)
{
    n = arr.length;

    for(let i = Math.floor(n / 2) - 1; i >=0; i--)
    {
        heapify(arr, n, i);
    }

    for(let i = n-1; i > 0; i--)
    {
        [arr[0], arr[i]] = [arr[i], arr[0]];
        heapify(arr, i, 0);
    }

    return arr;
}