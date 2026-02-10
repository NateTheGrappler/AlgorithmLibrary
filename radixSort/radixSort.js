function countSortHelper(arr, n, exp)
{
    let output = new Array(n).fill(0);
    let count = new Array(10).fill(0);

    for(let i = 0; i < n; i++)
    {
        let digit = Math.floor(Math.abs(arr[i]) / exp) % 10;
        count[digit]++;
    }

    for(let i = 1; i < 10; i++)
    {
        count[i] += count[i-1];
    }

    for(let i = n - 1; i >= 0; i--)
    {
        let digit = Math.floor(Math.abs(arr[i]) / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }
    for(let i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}
function radixSort(arr)
{
    let n = arr.length;
    let maxVal = Math.max(...arr);

    for(let exp = 1; Math.floor(maxVal / exp) > 0; exp *= 10)
    {
        countSortHelper(arr, n, exp);
    }
}