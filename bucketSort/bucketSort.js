
function insertionSort(arr)
{
    let n = arr.length

    for(let i = 1; i < n; i++)
    {
        let key = arr[i];
        let j = i - 1;

        while(j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j]
            j--;
        }
        arr[j+1] = key;
    }
}

function bucketSort(arr)
{
    let n = arr.length;
    let minVal = Math.min(...arr);
    let maxVal = Math.max(...arr);
    let buckets = Array.from({length: n}, () => []);

    arr.forEach(num =>
    {
        let normalized = (num - minVal) / (maxVal - minVal)
        let bucketIndex = Math.floor(normalized * n);
        if(bucketIndex == n) { bucketIndex = n -1;}
        buckets[bucketIndex].push(num);
    });

    buckets.forEach(bucket => 
    {
        insertionSort(bucket);
    });

    let index = 0;
    buckets.forEach(bucket =>
    {
        bucket.forEach(num =>
        {
            arr[index] = num;
            index += 1;
        });
    });
    return arr;
}