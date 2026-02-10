const minRUN = 32;

function calcMinRun(n)
{
    let r = 0
    while(n >= minRUN)
    {
        r |= (n & 1);
        n >>= 1;
    }
    return n + r;
}

function insertionSort(arr, left, right)
{
    for(let i = left +1; i <= right; i++)
    {
        let key = arr[i];
        let j = i - 1;
        while(j >= left && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j -= 1;
        }
        arr[j+1] = key;
    }
}

function merge(arr, l, m, r)
{
    const left = arr.slice(l, m+1);
    const right = arr.slice(m+1, r+1);

    let i = 0, j = 0, k = l;
    while(i < left.length && j < right.length)
    {
        if(left[i] <= right[j])
        {
            arr[k++] = left[i++];
        }
        else
        {
            arr[k++] = right[j++];
        }
    }
    while(i < left.length) arr[k++] = left[i++];
    while(j < right.length) arr[k++] = right[j++];
}

function findRun(arr, start, n)
{
    let end = start + 1;
    if(end == n) return end;

    if(arr[end] < arr[start])
    {
        while(end < n && arr[end] < arr[end -1]) end++;
        let sub = arr.slice(start, end).reverse();
        for(let i = start; i < end; i++) arr[i] = sub[i-start];
    }
    else
    {
        while(end < n && arr[end] >= arr[end - 1]) end++;
    }
    return end
}

function timSort(arr) {
    const n = arr.length;
    const minRun = calcMinRun(n);
    const runs = [];

    let i = 0;
    while (i < n) {
        let runEnd = findRun(arr, i, n);
        let runLen = runEnd - i;

        if (runLen < minRun) {
            let end = Math.min(i + minRun, n);
            insertionSort(arr, i, end - 1);
            runEnd = end;
        }
        runs.push([i, runEnd]);
        i = runEnd;

        while (runs.length > 1) {
            const [l1, r1] = runs[runs.length - 2];
            const [l2, r2] = runs[runs.length - 1];
            const len1 = r1 - l1, len2 = r2 - l2;

            if (len1 <= len2) {
                merge(arr, l1, r1 - 1, r2 - 1);
                runs.pop();
                runs[runs.length - 1] = [l1, r2];
            } else break;
        }
    }

    while (runs.length > 1) {
        const [l1, r1] = runs[runs.length - 2];
        const [l2, r2] = runs[runs.length - 1];
        merge(arr, l1, r1 - 1, r2 - 1);
        runs.pop();
        runs[runs.length - 1] = [l1, r2];
    }

    return arr;
}