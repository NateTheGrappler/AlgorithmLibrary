let unsortedArray = [2, 234, 5, 23, 7, 1, 90]


function bogoSortCheck(unsortedArray)
{
    for(i = 0; i < unsortedArray.length-1; i++)
    {
        if(unsortedArray[i] > unsortedArray[i+1])
        {
            return false;
        }
    }
    return true;
}

function bogoSort(unsortedArray)
{
    while(!bogoSortCheck(unsortedArray))
    {
        for(let i = 0; i<unsortedArray.length; i++)
        {
            let j = Math.floor(Math.random() * unsortedArray.length);
            let temp = unsortedArray[i];
            unsortedArray[i] = unsortedArray[j];
            unsortedArray[j] = temp;
        }
    }
    return unsortedArray;
}