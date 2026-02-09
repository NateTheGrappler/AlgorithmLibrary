

function countingSort(arr)
{
    let n = arr.length;
    let maxVal = Math.max(...arr)
    let countArray = new Array(maxVal + 1).fill(0);

    for(let value of arr)
    {
        countArray[value] += 1;
    }

    for(let i = 1; i <= maxVal; i++)
    {
        countArray[i] += countArray[i-1];
    }

    let answerArray = new Array(n)
    for(let i = n-1; i >= 0; i--)
    {
        answerArray[countArray[arr[i]] - 1] = arr[i];
        countArray[arr[i]] -= 1;
    }

    return answerArray;
}