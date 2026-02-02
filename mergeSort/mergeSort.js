unsortedList = [50, 11, 23, 3, 38, 39, 0, 7, 0, 15, 6, 9, 16, 25, 30, 41, 30, 29, 23, 39, 20, 18, 20, 20, 5, 13, 5, 9, 10, 6]

function mergeSort(unsortedList)
{
    if(unsortedList.length <= 1)
    {
        return unsortedList;
    }

    let mid = Math.floor(unsortedList.length / 2);
    let leftArray = unsortedList.slice(0, mid);
    let rightArray = unsortedList.slice(mid);

    leftArray= mergeSort(leftArray);
    rightArray = mergeSort(rightArray);

    return mergeSort_Helper(leftArray, rightArray);
}

function mergeSort_Helper(left, right)
{
    let result = []
    let i = 0;
    let j = 0;

    while(i < left.length && j < right.length)
    {
        if(left[i] < right[j])
        {
            result.push(left[i]);
            i++;
        }
        else
        {
            result.push(right[j]);
            j++;
        }
    }

    while(i < left.length)
    {
        result.push(left[i]);
        i++;
    }
    while(j < right.length)
    {
        result.push(right[j]);
        j++
    }

    return result;
}
